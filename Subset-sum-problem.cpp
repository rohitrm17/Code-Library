// Find if given sum is possible from given array
// Ex: arr = {1 2 3 5 7}  sum=9
// Ans: possible array = {2 7}
 
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , sum;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];
    
    cin >> sum;

    int ss[n+1][sum+1];

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=sum ; j++)
        {
            if(j == 0)
                ss[i][j] = 1;
            else    
            if(i == 0)
                ss[i][j] = 0;
            else
            if(ss[i-1][j] == 1)
                ss[i][j] = 1;
            else
            {
                if(v[i-1] > j)
                    ss[i][j] = 0;
                else
                    ss[i][j] = ss[i-1][j-v[i-1]];
            }
        }
    }

    if(ss[n][sum] == 1)
        cout << "Sum is possible";
    else
        cout << "Sum not possible";

    return 0;
}