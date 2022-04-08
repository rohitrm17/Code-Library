// Find the shortest sequence from which given to sequence can be derived
// Ex: s1=adefg  s2=plmfgo
// ans: adeplmfgo

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
    
    int l1=s1.size() , l2=s2.size();
    int a[l1+1][l2+1];

    for(int i=0 ; i<=l1 ; i++)
    {
        for(int j=0 ; j<=l2 ; j++)
        {
            if(i == 0)
                a[i][j] = j;
            else
            if(j == 0)
                a[i][j] = i;
            else
            if(s1[i-1] == s2[j-1])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = min(a[i-1][j] , a[i][j-1]) + 1;
        }
    }

    cout << "Min subseq len: " << a[l1][l2] ;

    return 0;
}