/************************************/
long long phi( long long num ) {
	long long ans = num ;
	for( int i = 0 ; e2( Pth[ i ] ) <= num ; i ++ ) {
		if( num%Pth[ i ] != 0 ) continue ;
		int div = Pth[ i ] ;
		for( ; num%div == 0 ; num /= div ) ;
		ans -= ans/div ;
	}
	if( num != 1 ) {
		ans -= ans/num ;
	}
	return ans ;
}

/************************************/
