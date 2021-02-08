// Header Includes
#include <stdio.h>
#include <string.h>
#include "stack.h"

// In-stack priority 
int isp(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }

    return 0;
}

// In-coming priority
int icp(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 4;
    }

    return 0;
}

// Infix to Postfix
void inToPost(char expression[], char convExpression[], char st[]) {
    int n = 0, m = 0;
    char c = '\0';

    while (expression[n] != '\0') {
        if (icp(expression[n])) {
            if (top != -1 && isp(st[top]) >= icp(expression[n])) {
                c = pop(st);
                push(expression[n], st);
                convExpression[m++] = c;
            } else {
                push(expression[n], st);
            }
        }

        else if (expression[n] == '(') {
            push(expression[n], st);
        }

        else if (expression[n] == ')') {
            while ((c = pop(st)) != '(') {
                convExpression[m++] = c;
            }
        }

        else {
            convExpression[m++] = expression[n];
        }

        n++;
    }

    while (top >= 0) {
        convExpression[m++] = pop(st);
    }

    convExpression[m] = '\0';
}

// Prefix to Postfix
void preToPost(char expression[], char stk[][50]) {
    char op1[50], op2[50];
    char ch[2];
    ch[1] = '\0';
    int n = strlen(expression) - 1;

    while (n >= 0) {
        if (icp(expression[n])) {
            ch[0] = expression[n];
            popMultiple(stk, op1);
            popMultiple(stk, op2);
            strcat(op1, op2);
            strcat(op1, ch);
            pushMultiple(op1, stk);
        }
        else {
            ch[0] = expression[n];
            pushMultiple(ch, stk);
        }

        n--;
    }
}

// Postfix to prefix
void postToPre(char expression[], char stk[][50]) {
    char op1[50], op2[50];
    char ch[3];
    ch[1] = '\0';
    int n = 0;

    while (expression[n] != '\0') {
        ch[0] = ch[1] = ch[2] = '\0';
        if (icp(expression[n])) {
            ch[0] = expression[n];
            popMultiple(stk, op2);
            popMultiple(stk, op1);
            strcat(ch, op1);
            strcat(ch, op2);
            pushMultiple(ch, stk);
        } else {
            ch[0] = expression[n];
            pushMultiple(ch, stk);
        }
        n++;
    }
}

// Beginning of main
int main() {
    char st[50];
    char stk[50][50];

    char expression[50];
    char convExpression[50];

    int choice = 1;

    do {
        printf("MENU\n1. Infix to Postfix\n2. Prefix to Postfix\n3. Postfix to Prefix\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an infix expression : ");
                scanf("%s", expression);
                inToPost(expression, convExpression, st);
                printf("The infix expression in postfix form is : %s\n", convExpression);
                break;

            case 2:
                printf("Enter a prefix expression : ");
                scanf("%s", expression);
                preToPost(expression, stk);
                popMultiple(stk, convExpression);
                printf("The prefix expression in postfix form is : %s\n", convExpression);
                break;

            case 3:
                printf("Enter an postfix expression : ");
                scanf("%s", expression);
                postToPre(expression, stk);
                popMultiple(stk, convExpression);
                printf("The postfix expression in prefix form is : %s\n", convExpression);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice);
    return 0;
} // End of main

/* OUTPUT
MENU
1. Infix to Postfix
2. Prefix to Postfix
3. Postfix to Prefix
0. Exit
Choice: 1
Enter an infix expression : a+b+c
The infix expression in postfix form is : ab+c+
MENU
1. Infix to Postfix
2. Prefix to Postfix
3. Postfix to Prefix
0. Exit
Choice: 3
Enter an postfix expression : ab+c+
The postfix expression in prefix form is : ++abc
MENU
1. Infix to Postfix
2. Prefix to Postfix
3. Postfix to Prefix
0. Exit
Choice: 2
Enter a prefix expression : ++abc
The prefix expression in postfix form is : ab+c+
MENU
1. Infix to Postfix
2. Prefix to Postfix
3. Postfix to Prefix
0. Exit
Choice: 0
*/