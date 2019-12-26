#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}
void preorder(struct node* root){
    if(root == NULL) return;
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}
struct node* createNode(value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* insertLeft(struct node *root, int value) {
    root->left = createNode(value);
    return root->left;
} 
struct node* insertRight(struct node *root, int value){
    root->right = createNode(value);
    return root->right;
}
int main(){
    struct node* root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);
    
    insertLeft(root->left, 5);
    insertRight(root->left, 6);
    
    printf("Inorder traversal \n");
    inorder(root);
    printf("\nPreorder traversal \n");
    preorder(root);
    printf("\nPostorder traversal \n");
    postorder(root);
}
