vector <int> dijkstra(int V, vector<vector<int>> adj[], int Source) 
    {
     vector<int> dis(V,INT_MAX);   // Distance array for maintainnig distance
        vector<int> vis(V,0);    // Visited array to know which vertex is visited
     
        
        set<pair<int,int>>s;    // set dsa to store pair of distance and vertex and to extracrt min distance vertex
        
        dis[Source] = 0;
        
        s.insert({0,Source});
        
        while(s.size()>0){
            auto node = *(s.begin());
            int d = node.first;
            int v = node.second;
            
            if(vis[v]==0){
                continue;
            }else{
                vis[v]=1;
            for(auto child:adj[v]){
                int distance = child[1];
                int vertex = child[0];
                
                if(dis[v] + distance < dis[vertex]){      // Main condition
                    dis[vertex] = dis[v] + distance;
                    s.insert({dis[vertex],vertex});
                }
            }
            }
            
            
        }
        return dis;
    }
