#include <bits/stdc++.h>

using namespace std;

int maximizingXor(int l, int r) 
{
    int ans=0;
    for(int i=l ; i<=r ; i++)
    {
        for(int j=i+1 ; j<=r ; j++)
            if((i^j) > ans)
                ans = (i^j);
    }
    return ans;
}

int main()
{
    

    int l;
    cin >> l;
    
    int r;
    cin >> r;
    
    int result = maximizingXor(l, r);

    cout << result << "\n";

    return 0;
}
