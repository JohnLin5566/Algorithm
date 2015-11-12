/* Polynomials structure practice, textbook p.69 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100 

typedef struct{
	float coef;
	int expon;
} poly;

poly terms[MAX_TERMS];
int avail = 0;

/* COMPARE */
int COMPARE ( int x, int y ){
	if ( x<y ) return -1;
	else if ( x==y ) return 0;
		else return 1;
}

/* add a new term to the polynomial */
void attach ( float coefficient, int exponent ){
	if ( avail >= MAX_TERMS ){
		fprintf( stderr, "Too many terms in the polynomial\n");
		exit( EXIT_FAILURE );
	}
	terms[avail++].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd ( int startA, int finishA, int startB, int finishB, int *startD, int *finishD ){

	float coefficient;
	*startD = avail;

	while ( startA <= finishA && startB <= finishB ){
		switch ( COMPARE( terms[startA].expon, terms[startB].expon ) ){
			
			/* a expon < b expon */
			case -1:
			attach ( terms[startB].coef, terms[startB].expon);
			startB++;
			break;

			/* equal exponents */
			case 0:
			coefficient = terms[startA].coef + terms[startB].coef;

			if ( coefficient ){
				attach ( coefficient, terms[startA].expon );
			}
			startA++;
			startB++;
			break;

			/* a expon > b expon */
			case 1:
			attach ( terms[startA].coef, terms[startA].expon );
			startA++;
		}
	}

	/* add in remaining terms of A(x) */
	for ( ; startA <= finishA; startA++ )
		attach ( terms[startA].coef, terms[startA].expon );
	/* add in remaining terms of B(x) */
	for ( ; startB <= finishB; startB++ )
		attach ( terms[startB].coef, terms[startB].expon );

	*finishD = avail-1;

}

int main(){

	int i;

	terms[0].coef = 2;
	terms[0].expon = 1000 ;
	avail++;
	terms[1].coef = 1;
	terms[1].expon = 0;
	avail++;

	terms[2].coef = 1;
	terms[2].expon = 4;
	avail++;
	terms[3].coef = 10;
	terms[3].expon = 3;
	avail++;
	terms[4].coef = 3;
	terms[4].expon = 2;
	avail++;
	terms[5].coef = 1;
	terms[5].expon = 0;
	avail++;

	padd(

	for ( i=0; i<avail; i++){
	
	printf("terms[%d].coef = %f, terms[%d].expon = %d\n",i ,terms[i].coef, i, terms[i].expon);
	}

}
