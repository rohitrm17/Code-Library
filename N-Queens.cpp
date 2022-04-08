#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

bool isSafe(int x , int y)
{
    for(int i=0 ; i<a.size() ; i++) // present row
        if(a[x][i] == 1)
            return false;

    // for(int i=0 ; i<x ; i++) // present col
    //     if(a[i][y] == 1)
    //         return false;
    
    for(int i=x , j=y ; i>=0 && j>=0 ; i-- , j--) // upper left diagonal
        if(a[i][j] == 1)
            return false;
    
    // for(int i=x , j=y ; i>=0 && j<a.size() ; i-- , j++) // upper right diagonal
    //     if(a[i][j] == 1)
    //         return false;

    for(int i=x , j=y ; j>=0 && i<a.size() ; i++ , j--) // lower left diagonal
        if(a[i][j] == 1)
            return false;

    return true;
}

void display(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ;j<n ; j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

bool nQueen(int s)
{
    if(s >= a.size())   // all Queens are placed
        return true;
    
    for(int i=0 ; i<a.size() ; i++)
    {
        if(isSafe(i , s))
        {
            a[i][s] = 1;
        
            if(nQueen(s+1))
                return true;

            a[i][s] = 0;    // backtrack
        }
    }
    return false;
}

int main()
{
    int n , q , ans=0;
    cout<<"Enter n : ";
    cin>>n;

    a = vector<vector<int>> (n);

    for(int i=0 ; i<n ; i++)
        a[i] = vector<int>(n,0);

    if(nQueen(0))
    {
        cout<<"\nSolution found \n";
        display(n);
    }
    else
        cout<<"\nNo Solution !!";
    return 0;
}
