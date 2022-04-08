#include <bits/stdc++.h>

using namespace std;

#define N 1000

vector<bool> isPrime(N , true);

void solve()
{
    isPrime[0] = isPrime[1] = false;
    for(int i=2 ; i*i<=N ; i++)
    {
        for(int j=2*i ; j<N ; j+=i)
        isPrime[j] = false;
    }
}

int main()
{
    solve();
    
    int n , c=0;
    cin >> n;
    
    for(int i=0 ; i<N && c<n ; i++)
        if(isPrime[i])
        {
            cout << i << " ";
            c++;
        }

    return 0;
}