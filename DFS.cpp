#include <bits/stdc++.h>

using namespace std;

int reach[20];

void DFS(int v, int a[10][10] , int n)
{
    reach[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] && !reach[i])
        {
            cout << v << "->" << i << endl;
            DFS(i, a , n);
        }
    }
}

int main()
{
    int n , v;
    cin >> n >> v;
    int a[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    DFS(v , a , n);

    return 0;
}