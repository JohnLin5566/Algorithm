/* Polynomials structure practice, textbook p.69 */
#include <stdio.h>
#define MAX_TERMS 100

typedef struct{
	float coef;
	int expon;
} poly;

poly terms[MAX_TERMS];
int avail = 0;

int main(){

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


	printf("avail is %d\n", avail);

}
