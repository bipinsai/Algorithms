create_set ( )
{
	for ( int  i = 0;i<n;i++)
	{
		p[i] = i ;
		rank[i] = 0 ;
	}
}
int find_set (int u )
{
 	int x= p[u];
 	if( x != u )
 		x= find_set (x);
 	return x;
}

void merge(int u , int v)
{
	int s1= find_set ( u );
	int s2 = find_set(v);
	if( rank[s1] > rank[s] )
		p[s2] = s1;
	else
		p[s1] = s2;
	if( rank[s1] == rank[s2] )
		rank[s2]++;
}
int kruskal ()
{
	create_set();
	int res = 0;
	for(int i= 0 ;i< v.size(); i++)
	{
		int cost = v[i].first ;
		int v1 =v[i].second.first ;
		int v2 = v[i].second.second;
		if( find_set( v2 ) == find_set(v1))
		{
			res+=v[i].first ;
			merge_set(v1,v2)
		}
	}
}
