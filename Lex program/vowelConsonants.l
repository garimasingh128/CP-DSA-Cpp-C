%{
#include<stdio.h>
int vowel=0;
int consonant=0;
%}
%%
[aeiouAEIOU] {vowel++;}
[a-zA-Z] {consonant++;}
\n    {return 0;}
%%
int yywrap()
{
return 0;
}
main(){

yylex();
printf("\nvowel=%d consonants=%d",vowel,consonant);
}