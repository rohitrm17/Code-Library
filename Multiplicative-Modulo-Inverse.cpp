#include <bits/stdc++.h>

using namespace std;

int mmi(int n, int m)
{
    int i = 1;
    while (i < m)
    {
        if ((i * n) % m == 1)
            return i;
        i++;
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int k = mmi(n, m);
    cout << k << endl;
    return 0;
}