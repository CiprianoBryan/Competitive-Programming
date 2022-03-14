/************************************/
void gcdExt( long long a , long long &x , long long b , long long &y , long long &g ) {
	if( b == 0 ) {
		g = a , x = 1 , y = 0 ;
		return ;
	}
	gcdExt( b , y , a%b , x , g ) ;
	y = y - ( a/b )*x ;
}

/************************************/
