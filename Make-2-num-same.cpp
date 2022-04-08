#include <bits/stdc++.h>

using namespace std;

int solve(int a , int b)
{
    int n = a^b;
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n & (n-1);
    }
    return count;    
}

int main()
{
    int a , b;
    cin >> a >> b;
    cout << solve(a , b) << endl;
    return 0;
}