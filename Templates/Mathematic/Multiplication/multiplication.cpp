/************************************/
long long Mult( long long a , long long b ) {
	long long sum = 0 ;
	for( ; b != 0 ; b >>= 1 ) {
		if( b&1 ) sum += a ;
		a += a ;
	}
	return sum ;
}

/************************************/
