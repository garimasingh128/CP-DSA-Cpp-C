
//Algorithm to Clone a linked list
//Written by PeeyushKumar

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next, *rand;
};

void traverse(node *head)
{
    node *ptr = head;

    while (ptr->next != NULL)
    {
        cout << ptr->data << ", ";
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
}

node *clone(node *head)
{
    node *newhead, *ptr;
    newhead = new node;
    newhead->data = head->data;

    ptr = newhead;
    while (head->next != NULL)
    {
        head = head->next;
        ptr->next = new node;
        ptr = ptr->next;
        ptr->data = head->data;
    }
    return newhead;
}

node *clone_rand(node *head)
{
    node *newhead, *ptr, *newptr;

    ptr = head;

    while (ptr != NULL)
    {
        newptr = new node;
        newptr->data = ptr->data;
        newptr->next = ptr->next;
        ptr->next = newptr;

        ptr = newptr->next;
    }

    ptr = head;
    while (ptr != NULL)
    {
        ptr->next->rand = ptr->rand->next;
        ptr = ptr->next->next;
    }

    newhead = head->next;
    newptr = newhead;
    ptr = head;

    while (ptr != NULL)
    {
        ptr->next = newptr->next;
        ptr = ptr->next;
        if (ptr != NULL)
            newptr->next = ptr->next;
        newptr = newptr->next;
    }

    return newhead;
}

int main()
{
    node *head = new node;
    head->data = 1;

    node *ptr = new node;
    ptr->data = 2;
    head->next = ptr;

    node *newnode = new node;
    newnode->data = 3;
    ptr->next = newnode;
    ptr = ptr->next;

    newnode = new node;
    newnode->data = 4;
    ptr->next = newnode;
    ptr = ptr->next;

    ptr->rand = head;
    ptr = head;
    ptr->rand = ptr->next->next;
    ptr = ptr->next;
    ptr->rand = ptr->next->next;
    ptr->next->rand = ptr;

    traverse(head);

    node *x = clone_rand(head);
    traverse(x);

    return 0;
}
