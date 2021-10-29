
// -------   If we use Adjacency Matrix Our complexity would be 0(v^2) --Chae koi bhi Method use krlo -----------//
//The code finds the shortest distances from the source to all vertices.//
// If we are interested only in the shortest distance from the source to a single target, //
//we can break the for loop when the picked minimum distance vertex is equal to the target //
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool>processed(V,false);
        vector<int>dis(V,INT_MAX);
        dis[S]=0;
        vector<int>par(V,-1);        // Only to Print Path from Source to target//
        for(int i=0;i<V-1;i++)
        {
             int u,minn=INT_MAX;
             for(int j=0;j<V;j++)
             { if(!processed[j] && dis[j]!=INT_MAX && dis[j]<minn)
                 {  
                     minn=dis[j];
                     u=j;
                 }
                 
                 
             }
             processed[u]=true;
             for(auto neighbour:adj[u])
             { int v=neighbour[0];
               int d=neighbour[1];
                
              if(dis[u]+d<dis[v])
              {    parent[v]=u;            // To store Parent Path
                   dis[v]=d+dis[u];
              }
                
             }
            
        }
        return dis;
        
    }
    
    void printPath(vector<int> par,int target)    //Only  To Print Path
    {  if(par[target]==-1)
       return;
         printPath(par,par[target]);
         cout<<par[target]<<" ";


    }

//-------------------------------  Dijkstra Using [Set] Time com-O(nlogn)-------------------------------//
//-------------------------------               2                        -------------------------------//

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
      {
          vector<int>dis(V,INT_MAX);
          dis[S]=0;
          set<pair<int,int>>st;
          st.insert({0,S});
          while(!st.empty())        /* Looping till all shortest distance are finalized then setds will become empty    */
          {  auto it=*(st.begin());  // First element of set will be at minimum distance 
             
             int u=it.second;
             st.erase(it);           // We finalized this node<so we don't need to come back to this node
             
             for(auto neighbour:adj[u])          // Traversing its neighbour
              {   
                  int v=neighbour[0];
                  int d=neighbour[1];
                 
                   if(dis[u]+d<dis[v])  
                   { 
                       if(dis[v]!=INT_MAX)     //If it already present in set, We have to replace its distance with Updated distance
                          {
                              st.erase(st.find({dis[v],v}));
                          }
                       
                       dis[v]=d+dis[u];  
                       st.insert({dis[v],v});  //Here We insert updated distance
                      
                   }
                  
                 }
             
              
          }
          return dis;
          
      }


//-------------------------------  Dijkstra Using [Priority_queue] Time com-O(nlogn)-------------------------------//
//-------------------------------                          2                        -------------------------------//

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
      {
          vector<int>dis(V,INT_MAX);
          dis[S]=0;
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
          vector<bool>processed(V,false);
          pq.push({0,S});
          while(!pq.empty())
          {  
              int u=pq.top().second;
              pq.pop();
              processed[u]=true;
             
             for(auto neighbour:adj[u])
              {   
                  int v=neighbour[0];
                  int d=neighbour[1];
                 
                   if(processed[v]==false && dis[u]+d<dis[v])
                   { 
                       dis[v]=d+dis[u];
                       pq.push({dis[v],v});
                      
                   }
                  
                 }
             
          }
          return dis;
          
      }