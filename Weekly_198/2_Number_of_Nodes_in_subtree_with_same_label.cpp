class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj,int i,vector<int>& vis,vector<int>& ans,string& labels){
        vis[i] = 1;
        vector<int>colors(26);
        colors[labels[i]-'a'] = 1;
        for(int x: adj[i]){
            if(!vis[x]){
                vector<int> t = dfs(adj,x,vis,ans,labels);
                for(int i=0;i<26;i++) colors[i] += t[i];
            }
        }
        ans[i] = colors[labels[i] - 'a'];
        return colors;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n,vector<int>());
        for(auto v: edges){
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }
        vector<int>ans(n,1);
        vector<int>visited(n);
        dfs(adj,0,visited,ans,labels);
        return ans;
    }
};