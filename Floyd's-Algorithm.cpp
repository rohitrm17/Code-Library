#include <bits/stdc++.h>

using namespace std;

int n , g[10][10];

void display()
{
    for(int i=0 ; i<n ; i++)
    {
        if(i == 0)
        {
            for(int k=0 ; k<n ; k++)
                printf("\t%d" , k);
            printf("\n");
        }
        for(int j=0 ; j<n ; j++)
        {
            if(j == 0)
                printf("%d\t" , i);
            printf("%d\t" , g[i][j]);
        }
        printf("\n");
    }
}

int mymin(int a , int b)
{
    if(a < b)
        return a;
    return b;
}

void floyd()
{
    for(int f=0 ; f<n ; f++)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(i!=f && j!=f && i!=j)
                {
                    g[i][j] = mymin(g[i][j] , g[i][f]+g[f][j]);
                }
            }
        }
    }
}

int main()
{
    int a;
    cin >> n;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin >> g[i][j];
        }
    }
    printf("\nmatrix: \n");
    display();
    floyd();
    printf("\nmatrix: \n");
    display();
    return 0;
}
