%{ 
#include<stdio.h> 
int lc=0, sc=0, tc=0;
%} 
  
SHOW [$]

%% 
\n    {lc++;} 
[' '] {sc++;}
\t    {tc++;}
{SHOW} { printf("lines=%d spaces=%d tabs=%d", lc, sc, tc);
        lc=0;
        tc=0;
        sc=0;
       }
. {}
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

