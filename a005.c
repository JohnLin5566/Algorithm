/* C program for implmentation of selection sort */
#include <stdio.h>
void swap(int *xp, int *yp){
	int temp = *xp;	*xp = *yp; *yp = temp;
}
void selectionSort(int arr[], int n ){
	int i, j, min;

	/* one by one move boundary of unsorted subarray */
	for ( i=0; i< n-1; i++)	{
		/* find the min element in the subarray */
		min=i;
		for (j=i+1; j<n; j++){
			if ( arr[j] < arr[min]){
				min=j;
			}
		}
		/* swap the found min element with the i-th element */
		swap(&arr[min], &arr[i]);
	}
}
void printArray(int arr[], int size){
	int i;
	for (i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(){
	int arr[]={64, 25, 12, 22, 32, 512, 234, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
