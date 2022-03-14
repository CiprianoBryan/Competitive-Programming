/************************************/
vector<int> adj[ N ] ;
bool vis[ N ] ;

void bfs( int node ) {
	queue<int> q ;
	q.push( node ) ;
	while( !q.empty() ) {
		int a = q.front() ;
		q.pop() ;
		vis[ a ] = true ;
		for( int b : adj[ a ] ) {
			if( vis[ b ] ) continue ;
			q.push( b ) ;
		}
	}
}

/************************************/
