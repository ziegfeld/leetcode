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
        return clone1(node);
    }

    // BFS
    UndirectedGraphNode *clone1(UndirectedGraphNode *graph) {
        if (!graph) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> table;
        queue<UndirectedGraphNode *> queue;
        queue.push(graph);

        UndirectedGraphNode *res = new UndirectedGraphNode(graph->label);
        table[graph] = res;

        while (!queue.empty()) {
            UndirectedGraphNode *curNode = queue.front();
            queue.pop();
            int n = curNode->neighbors.size();
            for (int i = 0; i < n; i++) {
                UndirectedGraphNode* neighbor = curNode->neighbors[i];
                if (table.find(neighbor) == table.end()) {
                    // no copy exists
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                    (table[curNode]->neighbors).push_back(newNode);
                    table[neighbor] = newNode;
                    queue.push(neighbor);
                } else {
                    // a copy already exists
                    UndirectedGraphNode* copy = table[neighbor];
                    (table[curNode]->neighbors).push_back(copy);
                }
            }
        }
        return res;
    }

    // DFS
    UndirectedGraphNode *clone2(UndirectedGraphNode *graph) {
        if (graph == NULL) return NULL;
        UndirectedGraphNode *res = new UndirectedGraphNode(graph->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> table;
        table[graph] = res;
        cloneHelper2(graph, table);
        return res;
    }

    void cloneHelper2(UndirectedGraphNode *curNode, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &table) {
        for (size_t i = 0; i < curNode->neighbors.size(); i++) {
            UndirectedGraphNode* neighbor = curNode->neighbors[i];
            if (table.find(neighbor) == table.end()) {
                // no copy exists
                UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                (table[curNode]->neighbors).push_back(newNode);
                table[neighbor] = newNode;
                cloneHelper2(neighbor, table);
            }
            else {
                // a copy already exists
                UndirectedGraphNode* copy = table[neighbor];
                (table[curNode]->neighbors).push_back(copy);
            }
        }
    }
};

int main() {
    return 0;
}