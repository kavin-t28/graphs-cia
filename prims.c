#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 1e9

int n, m;
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int dist[MAX_VERTICES];
int parent[MAX_VERTICES];

void prim(int s)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[s] = 0;
    parent[s] = -1;

    for (i = 0; i < n - 1; i++)
    {
        int u = -1, min_dist = INF;
        for (j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = true;

        for (j = 0; j < n; j++)
        {
            if (graph[u][j] && !visited[j] && graph[u][j] < dist[j])
            {
                dist[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = INF;
        }
    }
    for (i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }
    int s;
    scanf("%d", &s);
    prim(s);
    for (i = 0; i < n; i++)
    {
        printf("%d - %d\n", i, parent[i]);
    }
    return 0;
}
