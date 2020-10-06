#include <bits/stdc++.h>
using namespace std;

/* List Structure */
typedef struct Node
{
	int data;
	struct Node *link;
}node;

node *head=NULL;		// Head node to keep track of list

/* Driver Functions */
void Push(int data);
int Top();
void Pop();

/* Main Method */
int main()
{
	Push(0);
	Push(1);
	Push(2);
	Push(3);
	
	cout<<Top()<<" ";
	Pop();			// Delete 3 from list
	Pop();			// Delete 2 from list
	cout<<Top()<<" ";
	Push(4);		// Add 4 at the end of list
	cout<<Top()<<" ";
	return 0;
}

/* Insert Element */
void Push(int data)
{
	// Declaring node
	node *temp = (node*)calloc(1,sizeof(node));
	temp->data = data;
	temp->link = head;
	
	head = temp;
	return;
}

/* Delete Element */
void Pop()
{
    if(!head)
        return;
	node* temp = head;
	head = head->link;
	
	free(temp);
}

/* Get the first stack element> */
int Top()
{
    if(head)
        return head->data;
    return -1;
}
