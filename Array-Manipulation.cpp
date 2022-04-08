#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)

#define ll long long int

using namespace std;

int main()
{
    boost;
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    int a, b, k;
    for (int q = 0; q < m; q++)
    {
        cin >> a >> b >> k;
        v[a - 1] += k;
        v[b] -= k;
    }
    ll max = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        c += v[i];
        if (c > max)
            max = c;
    }
    cout << max << endl;
    return 0;
}
