/* 
   Usage:
     ./notes add "Buy groceries"
     ./notes list
     ./notes search groceries
     ./notes delete 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB_FILE "notes.txt"
#define LINE_BUF 1024

/* Helper: get current timestamp as string */
static void current_timestamp(char *buf, size_t n) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(buf, n, "%Y-%m-%d %H:%M:%S", tm);
}

/* Helper: trim newline at end */
static void trim_newline(char *s) {
    size_t l = strlen(s);
    if (l > 0 && s[l-1] == '\n') s[l-1] = '\0';
}

/* Get next ID by scanning DB_FILE */
static long next_id() {
    FILE *f = fopen(DB_FILE, "r");
    if (!f) return 1; // file doesn't exist => first ID = 1
    char line[LINE_BUF];
    long maxid = 0;
    while (fgets(line, sizeof(line), f)) {
        char *p = strtok(line, "|");
        if (p) {
            long id = atol(p);
            if (id > maxid) maxid = id;
        }
    }
    fclose(f);
    return maxid + 1;
}

/* Add a new note */
static void cmd_add(const char *text) {
    if (!text || strlen(text) == 0) {
        printf("Cannot add empty note.\n");
        return;
    }
    long id = next_id();
    char ts[64];
    current_timestamp(ts, sizeof(ts));
    FILE *f = fopen(DB_FILE, "a");
    if (!f) {
        perror("Failed to open notes database");
        return;
    }
    fprintf(f, "%ld|%s|%s\n", id, ts, text);
    fclose(f);
    printf("Added note [%ld].\n", id);
}

/* List all notes */
static void cmd_list() {
    FILE *f = fopen(DB_FILE, "r");
    if (!f) {
        printf("No notes yet. Add one with: ./notes add \"Your note\"\n");
        return;
    }
    char line[LINE_BUF];
    printf("ID  | Timestamp           | Note\n");
    printf("----+---------------------+---------------------------------\n");
    while (fgets(line, sizeof(line), f)) {
        trim_newline(line);
        char *id = strtok(line, "|");
        char *ts = strtok(NULL, "|");
        char *note = strtok(NULL, "|");
        if (id && ts && note) {
            printf("%-4s| %-19s | %s\n", id, ts, note);
        }
    }
    fclose(f);
}

/* Search notes by substring (case-insensitive) */
static void cmd_search(const char *query) {
    if (!query || strlen(query) == 0) {
        printf("Provide a search term: ./notes search term\n");
        return;
    }
    FILE *f = fopen(DB_FILE, "r");
    if (!f) {
        printf("No notes to search.\n");
        return;
    }
    char line[LINE_BUF];
    int found = 0;
    char qlow[LINE_BUF];
    strncpy(qlow, query, sizeof(qlow)-1); qlow[sizeof(qlow)-1]=0;
    for (char *p=qlow; *p; ++p) *p = tolower(*p);

    while (fgets(line, sizeof(line), f)) {
        char copy[LINE_BUF];
        strncpy(copy, line, sizeof(copy)-1); copy[sizeof(copy)-1]=0;
        char *id = strtok(copy, "|");
        char *ts = strtok(NULL, "|");
        char *note = strtok(NULL, "|");
        if (id && ts && note) {
            char lownote[LINE_BUF];
            strncpy(lownote, note, sizeof(lownote)-1); lownote[sizeof(lownote)-1]=0;
            for (char *p=lownote; *p; ++p) *p = tolower(*p);
            if (strstr(lownote, qlow)) {
                printf("[%s] %s - %s", id, ts, note); // note already has newline from file
                found++;
            }
        }
    }
    fclose(f);
    if (!found) printf("No notes matched '%s'.\n", query);
}

/* Delete note by ID */
static void cmd_delete(const char *idstr) {
    if (!idstr) {
        printf("Provide an ID to delete: ./notes delete 3\n");
        return;
    }
    long target = atol(idstr);
    if (target <= 0) {
        printf("Invalid ID.\n");
        return;
    }
    FILE *f = fopen(DB_FILE, "r");
    if (!f) {
        printf("No notes to delete.\n");
        return;
    }
    FILE *tmp = fopen("notes.tmp", "w");
    if (!tmp) {
        perror("Failed to create temp file");
        fclose(f);
        return;
    }
    char line[LINE_BUF];
    int deleted = 0;
    while (fgets(line, sizeof(line), f)) {
        char copy[LINE_BUF];
        strncpy(copy, line, sizeof(copy)-1); copy[sizeof(copy)-1]=0;
        char *id = strtok(copy, "|");
        if (id) {
            long idnum = atol(id);
            if (idnum == target) {
                deleted = 1;
                continue; // skip writing this line
            }
        }
        fputs(line, tmp);
    }
    fclose(f);
    fclose(tmp);
    if (deleted) {
        remove(DB_FILE);
        rename("notes.tmp", DB_FILE);
        printf("Deleted note [%ld].\n", target);
    } else {
        remove("notes.tmp");
        printf("Note with ID %ld not found.\n", target);
    }
}

/* Print usage */
static void usage(const char *prog) {
    printf("Simple Note Manager\n");
    printf("Usage:\n");
    printf("  %s add \"note text\"    - add a note\n", prog);
    printf("  %s list                 - list all notes\n", prog);
    printf("  %s search term          - search notes\n", prog);
    printf("  %s delete ID            - delete note by ID\n", prog);
}

/* Main */
int main(int argc, char **argv) {
    if (argc < 2) {
        usage(argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf("Please provide note text.\n");
            return 1;
        }
        /* join all remaining args as the note text */
        char buf[LINE_BUF] = {0};
        for (int i = 2; i < argc; ++i) {
            strcat(buf, argv[i]);
            if (i+1 < argc) strcat(buf, " ");
        }
        cmd_add(buf);
    } else if (strcmp(argv[1], "list") == 0) {
        cmd_list();
    } else if (strcmp(argv[1], "search") == 0) {
        if (argc < 3) { printf("Provide a search term.\n"); return 1; }
        cmd_search(argv[2]);
    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) { printf("Provide an ID to delete.\n"); return 1; }
        cmd_delete(argv[2]);
    } else {
        usage(argv[0]);
        return 1;
    }
    return 0;
}
