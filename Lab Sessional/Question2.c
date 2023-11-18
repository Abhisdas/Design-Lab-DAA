/* 2. Let G be the undirected, weighted graph of integers from 1 to 10 where
there is an undirected edge between i and j either (if integer i divides
integer j evenly and i < j) or (if j = i + 1). If there is an edge between
vertex i and vertex j in the graph, then the weight of the edge is given by
the following formula: C(i, j) = (i + j)2 % 100. Find a representation of the
graph in cost-adjacency matrix format. Further, show the result of
performing Kruskal’s algorithm on this graph to find a minimum-cost
spanning tree of the graph. Display the obtained minimum-cost spanning
tree in cost-adjacency list representation. */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

struct Edge {
    int src, dest, weight;
};

int compareEdges_2300(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

int Find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return Find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xSet = Find(parent, x);
    int ySet = Find(parent, y);
    parent[xSet] = ySet;
}

void printMST_2300(struct Edge result[], int e) {
    printf("Minimum-cost Spanning Tree in Cost-Adjacency List Representation:\n");
    for (int i = 0; i < e; ++i) {
        printf("%d - %d : %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
    }
}

void kruskalMST_2300(int cost[MAX][MAX]) {
    int e = 0; 
    struct Edge edges[MAX * MAX];

    for (int i = 0; i < MAX; ++i) {
        for (int j = i + 1; j < MAX; ++j) {
            if ((j == i + 1) || (i > 0 && j % i == 0)) {
                edges[e].src = i;
                edges[e].dest = j;
                edges[e].weight = cost[i][j];
                ++e;
            }
        }
    }

    qsort(edges, e, sizeof(edges[0]), compareEdges_2300);

    struct Edge result[MAX];
    int parent[MAX];
    for (int i = 0; i < MAX; ++i)
        parent[i] = -1;

    int treeEdgeCount = 0;
    for (int i = 0; i < e && treeEdgeCount < MAX - 1; ++i) {
        int x = Find(parent, edges[i].src);
        int y = Find(parent, edges[i].dest);

        if (x != y) {
            result[treeEdgeCount++] = edges[i];
            Union(parent, x, y);
        }
    }

    printMST_2300(result, treeEdgeCount);
}

int main() {
    int n = MAX;
    int cost[MAX][MAX];

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((j == i + 1) || (i > 0 && j % i == 0)) {
                cost[i][j] = (i + j) * (i + j) % 100;
                cost[j][i] = cost[i][j];  
            } else {
                cost[i][j] = 0;  
            }
        }
    }

  
    printf("Cost-adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", cost[i][j]);
        }
        printf("\n");
    }

    
    printf("\nMinimum-cost spanning tree:\n");
    kruskalMST_2300(cost);

    return 0;
}
