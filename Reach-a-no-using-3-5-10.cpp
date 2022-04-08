#include <bits/stdc++.h>
#define N 30

using namespace std;

vector<int> v(N , 0);

void fun()
{
    v[0] = 1;

    for(int i=3 ; i<N ; i++)
        v[i] += v[i-3];

    for(int i=5 ; i<N ; i++)
        v[i] += v[i-5];
    
    for(int i=10 ; i<N ; i++)
        v[i] += v[i-10];
}

int main()
{
    fun();
    int a;
    cin >> a;
    cout<<"No. of ways to reach "<<a<<": "<<v[a];
    return 0;
}