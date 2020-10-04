%option noyywrap
%{
#include<stdio.h>
#include<string.h>
char ch[200];
%}

%%
['\n'] { fprintf(yyout,"%s\n",ch);}
[.]+ { strcpy(ch,yytext);}
%%
int main()
{
extern FILE *yyin,*yyout;
yyin=fopen("ABC.txt","r");

yyout=fopen("output.txt","w");
yylex();
printf("File content is copied in another file\n");
return 0;
}
