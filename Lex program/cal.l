%{ 
#include<stdio.h>
#include<math.h>
int op = 0,i; 
float a, b; 
%} 
  
dig [0-9]+|([0-9]*)"."([0-9]+) 
add "+"
sub "-"
mul "*"
div "/"
pow "^"
ln \n 
%% 
{dig} {digi();}  
{add} {op=1;} 
{sub} {op=2;} 
{mul} {op=3;} 
{div} {op=4;} 
{pow} {op=5;} 
{ln} {printf("\n The Answer :%f\n\n",a);} 
  
%% 
digi() 
{ 
 if(op==0) 
 a=atof(yytext);  
  
 else
 { 
 b=atof(yytext); 
  
 switch(op) 
 { 
   case 1:a=a+b; 
    break; 
  
   case 2:a=a-b; 
   break; 
   
   case 3:a=a*b; 
   break; 
   
   case 4:a=a/b; 
   break; 
   
   case 5:for(i=a;b>1;b--) 
   a=a*i; 
   break; 
  } 
 op=0; 
 } 
} 
  
int yywrap() 
 { 
  return 0; 
 } 

int main() 
{ 
 yylex(); 
 return 1;
} 
  
