/************************************/
int phi[ N ] ;

void sievePhi( int n ) {
	for( int num = 1 ; num <= n ; num ++ ) {
		phi[ num ] = num ;
	}
	for( int num = 2 ; num <= n ; num ++ ) {
		if( phi[ num ] != num ) continue ;
		for( int mult = num ; mult <= n ; mult += num ) {
			phi[ mult ] -= phi[ mult ]/num ;
		}
	}
}

/************************************/
