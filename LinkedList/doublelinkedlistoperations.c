#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *prev;
struct node *next;
};

void display(struct node *p,struct node *start){

printf("Elements of doubly linked list are:");
p=start;
while(1)
{
    printf("%d\t",p->data);
    p=p->next;
    if(p->next==NULL)
    {
        printf("%d\n",p->data);
        break;
    }
}
}

void deleteBefore(struct node *start,struct node *p,struct node *q,struct node *temp){
int key;
printf("Enter the element before which you want to delete\n");
scanf("%d",&key);
p=start;
q=p;
while(p->data!=key){
	temp=q;
	q=p;
	p=p->next;
}
if(p==start)
	printf("No element exist before %d\n",key);
else if(start==q){
start=p;
p->prev=NULL;
}
else{
p->prev=q->prev;
temp->next=p;}
}

void insertBefore(struct node *start,struct node *p,struct node *q,struct node *temp){
int key;
printf("Enter the element before which you want to insert\n");
scanf("%d",&key);
p=start;
while(p->data!=key){
	q=p;
	p=p->next;
}
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter data to be inserted:");
scanf("%d",&temp->data);

temp->prev=p->prev;
temp->next=p;
p->prev=temp;
q->next=temp;
}

void search(struct node *start,struct node *p){
int key;
int i=0;
printf("Enter the element to search for\n");
scanf("%d",&key);
p=start;
while(p->data!=key)
{
	p=p->next;
	i++;
}
printf("%d is at position number %d\n",key,++i);
}

void main(){
int i;
struct node *start=NULL;
struct node *p=NULL;
struct node *q=NULL;
struct node *temp=NULL;
int n;
printf("enter total no of elements");
scanf("%d",&n);
for(i=0;i<n;i++){
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter data : ");
scanf("%d",&temp->data);
if(start==NULL){
    start=temp;
    p=start;
    start->prev=NULL;
}
else{
    q=p;
    p=temp;
    q->next=temp;
    p->prev=q->next;
    p->next==NULL;

}
}

display(p,start);

deleteBefore(start,p,q,temp);

display(p,start);

insertBefore(start,p,q,temp);

display(p,start);

search(start,p);

}
