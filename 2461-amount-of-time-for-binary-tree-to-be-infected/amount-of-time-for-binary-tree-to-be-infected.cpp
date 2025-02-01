class Solution {
public:
    int node = 0;
    int getNumberOfNodes(TreeNode* root,unordered_map<int,int> &nodes){
        if(root==nullptr){
            return 0;
        }
        nodes[root->val]=node;
        node++;
        int leftNodes = getNumberOfNodes(root->left,nodes);
        int rightNodes = getNumberOfNodes(root->right,nodes);
        return leftNodes+rightNodes+1;
    }
    void makegraph(vector<vector<int>> &adj,TreeNode* root,unordered_map<int,int> &nodes){
        if(root==nullptr){
            return;
        }
        if(root->left!=nullptr){
            adj[nodes[root->val]].push_back(nodes[root->left->val]);
            adj[nodes[root->left->val]].push_back(nodes[root->val]); 
            makegraph(adj, root->left, nodes);
        }
        if(root->right!=nullptr){
            adj[nodes[root->val]].push_back(nodes[root->right->val]);
            adj[nodes[root->right->val]].push_back(nodes[root->val]);
            makegraph(adj, root->right, nodes);
        }
    }
    int dfs(vector<vector<int>> &adj,vector<int> &vis,int node){
        vis[node]=1;
        int dist = 0;
        for(auto it:adj[node]){
            if(!vis[it]){
                dist = max(dist,dfs(adj,vis,it));
            }
        }
        return dist+1;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,int> nodes;
        int n = getNumberOfNodes(root,nodes);
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        makegraph(adj,root,nodes);
        return dfs(adj,vis,nodes[start])-1;
    }
};