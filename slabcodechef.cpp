#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
	    long int sal;
	    cin>>sal;
	    if(sal<=250000)
	    {
	        sal=sal;
	    }
	    else if(sal>250000 && sal<=500000)
	    {
	        sal=sal-(sal-250000)*0.05;  
	    }
	     else if(sal>500001 && sal<=750000)
	    {
	       sal=sal-(sal-250000)*0.05-(sal-500000)*0.1; 
	    }
	     else if(sal>750000 && sal<=1000000)
	    {
	        sal=sal-(sal-250000)*0.05-(sal-500000)*0.1-(sal-750000)*0.15; 
	    }
	     else if(sal>1000000 && sal<=1250000)
	    {
	        sal=sal-(sal-250000)*0.05-(sal-500000)*0.1-(sal-750000)*0.15-(sal-1000000)*0.2;
	    }
	     else if(sal>1250000 && sal<=1500000)
	    {
	         sal=sal-(sal-250000)*0.05-(sal-500000)*0.1-(sal-750000)*0.15-(sal-1000000)*0.2-(sal-1250000)*0.25;
	    }
	    else
	    {
	        sal=sal-(sal-250000)*0.05-(sal-500000)*0.1-(sal-750000)*0.15-(sal-1000000)*0.2-(sal-1250000)*0.25-(sal-1500000)*0.3;
	    }
	    cout<<sal;
	}
	return 0;
}

