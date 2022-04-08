#include <bits/stdc++.h>

using namespace std;

// The rod is cut into more than 2 pieces 

int RodCuttingProblem(int n)
{
    vector<int> v(n+1 , 0);
    for(int i=2 ; i<=n ; i++)
        for(int j=1 ; j<=i/2 ; j++)
            v[i] = max(v[i] , max((j*(i-j)) , j*(v[i-j])));
    return v[n];
}

int main() 
{
    int n;
    cin >> n;
    cout << "Ans:" << RodCuttingProblem(n) << endl;	
	return 0;
}