char* reverseString(char* input1) 
{ 
	int length = strlen(input1);  
	int i; 
	for (i = length - 1; i >= 0; i--) { 
		if (input1[i] == ' ') { 
	 
			input1[i] = '\0'; 

	
			printf("%s ", &(input1[i]) + 1); 
		} 
	} 

 
	printf("%s", input1); 
} 

int main() 
{ 
	char input1[] = "MY NAME IS KHAN"; 
	reverseString(input1); 
	return 0; 
}
