/************************************/
int phi( int num ) {
	int ans = num ;
	while( ddo[ num ] ) {
		int div = ddo[ num ] ;
		for( ; num%div == 0 ; num /= div ) ;
		ans -= ans/div ;
	}
	if( num != 1 ) {
		ans -= ans/num ;
	}
	return ans ;
}

/************************************/
