/************************************/
Pair E[ 2*MAXE ] ;
vector<int> edges[ MAXV ] ;
bool vis[ MAXV ] ;

int dfs( int from , int flow , int target ) {
	if( from == target ) return flow ;
	vis[ from ] = true ;
	for( int nroE : edges[ from ] ) {
		if( vis[ E[ nroE ].first ] || !E[ nroE ].second ) continue ;
		int currFlow = dfs( E[ nroE ].first , min( flow , E[ nroE ].second ) , target ) ;
		if( !currFlow ) continue ;
		E[ nroE ].second -= currFlow ;
		E[ nroE^1 ].second += currFlow ;
		return currFlow ;
	}
	return 0 ;
}

int maxFlow( int n , int s , int t ) {
	int flow = 0 ;
	while( true ) {
		for( int i = 0 ; i < n ; i ++ ) {
			vis[ i ] = false ;
		}
		int currFlow = dfs( s , INF , t ) ;
		if( !currFlow ) break ;
		flow += currFlow ;
	}
	return flow ;
}

/************************************/

int main() {
	int n , m , s , t ;
	cin >> n >> m >> s >> t ;
	int u , v , w ;
	int nroE = 0 ;
	while( m -- ) {
		scanf( "%d %d %d" , &u , &v , &w ) ;
		E[ nroE ] = { v , w } ; edges[ u ].push_back( nroE ++ ) ;
		E[ nroE ] = { u , 0 } ; edges[ v ].push_back( nroE ++ ) ;
	}
	cout << maxFlow( n , s , t ) ;

    return 0 ;
}

/***************************************************************/

/************************************/
int E ;

int last[ MAXV + 5 ] , vis[ MAXV + 5 ] ;
int to[ 2*MAXE + 5 ] , cap[ 2*MAXE + 5 ] , nxt[ 2*MAXE + 5 ] ;

void add_edge( int u , int v , int uv , int vu = 0 ) {
	to[ E ] = v ; cap[ E ] = uv ; nxt[ E ] = last[ u ]; last[ u ] = E ++ ;
	to[ E ] = u ; cap[ E ] = vu ; nxt[ E ] = last[ v ]; last[ v ] = E ++ ;
}

int dfs( int u , int f , int target ) {
	if( u == target ) return f ;
	if( vis[ u ] ) return 0 ;
	vis[ u ] = true ;
	for( int e = last[ u ] ; e != -1 ; e = nxt[ e ] ) {
		int v = to[ e ] ;
		if( cap[ e ] ) {
			int ret = dfs( v , min( f , cap[ e ] ) , target ) ;
			if( ret ) {
				cap[ e ] -= ret ;
				cap[ e^1 ] += ret ;
				return ret ;
			}
		}
	}
	return 0 ;
}

int maxFlow( int n , int s , int t ) {
	int flow = 0 ;
	while( true ) {
		for( int i = 0 ; i < n ; i ++ ) {
			vis[ i ] = false ;
		}
		int currFlow = dfs( s , INF , t ) ;
		if( !currFlow ) break ;
		flow += currFlow ;
	}
	return flow ;
}

/************************************/

int main() {
	int n , m ;
	int s , t ;
	cin >> n >> m ;
	cin >> s >> t ;
	int u , v , w ;
	int E = 0 ;
	while( m -- ) {
		scanf( "%d %d %d" , &u , &v , &w ) ;
		add_edge( u , v , w ) ;
	}
	cout << maxFlow( n , s , t ) ;

    return 0 ;
}