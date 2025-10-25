#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void enqueue(){
    int n;
    printf("Enter element to enqueue:");
    scanf("%d",&n);
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        if(head==NULL){
            printf("Overflow\n");
            return;
        }
        head->data=n;
        head->next=NULL;
        return;
    }
    struct node* q=(struct node*)malloc(sizeof(struct node));
    if(q==NULL){
            printf("Overflow\n");
            return;
        }
    q->data=n;
    q->next=NULL;
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}

void dequeue(){
    if(head==NULL){
        printf("Underflow\n");
        return;
    }
    struct node* p=head;
    head=head->next;
    printf("dequeued element :%d\n",p->data);
    free(p);
}

void display(){
    if(head==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* p=head;
    printf("Queue:");
    while(p->next!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("%d ",p->data);
    printf("\n");
}
int main()
{
    int choice;
    while(1){
        printf("Instructions:\n");
        printf("1 to enqueue\n2 to dequeue\n3 to exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        if(choice==3){
            printf("Your session has ended.");
          return 0;
        }
        switch(choice){
            case 1:enqueue();
            display();
            break;
            case 2:dequeue();
            display();
            break;
            default: printf("Invalid input, try again!\n");
        }
    }
  return 0;
}
