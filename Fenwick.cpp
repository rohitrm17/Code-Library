#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> BIT(n);

void update(int x , int val)
{
    for( ; x<n ; x += (x & (-x)))
        BIT[x] += val;
}

void query(int x)
{
    int sum = 0;
    for( ; x>0 ; x -= (x & (-x)))
        sum += BIT[x];
    cout << "Sum: " << sum;
}

int main()
{
    
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> v[i];
        update(i , v[i]);
    }
    
    int l;
    cin >> l;
    query(l);

    return 0;
}