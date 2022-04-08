#include <bits/stdc++.h>

#define INFY 9999

using namespace std;

void dispPar(int parent[30], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d ", parent[i]);
    printf("\n");
}

int find(int i, int parent[30])
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j, int parent[30])
{
    int a = find(i, parent);
    int b = find(j, parent);
    parent[a] = b;
}

void kruskals(int Graph[30][30], int parent[30], int n)
{
    int minCost = 0, cost[30][30], i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (Graph[i][j] == 0)
            {
                cost[i][j] = INFY;
            }
            else
            {
                cost[i][j] = Graph[i][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    while (count < n - 1)
    {
        int min = INFY, a = -1, b = -1;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (find(i, parent) != find(j, parent) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b, parent);
        dispPar(parent, n);
        printf("Edge %d:(%d,%d) cost:%d\n", count++, a, b, min);
        minCost = minCost + min;
    }
    printf("Minimum cost is %d\n", minCost);
}

void main()
{
    int Graph[30][30], n, parent[30], i, j;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    }
    kruskals(Graph, parent, n);
}