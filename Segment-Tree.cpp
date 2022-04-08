#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define INF 10000000

ll arr[10000000];
ll st[10000000];

void build(ll si, ll ss, ll se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }
    ll mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    if (st[2 * si] < st[2 * si + 1])
        st[si] = st[2 * si];
    else
        st[si] = st[2 * si + 1];
}

ll query(ll si, ll ss, ll se, ll qs, ll qe)
{
    if (qe < ss || qs > se)
        return INF;
    if (ss >= qs && se <= qe)
        return st[si];
    ll mid = (ss + se) / 2;
    ll l = query(2 * si, ss, mid, qs, qe);
    ll r = query(2 * si + 1, mid + 1, se, qs, qe);
    if (l < r)
        return l;
    else
        return r;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    while (m--)
    {
        ll l, r, k;
        cin >> l >> r;
        k = query(1, 1, n, l + 1, r + 1);
        printf("%lld\n", k);
    }
    return 0;
}