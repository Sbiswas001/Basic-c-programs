#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    scanf("%[^\n]", password);

    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else if (ispunct(password[i]))
            hasSpecial = 1;
    }

    printf("\nPassword Analysis:\n");
    printf("Length: %d\n", length);
    printf("Uppercase: %s\n", hasUpper ? "Yes" : "No");
    printf("Lowercase: %s\n", hasLower ? "Yes" : "No");
    printf("Digit: %s\n", hasDigit ? "Yes" : "No");
    printf("Special Character: %s\n\n", hasSpecial ? "Yes" : "No");

    if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
        printf("✅ Password Strength: STRONG 💪\n");
    else if (length >= 6 && ((hasUpper && hasLower) || (hasDigit && hasSpecial)))
        printf("⚠️ Password Strength: MODERATE\n");
    else
        printf("❌ Password Strength: WEAK\n");

    return 0;
}
