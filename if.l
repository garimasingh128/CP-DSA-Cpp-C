%option noyywrap
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch[10];
int count=0;
%}

%%
[a-zA-Z]+ { if(strcmp(yytext,ch)==0)
             count++;
	  }
. ;
%%
int main()
{
printf("Enter a word to be count in a file\n");
scanf("%s",ch);
extern FILE *yyin,*yyout;
yyin=fopen("ABC.txt","r");
yylex();

printf(" frequency of given word is %d\n",count);
return 0;
}
