#include <bits/stdc++.h>

using namespace std;

int parent[30];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main()
{
    int n;
    cin >> n;
    
    for(int i=0 ; i<30 ; i++)
        parent[i] = i;
    
    int u , v;
    while(n--)
    {
        cin >> u >> v;
        union1(u , v);
    }

    for(int i=0 ; i<30 ; i++)
        cout << parent[i] << " ";

    return 0;
}