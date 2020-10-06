%{
#include<stdio.h>
#include<math.h>
int p=0, result=0;
int on=0;
%}
NUMBER [0-7]+

%%
{NUMBER} { on= atoi(yytext);
           while(on)
	   {
	   result += (on%10 * pow(8,p++) );
	   on /= 10;
	   }
           printf(" Decimal equivaent = %d\n", result); result = 0; p = 0;
	  }
%%
int yywrap(){
return 1;
}

int main(){
printf("Enter no ");
yylex();
return 0;
}