/* find all the permutation of a given string */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap ( char *x, char *y){ 
	char temp = *x; 
	*x=*y; 
	*y=temp;
}

void permute ( char* list, int i, int n){
	int j;
	if ( i==n )
		printf("%s\n", list);
	else{
		for ( j=i; j<=n; j++){
			swap( (list+i), (list+j) );
			permute( list, i+1, n );
			swap( (list+i), (list+j) );
		}
	}
}

int main(){
	char str[80];
	int len=0;
	int i;

	puts("Enter a string: \n");
	gets(str);
	printf("\n\n");

	//calculate the length of the string
	for ( i=0; str[i] != '\0'; i++){
		len++;
	}

	// start from 0-th element
	permute( str, 0, len-1);
	getchar();
	return 0;
}
