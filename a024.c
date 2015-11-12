/* compare function, textbook p.12 */
#include<stdio.h>

int compare ( int x, int y) {
	if ( x<y ) return -1;
	else if ( x==y ) return 0;
	else return 1;
}

int main(){

	int a=4, b=6;

	printf("%d\n", compare(a, b));

	return 0;
}
