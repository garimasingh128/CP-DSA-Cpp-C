#include<iostream>
struct Node
{
	int info;
	Node *next;
}*start,*newptr,*save,*ptr;
Node *Create_New_Node(int n)
{
	ptr=new Node;
	ptr->info=n;
	ptr->next=NULL;
	return ptr;
}
void Insert_Beg(Node* newptr)
{
	if(start==NULL)
	{
		start=newptr;
	}
	else
	{
		save=start;
		start=newptr;
		newptr->next=save;
	}
}
void Display(Node* np)
{
	while(np!=NULL)
	{
		std::cout<<np->info<<"->";
		np=np->next;
	}
	std::cout<<"!!!\n";
}
int main()
{
	
	start=NULL;
	int info;
	char ch='y';
	while(ch=='Y'||ch=='y')
	{
		system("cls");
		std::cout<<"\n enter info for new node";
		std::cin>>info;
		std::cout<<"\n creating new node. press enter to continue";
		system("pause");
		newptr=Create_New_Node(info);
		if(newptr!=NULL)
		{
			std::cout<<"\n new node created successfully. press enter to continue";
			system("pause");
		}
		else
		{
			std::cout<<"\n cannot create new node. aborting.";
			system("pause");
			exit(1);
		}
		std::cout<<"\n now inserting new node at beginning";
		std::cout<<"\n press enter to continue";
		system("pause");
		Insert_Beg(newptr);
		std::cout<<"\n now the list is:";
		Display(start);
		std::cout<<"\n press Y to enter more nodes, N to exit";
		std::cin>>ch;
	}

	return 0;
}

