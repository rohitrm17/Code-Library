#include <bits/stdc++.h>

using namespace std;

int solve(int n)
{
    int rev=0 , rem;
    while(n > 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    return rev;
}

int main()
{
    int n;
    cin >> n;
    cout << "Reverse of " << n << " : " << solve(n) << endl;
    return 0;
}