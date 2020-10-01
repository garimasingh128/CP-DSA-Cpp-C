#include <stdio.h>
#include <stdlib.h>

/* List Structure */
typedef struct Node
{
	int data;
	struct Node *link;
}node;

node *head=NULL;		// Head node to keep track of list

/* Driver Functions */
void EnQueque(int data);
int DeQueue();
void print(node *p);

/* Main Method */
int main()
{
	EnQueque(0);
	EnQueque(1);
	EnQueque(2);
	EnQueque(3);
	DeQueue();			// Delete 0 from list
	DeQueue();			// Delete 1 from list
	
	EnQueque(4);		// Add 4 at the end of list
	
	print(head);		// Print element of queue
	
	return 0;
}

/* Insert Element */
void EnQueque(int data)
{
	// Declaring node
	node *temp = (node*)calloc(1,sizeof(node));
	temp->data = data;
	temp->link = NULL;
	
	// If head is NULL or first node
	if(!head)
	{
		head = temp;
		return;
	}
	node *traverse=head;
	
	// Traverse list upto end
	while(traverse->link)
		traverse = traverse->link;
	
	traverse->link = temp;
}

/* Delete Element */
int DeQueue()
{
	node* temp = head;
	head = head->link;
	
	int data = temp->data;
	
	free(temp);
	
	return data;
}

/* Print queue */
void print(node *p)
{
	printf(" %d",p->data);
	if(!p->link)
		return;
	print(p->link);
}
