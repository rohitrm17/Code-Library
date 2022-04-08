#include <bits/stdc++.h>

using namespace std;

int LongestCommonSubsequence(string s1 , string s2)
{
    int n=s1.size() , m=s2.size();
    vector<vector<int>> v(n+1 , vector<int>(m+1));

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=m ; j++)
        {
            if(i==0 || j==0)
                v[i][j] = 0;
            else
            {
                if(s1[i-1] == s2[j-1])
                    v[i][j] = v[i-1][j-1] + 1;
                else
                    v[i][j] = max(v[i-1][j] , v[i][j-1]);
            }
        }
    }

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=m ; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    return v[n][m];
}

int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
    cout << "Ans: " << LongestCommonSubsequence(s1 , s2) << endl;
    return 0;
}