/************************************/
int sigma( int num ) {
	int prod = 1 ;
	while( ddo[ num ] ) {
		int div = ddo[ num ] ;
		int exp = 0 ;
		while( num%div == 0 ) {
			num /= div ;
			exp ++ ;
		}
		prod *= exp + 1 ;
	}
	if( num != 1 ) {
		prod <<= 1 ;
	}
	return prod ;
}

/************************************/
