#include <bits/stdc++.h>

using namespace std;

void solve(int n)
{
    int num=n , rev=0;

    while (num > 0)
    {
        rev = (num*10) + (num%10);
        num = num / 10;
    }
    if(rev == n)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}