#include <bits/stdc++.h>

using namespace std;

vector<int> waveSort(vector<int> v) // Also can be done by first sorting then swaping alternative index
{
    int n = v.size();
    for(int i=1 ; i<n-1 ; i+=2)
    {
        if(v[i] > v[i-1])
            swap(v[i] ,v[i-1]);
        if(v[i] > v[i+1])
            swap(v[i] , v[i+1]);
    }
    return v;
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin >> n;
    vector<int> v(n);
    cout<<"\nEnter array: ";
    for(int i=0 ; i<n ; i++)
        cin >> v[i];
    v = waveSort(v);
    for(int i=0 ; i<n ; i++)
        cout<<v[i]<<" ";
    return 0;
}