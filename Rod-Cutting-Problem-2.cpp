// Cut the rod such that sum is max
// Ex: values = 2 3 7 8 10
//     size =   1 2 3 4 5
// Ans: 
#include <bits/stdc++.h>

using namespace std;

int RodCuttingProblem2()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for(int i=0 ; i<n ; i++)
        cin >> values[i];
    
    vector<int> v(n+1 , 0);
    for(int i=1 ; i<=n ; i++)
        for(int j=0 ; j<i ; j++)
            v[i] = max(v[i] , v[i-(j+1)]+values[j]);
    
    return v[n];
}

int main() 
{
    cout << "Max sum:" << RodCuttingProblem2() << endl;	
	return 0;
}