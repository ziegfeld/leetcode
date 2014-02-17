//============================================================================
// Clone an undirected graph. Each node in the graph contains a label and a 
// list of its neighbors.
//
// Note:
// Nodes are labeled uniquely.
//
// We use # as a separator for each node, and , as a separator for node label 
// and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
// The graph has a total of three nodes, and therefore contains three parts 
// as separated by #.
//
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus 
// forming a self-cycle.
//
// Complexity:
// BFS or DFS, O(V+E) time, O(E) space
//============================================================================

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        return cloneGraph2(node);
    }

    UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visit;
        return dfs(node, visit);
    }

    UndirectedGraphNode * dfs(UndirectedGraphNode * cur, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> & visit) {
        if (visit.count(cur)) return visit[cur];
        auto copy = new UndirectedGraphNode(cur->label);
        visit[cur] = copy;
        for (auto next : cur->neighbors) copy->neighbors.push_back(dfs(next, visit));
        return copy;
    }

    UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visit;
        queue<UndirectedGraphNode*> qs;
        visit[node] = new UndirectedGraphNode(node->label);
        qs.push(node);
        while (!qs.empty()) {
            auto cur = qs.front();
            qs.pop();
            for (auto next : cur->neighbors) {
                if (visit.count(next)) {
                    visit[cur]->neighbors.push_back(visit[next]);
                }
                else {
                    visit[next] = new UndirectedGraphNode(next->label);
                    visit[cur]->neighbors.push_back(visit[next]);
                    qs.push(next);
                }
            }
        }
        return visit[node];
    }
};

string toString(UndirectedGraphNode* node) {
    unordered_set<UndirectedGraphNode*> vs;
    queue<UndirectedGraphNode*> qs;
    ostringstream os;
    qs.push(node);
    vs.insert(node);
    while (!qs.empty()) {
        node = qs.front(), qs.pop();
        os << node->label << " ";
        for (auto it : node->neighbors) if (!vs.count(it)) vs.insert(it), qs.push(it);
    }
    return os.str();
}

int main() {
    Solution sol;

    {
        vector<UndirectedGraphNode*> p0;
        for (int i = 0; i <= 2; i++) p0.push_back(new UndirectedGraphNode(i));
        p0[0]->neighbors.push_back(p0[1]);
        p0[0]->neighbors.push_back(p0[2]);
        p0[1]->neighbors.push_back(p0[0]);
        p0[1]->neighbors.push_back(p0[2]);
        p0[2]->neighbors.push_back(p0[0]);
        p0[2]->neighbors.push_back(p0[1]);
        p0[2]->neighbors.push_back(p0[2]);
        cout << toString(p0[0]) << endl;
        auto p1 = sol.cloneGraph(p0[0]);
        cout << toString(p1) << endl;
    }

    return 0;
}