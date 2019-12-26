#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *link;
};

void display(struct node *p,struct node *start){

printf("Elements of single linked list are:");
p=start;
while(1)
{
    printf("%d\t",p->data);
    p=p->link;
    if(p->link==NULL)
    {
        printf("%d\n",p->data);
        break;
    }
}
}

void deleteBefore(struct node *start,struct node *p,struct node *q,struct node *temp){
int key;
printf("Enter the element which you want to delete\n");
scanf("%d",&key);
p=start;
q=p;
while(p->data!=key){
	temp=q;
	q=p;
	p=p->link;
}
if(p==start)
{
	start=p->link;
	free(p);
}
else{
q->link=p->link;
free(p);
}
}

void insertBefore(struct node *start,struct node *p,struct node *q,struct node *temp){
int key;
printf("Enter the element before which you want to insert\n");
scanf("%d",&key);
p=start;
while(p->data!=key){
	q=p;
	p=p->link;
}
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter data to be inserted:");
scanf("%d",&temp->data);
q->link=temp;
temp->link=p;

}

void search(struct node *start,struct node *p){
int key;
int i=0;
printf("Enter the element to search for\n");
scanf("%d",&key);
p=start;
while(p->data!=key)
{
	p=p->link;
	i++;
}
printf("%d is at position number %d\n",key,++i);
}

void main(){
int i,n;
struct node *start=NULL;
struct node *p=NULL;
struct node *q=NULL;
struct node *temp=NULL;
printf("enter total no of elements");
scanf("%d",&n);
for(i=0;i<n;i++){
temp=(struct node *)malloc(sizeof(struct node));
printf("Enter data : ");
scanf("%d",&temp->data);
if(start==NULL){
    start=temp;
    p=start;
}
else{
    q=p;
    p=temp;
    q->link=temp;
    p->link=NULL;

}
}

display(p,start);

deleteBefore(start,p,q,temp);

display(p,start);

insertBefore(start,p,q,temp);

display(p,start);

search(start,p);

}
