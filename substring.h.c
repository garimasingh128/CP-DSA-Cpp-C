#include <stdio.h>
#include <stdbool.h>

int length(char *str) {
    int i = 0;
    while((*str) != '\0') { 
        i++;
        str++;
    }
    return i;
}

void copy(char *str, char *str2) {
    while ((*str) != '\0')
    {
        *str2 = *str;
        str++;
        str2++;
    }
    *str2 = '\0';
}

void concat(char *str, char *str2) {
    while ((*str) != '\0')
    {
        str++;
    }
    while ((*str2) != '\0')
    {
        *str = *str2;
        str++;
        str2++;
    }
    *str = '\0';
}

void reverse(char str[]) {
    char str2[20];
    copy(str, str2);
    int len = length(str);
    for (int i = len-1; i >= 0; i--)
    {
        str[len-i-1] = str2[i];
    }
}

bool compare(char str[], char str2[]) {
    int len = length(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}

bool palindrome(char str[]) {
    char str2[20];
    copy(str, str2);
    reverse(str);
    return compare(str, str2);
}

void sub(char str[], char str2[], int start, int end) {
    int len = length(str);
    int i = start;
    if (start < len && end < len && start <= end)
    {
        for (; i < end + 1; i++)
        {
            str2[i - start] = str[i];
        }
    }
    str2[i - start] = '\0';
}

int substring(char str[], char str2[]) {
    int occ = 0;
    int len = length(str);
    int len2 = length(str2);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == str2[0])
        {
            char check[len2];
            sub(str, check, i, i + len2 -1);
            bool cmp = compare(str2, check);
            if (cmp == 1)
            {
                occ++;
            }
        }
    }
    return occ;
}

void delete(char str[]) {
	str[0] = '\0';
}

int main() {
    char str[20], str2[20];
    while (true)
    {
        printf("MENU:\n1.Length\n2.Copy\n3.Concat\n4.Reverse\n5.Compare\n6.Palindrome\n7.Substring\n");
        int n;
        scanf("%d", &n);
        switch (n)
        {
            case 1: {
                printf("Enter a string: ");
                scanf("%s", str);
                int len = length(str);
                printf("Length of string is %d\n", len);
                break;
            }
            case 2: {
                printf("Enter a string: ");
                scanf("%s", str);
                printf("Entered string is %s\n", str);
                copy(str, str2);
                printf("Copied string is %s\n", str2);
                break;
            }
            case 3: {
                printf("Enter a string: ");
                scanf("%s", str);
                printf("Enter another string: ");
                scanf("%s", str2);
                concat(str, str2);
                printf("Concatenated string is %s\n", str);
                break;
            }
            case 4: {
                printf("Enter a string: ");
                scanf("%s", str);
                reverse(str);
                printf("Reversed string is %s\n", str);
                break;
            }
            case 5: {
                printf("Enter a string: ");
                scanf("%s", str);
                printf("Enter another string: ");
                scanf("%s", str2);
                bool cmp = compare(str, str2);
                printf(cmp == 1 ? "True\n" : "False\n");
                break;
            }
            case 6: {
                printf("Enter a string: ");
                scanf("%s", str);
                bool cmp = palindrome(str);
                printf(cmp == 1 ? "Palindrome\n" : "Not a palindrome\n");
                break;
            }
            case 7: {
                printf("Enter a string: ");
                scanf("%s", str);
                printf("Enter another string: ");
                scanf("%s", str2);
                int occ = substring(str, str2);
                printf("Substring was found %d times in string\n", occ);
                break;
            }
        }
    }
    
}
