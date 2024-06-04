class Solution {
public:
    bool check(vector<vector<int>>& graph,vector<int> &colors,int node){
        for(auto it:graph[node]){
            if(colors[it]==-1){
                colors[it]=!colors[node];
                if(!check(graph,colors,it)) return false;
            }
            if(colors[it]==colors[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colors[i] ==-1){
                colors[i]=0;
                if(!check(graph,colors,i)) return false;
            }
        }
        return true;
    }
};