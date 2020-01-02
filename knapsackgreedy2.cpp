
#include <bits/stdc++.h> 
using namespace std; 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 
void bubbleSort(int r[], int wt[], int value[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	for (j = 0; j < n-i-1; j++) 
		if (r[j] < r[j+1]) 
		{
		
			
			swap(&r[j], &r[j+1]); swap(&wt[j], &wt[j+1]); swap(&value[j], &value[j+1]);  
			
			
		}
} 

void maximum(int r[], int wt[], int value[], int n)
{
	int n1=n;
	double vn=0.0;
	double p=0.0;
	for(int i=0;i<3;i++)
	{
	if(n1>=wt[i])	
	{
		n1=n1-wt[i];
		vn=vn+value[i];
	}
	else
	{
		p=r[i]*n1;
		vn=vn+p;
		break;
	}
	}
	cout<<"maximum value"<<vn;
}

int main() 
{ 
	int wt[3] = {10,20,30}; 
	int value[3] ={60,100,120};
	int n=50;
	int r[3];
	for(int i=0;i<3;i++)
	{
		r[i]=value[i]/wt[i];
	}
	bubbleSort(r,wt, value, 3); 
	for(int i=0;i<3;i++)
	{
		cout<<r[i]<<"\t"<<wt[i]<<"\n";
	}
	maximum(r,wt,value,n);

	return 0; 
} 

