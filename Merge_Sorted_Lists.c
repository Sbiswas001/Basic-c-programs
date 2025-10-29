#include <stdio.h>

typedef struct ListNode{
    int val;
    struct Node *next;
} node;

node * createNode(int data){
    node* new = (node*)malloc(sizeof(node));
    new->val = data;
    new->next = NULL;
    return new;
}

node* merge_Sorted_Lists(node * list1, node * list2){
    node* list3 = createNode(0);
    node* temp1 = list1; node* temp2 = list2; node* temp3 = list3;
    while (temp1 != NULL && temp2 != NULL){
        // both the list are not empty
        if (temp1->val < temp2->val){
            temp3->val = temp1->val;
            temp1 = temp1->next;
        }
        if (temp2->val < temp1->val){
            temp3->val = temp2->val;
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }
    if (temp1 == NULL && temp2 != NULL){
        // list1 is over before list2, append the rest of list2 to list3
        while(temp2 != NULL){
            temp3->val = temp2->val;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    }
    if (temp1 != NULL && temp2 == NULL){
        // list2 is over before list1, append the rest of list1 to list3
        while(temp1 != NULL){
            temp3->val = temp1->val;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
    }
    return list3;
}
