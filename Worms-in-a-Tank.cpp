/*
https://www.hackerrank.com/contests/aps-2022-vie-01/challenges/worms-in-a-tank
*/

#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> v)
{
    for(int i=0 ; i<v[0].size() ; i++)
    {
        for(int j=0 ; j<v[0].size() ; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+2 , vector<int>(n+2 , 0));

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            cin >> v[i][j];
    
    int i , j , k , l , count=0;
   
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if(v[i][j] == 1)
            {
                count++;
                while(v[i][j+1] == 1)
                {
                    j++;
                    v[i][j] = 0;
                    
                }
                
                while(v[i+1][j] == 1)
                {
                    i++;
                    v[i][j] = 0;
                    
                }
                
                while(v[i+1][j+1] == 1)
                {
                    i++;
                    j++;
                    v[i][j] = 0;
                    
                }
                
                while(v[i+1][j-1] == 1)
                {
                    i++;
                    j--;
                    v[i][j] = 0;
                    
                }
            }
        }
    }
    
    cout<<count;
    return 0;
}