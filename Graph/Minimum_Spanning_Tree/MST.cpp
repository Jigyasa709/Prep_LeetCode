int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue < pair<int,int> , vector<pair<int,int>> ,greater <pair<int,int>> > pq;
        
        pq.push({0,0});
        
        vector <bool> vis(V,false);
        
        int totalCost =0;
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(!vis[node])
            {
                    totalCost += dist;
                    vis[node] = true;
                
                for(vector <int> v: adj[node])
                {
                    int nbr = v[0];
                    int weight = v[1];
                    
                    if(!vis[nbr])
                    {
                        pq.push({weight,nbr});
                    }
                }
            }
        }
        
        return totalCost;
    }
