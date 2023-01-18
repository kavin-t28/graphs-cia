#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 5000

typedef struct {
  int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m;

int find(int parent[], int i) {
    if (parent[i] == -1) return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset)
        parent[xset] = yset;
}

int kruskal() {
    int i, e = 0, u, v;
    int ans = 0;
    for (i = 0; i < m; i++) {
        u = find(parent, edges[i].u);
        v = find(parent, edges[i].v);
        if (u != v) {
            ans += edges[i].w;
            Union(parent, u, v);
            e++;
        }
        if (e == n - 1) break;
    }
    return ans;
}

int main() {
    int i;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    qsort(edges, m, sizeof(Edge), comp);
    int s;
    scanf("%d", &s);
    int ans = kruskal();
    printf("The minimum spanning tree weight is : %d \n", ans);
    return 0;
}

