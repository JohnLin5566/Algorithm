/* Transposing a matrix */
#include<stdio.h>

typedef struct{
	int col;
	int row;
	int value;
} term;

void transpose( term a[], term b[] ){
	
	int n, i, j, currentb;

	/* creat a b matrix is according a matrix */
	n = a[0].value;		/* total number of elements */
	b[0].row = a[0].col;	/* rows numbers in b is cols numbers in a */
	b[0].col = a[0].row;	/* cols numbers in b is rows numbers in a */
	b[0].value = n;

	if ( n>0 ){		/* non zero matrix */

		currentb = 1;

		/* transpose by the columns in a */
		for ( i=0; i<a[0].col; i++ ){
			
			/* find elements from the current column */
			for ( j=1; j<=n; j++ ){
				
				/* element is in current col, add it to b */
				if ( a[j].col == i ){
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
		
	}

}

int main(){

	int i;
	term a[6];
	term b[6];

	/* CAUTION: the nonzero element can NOT set at the boundary of the matrix,
	 *  * like a[i].row = a[0].row or a[i].col = a[0].col */


	/* the length of row */
	a[0].row = 6;
	/* the length of col */
	a[0].col = 6;
	/* how many elements of value in the matrix is NOT zero */
	a[0].value = 5;

	a[1].row = 4;
	a[1].col = 2;
	a[1].value = 10;
	a[2].row = 2;
	a[2].col = 3;
	a[2].value = 11;
	a[3].row = 3;
	a[3].col = 4;
	a[3].value = 12;
	a[4].row = 3;
	a[4].col = 5;
	a[4].value = 13;
	a[5].row = 4;
	a[5].col = 1;
	a[5].value = 14;

	
	for ( i=0; i<6; i++ ){
	printf("a[%d].row=%d\ta[%d].col=%d\ta[%d].value=%d", i, a[i].row, i, a[i].col, i, a[i].value);
	printf("\n");
	}

	transpose ( a, b );
	printf("---------------\n");

	for ( i=0; i<6; i++ ){
	printf("b[%d].row=%d\tb[%d].col=%d\tb[%d].value=%d", i, b[i].row, i, b[i].col, i, b[i].value);
	printf("\n");
	}

	return 0;
}
