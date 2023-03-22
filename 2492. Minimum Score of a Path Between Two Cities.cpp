class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        queue<pair<int,int>>q;
        q.push({1,INT_MAX});
        vector<vector<int>>adj[n+1];
        for(int i=0;i<roads.size();i++)
        {
             int u=roads[i][0];
             int v=roads[i][1];
             int adjwt=roads[i][2];
             adj[u].push_back({v,adjwt});
             adj[v].push_back({u,adjwt});
        }
        int ans=INT_MAX;
        vector<int>vis(n+1,0);
        vis[1]=1;
        while(!q.empty())
        {
            auto ele=q.front();q.pop();
            int node=ele.first;
            for(auto it:adj[node])
            {
                int node=it[0];
                int wt=it[1];
                ans=min(ans,wt);//updating answer for with everyedge that is connected to curNode
                if(!vis[node])
                {
                    q.push({node,wt});
                    vis[node]=1;
                }
            }
        }
        return ans;
    }
};
