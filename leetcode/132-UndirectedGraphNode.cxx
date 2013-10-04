/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode  Node;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (! node) return 0;
        unordered_map<Node *, Node *> m;
        queue<Node *> q;
        Node *tmp, *copy, *neib, *ret = new Node(node->label);
        m[node] = ret;
        q.push(node);
        while (! q.empty()) {
            tmp = q.front(); q.pop();
            copy = m[tmp];
            for (int i = 0; i < tmp->neighbors.size(); ++i) {
                neib = tmp->neighbors[i];
                if (m.find(neib) != m.end()) {
                    copy->neighbors.push_back(m[neib]);
                } else {
                    q.push(neib);
                    Node * x = new Node(neib->label);
                    copy->neighbors.push_back(x);
                    m[neib] = x;
                }
            }
        }
        return ret;
    }
};
