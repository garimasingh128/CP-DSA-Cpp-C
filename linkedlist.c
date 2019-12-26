#include <stdio.h>
#include <stdlib.h>

struct node{
	int data; // data field
	struct node *next;
};

void display(struct node* head){
	struct node* current=head; // current node set to head
	
	printf("traversing the list...\n");
	while(current!=NULL){ //traverse until current node isn't NULL
		printf("%d ",current->data);
		current=current->next; // go to next node		
	}	
}

struct node* reverse_N(struct node* head,struct node* temp,int n){
	struct node *next=NULL,*cur=head,*prev=temp; //initialize the pointers
	int count=0;
	while(cur!=NULL && (count++)<n){//loop till the end of linked list
		next=cur->next;//next = cur->next to store the rest of the list;
		cur->next=prev;//change the direction of linked list
		prev=cur; //update prev
		cur=next; //update cur
	}
    
	head=prev; //update head
	return head; //return head
}

struct node* creatnode(int d){
	struct node* temp=malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	return temp;
}

int main(){
	printf("creating the linked list by inserting new nodes at the end\n");
	
	printf("enter 0 to stop building the list, else enter any integer\n");
	
	int k,count=0,x=1,n;
	
	struct node* curr,*temp;
	
	scanf("%d",&k);
	struct node* head=creatnode(k); //buliding list, first node
	scanf("%d",&k);
	temp=head;
	///////////////////inserting at the end//////////////////////
	while(k){
	curr=creatnode(k);
	temp->next=curr;//appending each node
	temp=temp->next;
	x++;
	scanf("%d",&k);
	}
	display(head); // displaying the list
	printf("\nInput N\n");
	while(1){
		scanf("%d",&n);
		if(n<x)
		break;
		printf("N greater than no of element, enter again\n");
	}
	
	printf("\nreversing upto first N elements...\n");
	
	//traversing to the node from which no reversing needed
	temp=head;
	while((count++)<n){
		temp=temp->next;
	}
	
	head=reverse_N(head,temp,n);
	display(head); // displaying the reversed( only first N terms) list
	
	return 0;
}

