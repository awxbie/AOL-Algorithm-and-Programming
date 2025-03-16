#include<stdio.h>
#include<string.h>

int main() {
	char string[101]; 
	char reverse[101];
	int j = 0; 
	
	scanf ("%[^\n]", string); 
	int length = strlen(string); 
	for (int i = length-1; i >= 0; i--) {
		reverse[j] = string[i]; 
		j++; 
	}
	for (int j = 0; j < length; j++) {
		if (reverse[j] >= 'A' && reverse[j] <= 'Z') reverse[j] += 32; 
		else if (reverse[j] >= 'a' && reverse[j] <= 'z') reverse[j] -= 32; 
	}
	reverse[j] = '\0'; 
	
	printf ("%s\n", reverse); 
	
	return 0; 
}
