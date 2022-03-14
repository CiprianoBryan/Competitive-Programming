/************************************/
int sigma( int num ) {
	int prod = 1 ;
	for( int i = 0 ; e2( Pth[ i ] ) <= num ; i ++ ) {
		int div = Pth[ i ] ;
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
