#include <bits/stdc++.h>

using namespace std;

void slidingWindow(vector<int> v , int k)
{
    int n=v.size() , i;
    deque<int> dq;

    for(i=0 ; i<k ; i++)
    {
        while(!dq.empty() && v[dq.back()]<v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << v[dq.front()] << " ";
    
    for( ; i<n ; i++)
    {
        if(dq.front() == i-k)
            dq.pop_front();
        while(!dq.empty() && v[dq.back()]<v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        cout << v[dq.front()] << " ";
    }

}

int main()
{
    int n , k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];

    slidingWindow(v , k);

    return 0;
}