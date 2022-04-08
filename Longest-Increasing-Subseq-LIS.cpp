#include <bits/stdc++.h>
#define N 30

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> v(n) , LIS(n , 1);
    for(int i=0 ; i<n; i++)
        cin >> v[i];
    
    for(int i=1 ; i<n ; i++)
        for(int j=0 ; j<=i ; j++)
            if(LIS[j]+1>LIS[i] && v[j]<v[i])
                LIS[i]++;
    
    int m=0;
    for(int i=0 ; i<n ; i++)
        m = max(m , LIS[i]);

    cout<<"LIS: "<<*max_element(LIS.begin() , LIS.end());
    return 0;
}