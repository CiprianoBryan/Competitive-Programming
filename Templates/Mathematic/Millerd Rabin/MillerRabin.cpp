/************************************/
ULong Mult( ULong a , ULong b , ULong mod ) {
	ULong sum = 0 ;
	for( ; b != 0 ; b >>= 1 ) {
		if( b&1 ) sum = ( sum + a )%mod ;
		a = ( a + a )%mod ;
	}
	return sum ;
}

ULong Pow( ULong b , ULong e , ULong mod ) {
	ULong prod = 1 ;
	for( ; e != 0 ; e >>= 1 ) {
		if( e&1 ) prod = Mult( prod , b , mod ) ;
		b = Mult( b , b , mod ) ;
	}
	return prod ;
}

/************************************/

bool MillerRabin( ULong p , int it ) { //srand( time( NULL ) ) ;
	if( p <= 2 ) return p == 2 ;
	if( !( p&1 ) ) return false ;
	ULong m = p - 1 ;
	for( ; m%2 == 0 ; m >>= 1 ) ;
	while( it -- ) {
		ULong a = rand()%( p - 1 ) + 1 ;
		ULong b = Pow( a , m , p ) ;
		if( b == p - 1 || b == 1 ) continue ;
		for( ULong m_ = m ; b != p - 1 && m_ != p - 1 ; m_ <<= 1 ) {
			b = Mult( b , b , p ) ;
		}
		if( b != p - 1 ) {
			return false ;
		}
	}
	return true ;
}

/************************************/
