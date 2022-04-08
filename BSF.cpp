#include <bits/stdc++.h>

using namespace std;

int f = 0, r = -1;
int visited[20], q[20];

void BFS(int v, int a[10][10] , int n)
{
    visited[v] = 1;
    q[++r] = v;
    while (f <= r)
    {
        cout << q[f++] << " ";
        for (int i = 0; i < n; i++)
        {
            if (a[q[f - 1]][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int n, v;
    cin >> n >> v;
    int a[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    BFS(v, a , n);

    return 0;
}