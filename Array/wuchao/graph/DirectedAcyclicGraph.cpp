//
// Created by 吴超 on 2020/12/1.
//
#include "DirectedAcyclicGraph.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DirectedAcyclicGraph {
public:
    DirectedAcyclicGraph(int);

    void addEdge(int, int);

    void topoSort();

private:
    int nodeCount;
    vector<vector<int>> adj;
};

DirectedAcyclicGraph::DirectedAcyclicGraph(int count) {
    nodeCount = count;
    adj = vector<vector<int>>(nodeCount);
}

//增加一条边，s先于t，则s->t ，将t插入s的领接表中
void DirectedAcyclicGraph::addEdge(int s, int t) {
    auto itr = adj[s].begin();
    adj[s].insert(itr, t);
}

void DirectedAcyclicGraph::topoSort() {
    vector<int> indgrees(nodeCount);
    //统计每个顶点的入度
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int w = adj[i][j];
            indgrees[w]++;
        }
    }
    queue<int> queue;
    for (int i = 0; i < indgrees.size(); i++) {
        if (indgrees[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int item = queue.front();
        cout << "item ==" << item << endl;
        queue.pop();
        for (int i = 0; i < adj[item].size(); i++) {
            int w = adj[item][i];
            indgrees[w]--;
            if (indgrees[w] == 0) queue.push(w);
        }
    }
}

int main() {
    DirectedAcyclicGraph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.topoSort();
}
