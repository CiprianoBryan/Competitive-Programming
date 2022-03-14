typedef pair<int,int> Pair ;
typedef vector<Pair> vPair ;

/************************************/
struct orden {
	bool operator() ( Pair p1 , Pair p2 ) {
		return p1.second > p2.second ;
	}
};

vPair adj[ N ] ;
bool vis[ N ] ;

int prim( int node ) {
	priority_queue<Pair,vPair,orden> q ;
	q.push( { node , 0 } ) ;
	int ans = 0 ;
	while( !q.empty() ){
		Pair f = q.top() ;
		q.pop() ;
		int a = f.first ;
		int d = f.second ;
		if( vis[ a ] ) continue ;
		vis[ a ] = true ;
		ans += d ;
		for( Pair v : adj[ a ] ){
			int b = v.first ;
			if( !vis[ b ] )
				q.push( v ) ;
		}
	}
	return ans ;
}

/************************************/

int main() {
	int n , m ;
	cin >> n >> m ;
	int u , v , d ;
	while( m -- ) {
		scanf( "%d %d %d" , &u , &v , &d ) ;
		adj[ u ].push_back( { v , d } ) ;
		adj[ v ].push_back( { u , d } ) ;
	}
	cout << prim( 1 ) ;

	return 0 ;
}