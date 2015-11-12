/* Recursive C implementation of Binary Search .
 * Using random number to creat a array and selectionSort the array. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 30
void swap( int *xp, int *yp){
	int temp = *xp; *xp = *yp; *yp=temp;
}
void printArray( int arr[], int size){
	int i;
	for ( i=0; i<size; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int binarySearch( int arr[], int l, int r, int x){
	if ( r>=1 ){
		int mid = l + (r-l)/2;
		if ( arr[mid]==x ) return mid;
		if ( arr[mid]>x ) return binarySearch( arr, l, mid-1, x );
		return binarySearch( arr, mid+1, r, x );
	}
	return -1;
}
int selectionSort( int arr[], int n){

	int i, j, min, temp;
	for ( i=0; i<n-1; i++ ){
		min=i;
		for( j=i+1; j<n; j++){
			if ( arr[j] < arr[min])
				min = j;
		}
		swap( &arr[i], &arr[min] );
	}
}

int main(){

	int i, n;
	int list[MAX_SIZE];
	/* key_num is the number we want to find, and result is that number position */
	int key_num, result;

	/* random seed setting */
	srand( time( NULL ) );

	printf("Enter the number of numbers to generate (from 2 to %d) :", MAX_SIZE);
	scanf("%d", &n);

	if ( n<1 || n>MAX_SIZE ){
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}

	/* randomly generate numbers from 0 to 999, and print that array */
	printf("\nThe original array : \n");
	for (i=0; i<n; i++){
		list[i] = rand() % 100;
		printf("%d  ", list[i]);
	}

	/* set the random number of the original array to the key_num */
	i = rand() % n;
	key_num = list[i];

	/* selectionSort there number arriay */
	printf("\n\nselectionSort:\n");
	selectionSort( list, n);
	printArray(list, n);

	result = binarySearch( list, 0, n-1, key_num );

	printf("\nThe result is %d\n", result);
	return 0;
}
