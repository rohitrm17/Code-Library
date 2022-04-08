#include <bits/stdc++.h>

using namespace std;

// First find the Longest common subsequence present in given string and its
// reverse, then do length of string - LCS 

void MakePalindrome(string s1)
{
    string s2=s1;
    reverse(s2.begin() , s2.end());
    int n=s1.size();
    vector<vector<int>> v(n+1 , vector<int>(n+1 , 0));

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n; j++)
        {
            if(s1[i-1] == s2[j-1])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = max(v[i-1][j] , v[i][j-1]);
        }
    }
    int lcs = v[n][n];

    cout << "To make " << s1 << " a palindrome, minimum char to be added are: " << (n-lcs) << endl;
}

int main()
{
    string s;
    cin >> s;
    MakePalindrome(s);
    return 0;
}