/* fastTranspose, textbook p.78 */
#include <stdio.h>
#define MAX_COL 20

typedef struct{
	int col;
	int row;
	int value;
} term;


void fastTranspose( term a[], term b[] ){

	int rowTerms [MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;

	if ( numTerms>0 ){

		/* At first, the value of all elements of rowTerms is zero */
		for ( i=0; i<numCols; i++ ){
			rowTerms[i] = 0;
			printf("rowTerms[%d] = %d\n", i, rowTerms[i]);
		}

		/* How many numbers of elements in each column of original matrix,
		 * then you can get how many numbers of elements in each row of transpose
		 * matrix */
		/* Now, you know how many elements in each transpose matrix, this is
		 * accmulated by a[i].col */
		for ( i=1; i<=numTerms; i++){
			rowTerms[a[i].col]++;
			printf("rowTerms[%d] = %d\n", a[i].col, rowTerms[a[i].col]);
		}

		/* starting postition is one */
		startingPos[0] = 1;

		/* numCols = a[0].col, the maximum column of the original matrix */
		for ( i=1; i<numCols; i++ ){

		/* calculate the position of the first row of transpose matrix, from
		 * the infomation of the first column of original matrix */

		/* Now, we know the startingPos of each row of transpose matrix */
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];
			printf("startingPos[%d] = %d\n", i, startingPos[i]);
		}

		for ( i=1; i<=numTerms; i++ ){
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}
int main(){

	int i;
	term a[9];
	term b[9];

	/* CAUTION: the nonzero element can NOT set at the boundary of the matrix,
	 * like a[i].row = a[0].row or a[i].col = a[0].col */


	/* the length of row */
	a[0].row = 6;
	/* the length of col */
	a[0].col = 6;
	/* how many elements of value in the matrix is NOT zero */
	a[0].value = 8;

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
	a[6].row = 1;
	a[6].col = 3;
	a[6].value = 15;
	a[7].row = 4;
	a[7].col = 3;
	a[7].value = 16;
	a[8].row = 2;
	a[8].col = 5;
	a[8].value = 17;


	for ( i=0; i<9; i++ ){
	printf("a[%d].row=%d\ta[%d].col=%d\ta[%d].value=%d", i, a[i].row, i, a[i].col, i, a[i].value);
	printf("\n");
	}

	fastTranspose ( a, b );
	printf("---------------\n");

	for ( i=0; i<9; i++ ){
	printf("b[%d].row=%d\tb[%d].col=%d\tb[%d].value=%d", i, b[i].row, i, b[i].col, i, b[i].value);
	printf("\n");
	}

	return 0;
}
