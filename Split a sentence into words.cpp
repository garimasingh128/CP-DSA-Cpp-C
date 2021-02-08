// C++ program to words in a sentence. 
#include <bits/stdc++.h> 
using namespace std; 

void removeDupWord(char str[]) 
{ 
	// Returns first token 
	char *token = strtok(str, " "); 

	// Keep printing tokens while one of the 
	// delimiters present in str[]. 
	while (token != NULL) 
	{ 
		printf("%s\n", token); 
		token = strtok(NULL, " "); 
	} 
} 

// Driver function 
int main() 
{ 
	char str[] = "Geeks for Geeks"; 
	removeDupWord(str); 
	return 0; 
}
