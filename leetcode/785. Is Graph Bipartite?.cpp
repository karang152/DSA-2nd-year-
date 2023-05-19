//https://leetcode.com/problems/is-graph-bipartite/submissions/953440127/





class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colour(n,-1);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(colour[i]==-1){
                colour[i]=0;
                q.push(i);
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(int neighbor : graph[temp]){
                        if(colour[neighbor]==colour[temp]) return false;
                        else if(colour[neighbor]==-1){
                            colour[neighbor]=!colour[temp];
                            q.push(neighbor);
                        }

                    }
                }
            }

        }
        return true;
        
    }
};
