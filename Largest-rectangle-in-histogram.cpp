#include <bits/stdc++.h>

using namespace std;

int largestRectanlge(vector<int> v)
{
    stack<int> s;
    v.push_back(0);
    int n=v.size() , i=0 , ans=0;

    while(i < n)
    {
        while(!s.empty() && v[s.top()]>v[i])
        {
            int h=v[s.top()];
            s.pop();
            if(s.empty())
                ans = max(ans , h*i);
            else
            {
                int len = i - s.top() - 1;
                ans = max(ans , h*len);
            }
        }
        s.push(i);
        i++;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];

    cout << largestRectanlge(v) << endl;
    return 0;
}