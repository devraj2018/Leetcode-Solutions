int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int e=edges.size();
	    vector<int>dis(n,INT_MAX);
	    dis[0]=0;
	    for(int i=0;i<n-1;i++)
	    { 
	        for(int i=0;i<e;i++)
	        {
	            int u=edges[i][0];
	            int v=edges[i][1];
	            int weight=edges[i][2];
	             if(dis[u]!=INT_MAX && dis[u]+weight<dis[v])
	              dis[v]=dis[u]+weight;
	        }
	        
	    }
	    for(int i=0;i<e;i++)
	        {
	            int u=edges[i][0];
	            int v=edges[i][1];
	            int weight=edges[i][2];
	             if(dis[u]!=INT_MAX && dis[u]+weight<dis[v])
	             return 1;
	        }
	        return 0;
	}