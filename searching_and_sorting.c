#include <stdio.h>

struct Student {
    char name[20];
    int roll;
    char div;    
};

void display_pass(struct Student s[], unsigned int n, int comp) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", s[i].roll);
    }
    printf("No. of comparisons: %d", comp);
    printf("\n");
}

void bubble(struct Student s[], unsigned int n) {
    for (int i = 0; i < n-1; i++) {
        int swap_count = 0;
        int comp = 0;
        for (int j = 0; j < n-i-1; j++) {
            comp++;
            if (s[j].roll > s[j+1].roll) {
                struct Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
                swap_count++;
            }
        }
        display_pass(s, n, comp);  
        if (swap_count == 0)
            break;  
    }
}

void selection(struct Student s[], unsigned int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        int comp = 0;
        for(int j = i; j < n; j++) {
            comp++;
            if(s[j].roll < s[min].roll)
                min = j;
        }
        struct Student temp = s[i];
        s[i] = s[min];
        s[min] = temp;
        display_pass(s, n, comp);
    }
}

void insertion(struct Student s[], unsigned int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = s[i];
        int j = i - 1, comp = 0;
        while (j >= 0 && key.roll < s[j].roll) {
            s[j+1] = s[j];
            j--;
            comp++;
        }
        s[j+1] = key;
        display_pass(s, n, comp);
    }
}

struct Student* binary_rec(struct Student s[], unsigned int n, int search, int low, int high) {
    if(low >  high) 
        return NULL;
    int middle = (low + high)/2;
    if(s[middle].roll == search)
        return &s[middle];
    else if(s[middle].roll > search)
        return binary_rec(s, n, search, low, middle-1);
    else
        return binary_rec(s, n, search, middle+1, high);
}

struct Student* binary_non_rec(struct Student s[], unsigned int n, int search) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low + high) /2;
        if(s[mid].roll == search)
            return &s[mid];
        else if(s[mid].roll < search)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NULL;
}

struct Student* linear(struct Student s[], unsigned int n, int search) {
    for(int i = 0; i < n; i++) {
        if(s[i].roll == search)
            return &s[i];
    }
    return NULL;
}

void accept(struct Student* s) {
    printf("Enter Student Roll: ");
    scanf("%d", &s->roll);
    printf("Enter Student Name: ");
    scanf("%s", s->name);
    printf("Enter student Division: ");
    scanf("%s", &s->div);
}

void display(struct Student* s) {
    printf("%d\t\t%s\t\t%c\n", s->roll, s->name, s->div);
}

int main() {
    int n, c;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter Student %d details\n", i+1);
        accept(&s[i]);
    } 
    while (1)
    {
        printf("\nMENU\n1. Display list\n2. Linear Search\n3. Binary Search\n4. Bubble sort\n5. Selection sort\n6. Insertion Sort\nEnter your choice: ");
        scanf("%d", &c);
        switch(c) {
            case 1: {
                for (int i = 0; i < n; i++) {
                    display(&s[i]);
                }
                break;
            }
            case 2: {
                int k;
                printf("Enter id of student to be searched: ");
                scanf("%d", &k);
                struct Student* stud = linear(s, n, k);
                if (stud == NULL) 
                    printf("Student was not found\n");
                else 
                    display(stud);
                break;
            }
            case 3: {
                //bubble(s, n);
                int k;
                printf("Enter id of student to be searched: ");
                scanf("%d", &k);
                struct Student* stud = binary_non_rec(s, n, k);
                if (stud == NULL) 
                    printf("Student was not found\n");
                else 
                    display(stud);
                break;
            }
            case 4: {
                bubble(s, n);
                break;
            }
            case 5: {
                selection(s, n);
                break;
            }
            case 6: {
                insertion(s, n);
                break;
            }
        }
        
    }
     
}