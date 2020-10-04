%{ 
#include<stdio.h> 
%} 


%% 

int|char|bool|float|void|for|do|while|if|else|return|void {printf("Keyword");}
[a-z]([a-z]|[0-9])* {printf("Identifier");}
.* {printf("Invalid");}

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

