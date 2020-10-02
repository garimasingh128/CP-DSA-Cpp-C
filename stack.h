#include <stdio.h>
#include <string.h>
#define size 50

int top = -1;
int topM = -1;

int push(char n, char st[]) {
    if (top + 1 < size) {
        st[++top] = n;
        return 1;
    }
    return 0;
}

// Push multiple to stack
int pushMultiple(char s[], char stk[][50]) {
    if (topM + 1 < size) {
        strcpy(stk[++topM], s);
        return 1;
    }
    return 0;
}

// Pop from stack
char pop(char st[]) {
    char temp = '\0';
    if (top >= 0) {
        temp = st[top];
        st[top--] = '\0';
    }
    return temp;
}

// Pop multiple from stack
int popMultiple(char st[][50], char ret[]) {
    if (topM >= 0) {
        strcpy(ret, st[topM]);
        st[topM--][0] = '\0';
        return 1;
    }

    return 0;
}