%option noyywrap
%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int c,j;
%}

%%
[0-9]+ { c=atoi(yytext);
          if(c==0 || c==1)
	  {
	  printf(" %d is not a prime number\n",c);
	  }
	  else
	  {
	    for(j=2;j<=sqrt(c);j++)
	     {
	        if(c%j==0)
		 break;
	     }
            if(j>sqrt(c))
               printf(" %d is a prime number\n",c);
	    else
	        printf(" %d is not a prime number \n",c);
           }
	 }
%%
int main()
{
printf("Enter a number\n");
yylex();
return 0;
}
