// Finding the maximum sub array sum
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];

    int sum=0 , ans=0;

    for(int i=0 ; i<n ; i++)
    {
        sum = sum + v[i];
        if(sum < 0)
            sum = 0;
        ans = max(ans , sum); 
    }

    cout << "Max subarray sum: " << ans; 

    return 0;
}