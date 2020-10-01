#include <stdio.h>
#include <stdlib.h>
#include <limits.h>     // For INT_MIN

#define SIZE 100

// Create a stack with capacity of 100 elements
int stack[SIZE];

// Initially stack is empty 
int top = -1;


/* Function declaration to perform push and pop on stack */
void push(int element);
int  pop();


int main()
{
    int choice, data;

    while(1)
    {
        /* Menu */
        printf("------------------------------------\n");
        printf("    STACK IMPLEMENTATION PROGRAM    \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1: 
                printf("Enter data to push into stack: ");
                scanf("%d", &data);
                
                // Push element to stack
                push(data);
                break;

            case 2: 
                data = pop();

                // If stack is not empty
                if (data != INT_MIN)
                    printf("Data => %d\n", data);
                break;

            case 3: 
                printf("Stack size: %d\n", top + 1);
                break;

            case 4: 
                printf("Exiting from app.\n");
                exit(0);
                break;

            default: 
                printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }


    return 0;
}



/**
 * Functiont to push a new element in stack.
 */
void push(int element)
{
    // Check stack overflow
    if (top >= SIZE)
    {
        printf("Stack Overflow, can't add more element element to stack.\n");
        return;
    }

    // Increase element count in stack
    top++;

    // Push element in stack
    stack[top] = element;

    printf("Data pushed to stack.\n");
}


/**
 * Function to pop element from top of stack.
 */
int pop()
{
    // Check stack underflow
    if (top < 0)
    {
        printf("Stack is empty.\n");

        // Throw empty stack error/exception
        // Since C does not have concept of exception
        // Hence return minimum integer value as error value
        // Later in code check if return value is INT_MIN, then
        // stack is empty
        return INT_MIN;
    }


    // Return stack top and decrease element count in stack
    return stack[top--];
}
