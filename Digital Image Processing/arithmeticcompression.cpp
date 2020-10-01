#include<bits/stdc++.h>
using namespace std;
struct lowhigh
{
int low;
int high;
};

lowhigh probabilty(char arr[], int n,  int cf[],char word, int pro[], int x)
{
struct lowhigh lh;
/**for(int i=0;i<n;i++)
{
if(arr[i]==word[i])
{
lh.high=lh.high+lh.low+pro[i];
}
else
{
lh.low=lh.low+pro[i];
}
}*/
lh.high=cf[x+1]; lh.low=cf[x];

for(int i=0;i<n;i++)
{
pro[i]=pro[i]*pro[x];
}
for(int i=0;i<n+1;i++)
{
cf[i]=cf[i]+pro[i];
}
return lh;
}
void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n, char c[])
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           char temp;
           temp=arr[j+1];
           arr[j+1]=arr[j];
           arr[j]=temp;
           swap(&c[j], &c[j+1]);
           
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

int main()
{
int n;
cout<<"enter n";
cin>>n;
char arr[n];
char word[n];
int pro[n];
for(int i=0;i<n;i++)
{
    cout<<"enter letter and its probabailty";
cin>>arr[i]>>pro[i];
}
bubbleSort(pro,n,arr);
int cf[n];

for(int i=0;i<n+1;i++)
{
cf[i]=cf[i]+pro[i];
}
cout<<"enter word";
cin>>word;

struct lowhigh lh;
for(int i=0;i<strlen(word);i++)
{
	int x=i;
lh=probabilty(arr,n,cf,word[i],pro,x);
}
double mean=(lh.low+lh.high)/2;
cout<<mean;
return 0;
}
