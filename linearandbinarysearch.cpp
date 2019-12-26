#include <stdio.h>

#include <stdlib.h>

int main()
{

/* Declare variables - array_of_number,search_key,i,j,low,high*/

    int array[100],search_key,i,j,n,low,high,location,choice;

    void linear_search(int search_key,int array[100],int n);

    void binary_search(int search_key,int array[100],int n);


/* read the elements of array */

    printf("ENTER THE SIZE OF THE ARRAY:");

    scanf("%d",&n);

    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");

    for(i=1;i<=n;i++)
    {

        scanf("%d",&array[i]);

    }

/* Get the Search Key element for Linear Search */

    printf("ENTER THE SEARCH KEY:");

    scanf("%d",&search_key);

/* Choice of Search Algorithm */

    printf("___________________\n");

    printf("1.LINEAR SEARCH\n");

    printf("2.BINARY SEARCH\n");

    printf("___________________\n");

    printf("ENTER YOUR CHOICE:");

    scanf("%d",&choice);

    switch(choice)
    {

    case 1:

        linear_search(search_key,array,n);

        break;

    case 2:

        binary_search(search_key,array,n);

        break;

    default:

        exit(0);

}

    return 0;

}

/* LINEAR SEARCH */

    void linear_search(int search_key,int array[100],int n)
    {

/*Declare Variable */

        int i,location;

        for(i=1;i<=n;i++)
        {

            if(search_key == array[i])
            {

                location = i;

    printf("______________________________________\n");

    printf("The location of Search Key = %d is %d\n",search_key,location);

    printf("______________________________________\n");

        }

    }

}

/* Binary Search to find Search Key */

void binary_search(int search_key,int array[100],int n)
{

    int mid,i,low,high;

    low = 1;

    high = n;

    mid = (low + high)/2;

    i=1;

    while(search_key != array[mid])
    {

        if(search_key <= array[mid])
        {

            low = 1;

            high = mid+1;

            mid = (low+high)/2;

        }
        else
        {

            low = mid+1;

            high = n;

            mid = (low+high)/2;

        }

}

    printf("__________________________________\n");

    printf("location=%d\t",mid);

    printf("Search_Key=%d Found!\n",search_key);

    printf("__________________________________\n");

}
