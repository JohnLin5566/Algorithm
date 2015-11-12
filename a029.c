/* Matrix multiplication function, textbook p.33 */
void mult ( int a[][], int b[][], int c[][] ){

	int i, j, k;
	for ( i=0; i<MAX_SIZE; i++ ){
		for ( j=0; j<MAX_SIZE; j++ ){
			
			c[i][j] = 0;
			for ( k=0; k<MAX_SIZE; k++ ){

 				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
