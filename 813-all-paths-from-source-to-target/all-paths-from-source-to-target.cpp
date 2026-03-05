class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int> &curr, vector<vector<int>> &ans){

        curr.push_back(node);

        // if we reached to the (n-1)th node, curr path is the valid path
        if(node==graph.size()-1){
            ans.push_back(curr);
        }

        // exploring through adjacent nodes
        for(auto edge: graph[node]){
            dfs(edge,graph,curr,ans);
        }
        // we need to backtrack by poping out the last element we pushed in curr, so that other paths can be explored
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // we need a current to store the current path 
        // and a ans 2d vector , in which we will store all the paths
        vector<int> curr;
        vector<vector<int>> ans;

        // by dfs lets explore all the paths 1 by 1 , and if at a moment we reached to the (n-1)th node , we will put that path in the ans
        dfs(0,graph,curr,ans);
        return ans;
    }
};