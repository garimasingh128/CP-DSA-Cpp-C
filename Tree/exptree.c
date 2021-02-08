#include<STDIO.H>
#include<CONIO.H>
#include<MALLOC.H>
typedef struct tree
{
char data;
struct tree *left;
struct tree *right;
}*pos;
pos stack[30];
int top=-1;
pos newnode(char b)
{
pos temp;
temp=(struct tree*)malloc(sizeof(struct tree));
temp->data=b;
temp->left=NULL;
temp->right=NULL;
return(temp);
}
void push(pos temp)
{
stack[++top]=temp;
}
pos pop()
{
pos p;
p=stack[top--];
return(p);
}
void inorder(pos t)
{
if(t!=NULL)
{
inorder(t->left);
printf(“%c”,t->data);
inorder(t->right);
}
}
void preorder(pos t)
{
if(t!=NULL)
{
printf(“%c”,t->data);
preorder(t->left);
inorder(t->right);
}
}
void postorder(pos t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
printf(“%s”,t->data);
}
}
void main()
{
char a[20];pos temp,t;int j,i;
clrscr();
printf(“\nEnter the postfix expression”);
gets(a);
for(i=0;a[i]!=NULL;i++)
{
if(a[i]==’*’ || a[i]==’/’ || a[i]==’+’ || a[i]==’-')
{
temp=newnode(a[i]);
temp->right=pop();
temp->left=pop();
push(temp);
}
else
{
temp=newnode(a[i]);
push(temp);
}
}
inorder(temp);
printf(“\n”);
preorder(temp);
printf(“\n”);
postorder(temp);
getch();
}
