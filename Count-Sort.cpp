#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> v(n) , count(11,0) , ans(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];

    for(int i=0 ; i<n ; i++)
        count[v[i]]++;
    
    for(int i=1 ; i<11 ; i++)
        count[i] = count[i] + count[i-1];

    for(int i=0 ; i<n ; i++)
    {
        count[v[i]]--;
        ans[count[v[i]]] = v[i];
    }

    for(int i=0 ; i<ans.size() ; i++)
        cout<<ans[i]<<" ";

    return 0;
    
}