/* C implementation of Heap Sort */
#include<stdio.h>
#include<stdlib.h>

/* A heap has current size and array of elements */
struct MaxHeap{
	int size;
	int *array;
};

/* A utility function to swap */
void swap(int *a, int *b) { int t = *a; *a = *b; *b=t;}

/* The main function to heapify a Max Heap. The function assumes that everything
 * under given root is already heapified. */
void maxHeapify(struct MaxHeap * maxHeap, int idx){

	int largest = idx;
	int left = (idx << 1) + 1;	//left=2*idx+1
	int right = (idx+1) << 1;	//right=2*idx+2

	/* if left child of root exists and is greater than root */
	if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
		largest = left ;
	/* if right child of root exists and is greater than root */
	if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
		largest = right ;

	/* change root, if needed */
	if (largest != idx){
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

/* A utility function to create a max heap of given capacity */
struct MaxHeap* createAndBuildHeap(int *array, int size){

	int i;
	struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));

	/* initialize size of heap */
	maxHeap->size = size;
	/* Assign address of first element of array */
	maxHeap->array = array;

	/* start from bottommost and rightmost internal node and heapify all internal
	 * nodes in bottom up way */
	for ( i=(maxHeap->size/2); i >= 0; --i){
		maxHeapify(maxHeap, i);
	}
	return maxHeap;
}

/* The main function to sort an array of given size */
void heapSort(int *array, int size){

	/* Build a heap from the input data */
	struct MaxHeap *maxHeap = createAndBuildHeap(array, size);

}

































