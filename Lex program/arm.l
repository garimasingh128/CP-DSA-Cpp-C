%{ 
#include<stdio.h>
#include<math.h>
int l=0, i=0, temp=0, x=0, temp1=0;
%} 




NUMBER [0-9]+ 

%% 
{NUMBER} { i = atoi(yytext);
           temp = i;
	   temp1 = i;
           while(i>0)
	   { l++;
	    i /= 10;
	   }
	   
            while(temp1>0)
	    { x += round(pow(temp1%10,l));
	    temp1 /= 10;
	    }
              
          
	    if(x==temp)
	    { printf("Yes");
	    }
	    else
	    { printf("No");
	    }

	  l=0, i=0, temp=0, x=0, temp1=0;
	  }

%% 

int yywrap()
{
    return 0;
}

int main() 
{ 

    yylex(); 
    
    return 1;
    
}
