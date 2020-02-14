#include<bits/stdc++.h>
using namespace std;
struct lowhigh
{
int low;
int high;
};

lowhigh probabilty(char arr[], int n,  int cf[],char word, int pro[])
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
lh.high=cf[word+1]; lh.low=cf[word];

for(int i=0;i<n;i++)
{
pro[i]=pro[i]*pro[word];
}
for(int i=0;i<n+1;i++)
{
cf[i]=cf[i]+pro[i];
}
return lh;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(char arr[], int n, int c[])
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
           swap(&arr[j], &arr[j+1]);
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
string word;
int pro[n];
for(int i=0;i<n;i++)
{
    cout<<"enter letter and its probabailty";
cin>>arr[i]>>pro[i];}
bubbleSort(pro,n,arr);
int cf[n];

for(int i=0;i<n+1;i++)
{
cf[i]=cf[i]+pro[i];
}
cout<<"enter word";
getline(word);

struct lowhigh lh;
for(int i=0;i<word.length()-1;i++)
{
lh=probabilty(arr,n,cf,word[i],pro);
}
double mean=(lh.low+lh.high)/2;
cout<<mean;
return 0;
}
