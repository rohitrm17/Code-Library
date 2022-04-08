#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool found = false;
    int n , m , key;
    cin >> n >> m;
    
    int a[n][m];
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            cin >> a[i][j];

    cin >> key;

    int r=0 , c=m-1;

    while(r<n && c>=0)
    {
        if(a[r][c] == key)
        {
            found = true;
            break;
        }
        else
        if(a[r][c] > key)
            c--;
        else
            r++;
    }

    if(found)
        cout << "Found";
    else
        cout << "Not Found";

    return 0;
}