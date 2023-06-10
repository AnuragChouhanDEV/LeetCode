// https://leetcode.com/problems/clone-graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
void dfs(Node* node, Node* copy, vector<Node*> &visited) {
    visited[node->val] = copy;
    for (auto n:node->neighbors) {
            if(visited[n->val] == NULL) {
                Node *newnode = new Node(n->val);
                copy->neighbors.push_back(newnode);
                dfs(n, newnode, visited);
            } else
                copy->neighbors.push_back(visited[n->val]);
        }
}
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        Node *copy = new Node(node->val);
        vector<Node*> visited(101, NULL);
        visited[node->val] = copy;
        for (auto n:node->neighbors) {
            if(visited[n->val] == NULL) {
                Node *newnode = new Node(n->val);
                copy->neighbors.push_back(newnode);
                dfs(n, newnode, visited);
            } else
                copy->neighbors.push_back(visited[n->val]);
        }
        return copy;
    }
};