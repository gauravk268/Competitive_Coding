/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *fun(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &vis){
    if(node==NULL)  return NULL;
    
    if(vis[node->label]==NULL){
        UndirectedGraphNode *tmp=new UndirectedGraphNode(node->label);
        vis[node->label]=tmp;
        for(auto &x:node->neighbors){
            tmp->neighbors.push_back(fun(x, vis));
        }
    }
    
    return vis[node->label];
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL)  return NULL;
    unordered_map<int, UndirectedGraphNode *> vis;
    return fun(node, vis);
}