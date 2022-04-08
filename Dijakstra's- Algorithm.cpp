#include <bits/stdc++.h>

using namespace std;

int n, g[10][10], visited[10];

int dist[10], path[10];

void display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d \t", g[i][j]);
        printf("\n");
    }
}

void dijakstra(int sr)
{
    int min, newSr;

    for (int i = 0; i < n; i++)
    {
        dist[i] = g[sr][i];
        path[i] = sr;
        visited[i] = 0;
    }

    visited[sr] = 1;

    for (int i = 0; i < n - 1; i++)
    {
        min = 99999;
        for (int m = 0; m < n; m++) // Finding next source
        {
            if (min > dist[m] && visited[m] == 0)
            {
                min = dist[m];
                newSr = m;
            }
        }

        visited[newSr] = 1;

        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                if (dist[j] > (dist[newSr] + g[newSr][j]))
                {
                    dist[j] = dist[newSr] + g[newSr][j];
                    path[j] = newSr;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (dist[i] == 10000)
            path[i] = -1;
}

void display_path(int sr, int dest)
{
    int j = dest;
    if (path[dest] == -1)
    {
        printf("Path does not exist !!");
        return;
    }
    printf("%d <- ", dest);
    do
    {
        j = path[j];
        printf("%d <- ", j);
    } while (j != sr);
}

int main()
{
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    
    printf("\nmatrix: \n");
    display();
    
    printf("\nEnter source: ");
    cin >> a;

    dijakstra(a);

    printf("\n\nFinal : ");
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);

    for (int i = 0; i < n; i++)
    {
        if (a != i)
        {
            printf("\nPath to %d: \n", i);
            display_path(a, i);
        }
    }
    
    return 0;
}
