/* Insertion Sort */

#include<stdio.h>
int print ( int tmp[]){
	int i=0;
	for ( i=1; i<11; i++){
		printf("%5d", tmp[i]);
	}
	printf("\n");
}


void insort ( int s[], int n ){
	int i, j;
	for ( i=2; i<=n; i++ ){
		s[0] = s[i];
		j=i-1;
		while ( s[0] < s[j] ){
			s[j+1]=s[j];
			j--;
			print(s);
		}
		s[j+1]=s[0];
			print(s);
	}
}
main(){
	int a[11], i;
	printf("plz input number:\n");

	for ( i=1; i<=10; i++ )	{
		scanf("%d", &a[i]);
	}
	/* original order */
	printf("the original order : \n");
	for ( i=1; i<11; i++){
		printf("%5d", a[i]);
	}
	printf("\nstart the sorting\n");

	/* sort */
	insort(a, 10);
	
	/* after sorting order */
	printf("\nthe sorted numbers: \n");
	for ( i=1; i<11; i++){
		printf("%5d", a[i]);
	}

	printf("\n");

	return 0;
}
