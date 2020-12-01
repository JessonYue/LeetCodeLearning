package com.slow.lib.practice.graph;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 有向无环图
 *
 * @Author wuchao
 * @Date 2020/11/30-8:59 AM
 * @description
 * @email 329187218@qq.com
 * @see
 */
class DirectedAcyclicGraph {
    private LinkedList<Integer> adj[]; // 邻接表
    private int nodeCount;//节点个数

    public DirectedAcyclicGraph(int nodeCount) {
        this.nodeCount = nodeCount;
        adj = new LinkedList[nodeCount];
        for (int i = 0; i < nodeCount; i++) {
            adj[i] = new LinkedList();
        }
    }

    //添加一条边，t先于s，t->s;
    public void addEdge(int t, int s) {
        adj[t].add(s);
    }

    public void toposort() {
        int[] indgrees = new int[nodeCount];
        for (int i = 0; i < adj.length; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                indgrees[adj[i].get(j)]++;
            }
        }
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 0; i < indgrees.length; i++) {
            if (indgrees[i] == 0) {
                queue.offer(i);
            }
        }
        while (!queue.isEmpty()) {
            int top = queue.poll();
            System.out.println("topo sort item==" + top);
            for (int i = 0; i < adj[top].size(); i++) {
                int w = adj[top].get(i);
                indgrees[w]--;
                if (indgrees[w] == 0) queue.add(w);
            }
        }

    }

    public static void main(String[] args) {
        DirectedAcyclicGraph graph = new DirectedAcyclicGraph(6);
        graph.addEdge(0,1);
        graph.addEdge(0,2);
        graph.addEdge(1,2);
        graph.addEdge(1,3);
        graph.addEdge(2,3);
        graph.addEdge(2,5);
        graph.addEdge(3,4);
        graph.toposort();
    }


}
