#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() 
{
    int n , visitedCount=0 , j , c=0;
    cin >> n;
    vector<int> v(n) , visited(n , 0) , temp;
    vector<vector<int>> ans;
    
    for(int i=0 ; i<n ; i++)
    {
        cin >> v[i];
        v[i]--;
        if(v[i] == i)
            c++;
    }
	
	if(c == n)
	{
	    cout << n << "\n";
	    for(int i=1 ; i<=n ; i++)
	        cout << i << " " << i <<"\n";
	    return 0;
	}
	
	while(visitedCount != n)
	{
	    for(int i=0 ; i<n ; i++)
	        if(visited[i] == 0)
	        {
	            j = i;
	            temp.push_back(j);
	            visited[j] = 1;
	            visitedCount++;
	            break;
	        }
	        
	    do
	    {
	        j = v[j];
	        if(visited[j] == 0)
	        {
	            visited[j] = 1;
	            visitedCount++;
	        }
	        
	        temp.push_back(j);
	        
	    }while(j != temp[0]);
	    
	    ans.push_back(temp);
	    temp.clear();
	}
	cout << ans.size() << "\n";
	for(int i=0 ; i<ans.size() ; i++)
	{
	    for(auto e: ans[i])
	        cout << e+1 <<" ";
	    cout <<"\n";
	}

	return 0;
}
