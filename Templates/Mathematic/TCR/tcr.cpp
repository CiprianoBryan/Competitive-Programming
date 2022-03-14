/************************************/

int x[ N ] ;
int m[ N ] ;

int chineseRemainder( int n ) {
	long long M = 1 ;
	for( int i = 0 ; i < n ; i ++ ) {
		x[ i ] %= m[ i ] ;
		M *= m[ i ] ;
	}
	int ans = 0 ;
	for( int i = 0 ; i < n ; i ++ ) {
		long long M_ = M/m[ i ] ;
		ans = add( ans , mult( x[ i ] , mult( inverseMod( M_ , m[ i ] ) , M_ , M ) , M ) , M ) ;
	}
	return ans ;
}

/************************************/
