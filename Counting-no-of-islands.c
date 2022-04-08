#include <stdio.h>
#include <stdlib.h>

int g[10][10] , reached[10] , v;

int dfs(int s)
{
    reached[s] = 1;
    for(int i=0 ; i<v ; i++)
        if(g[s][i]==1 && reached[i]==0)
            dfs(i);
}

int count()
{
    int c=0;

    for(int i=0 ; i<v ; i++)
        if(reached[i]==0)
        {
            dfs(i);
            c++;
        }

    return c;
}

int main()
{
    FILE *f = fopen("Input.txt" , "r");
    int e;
    fscanf(f , "%d" , &v);
    for(int i=0 ; i<v ; i++)
        for(int j=0 ; j<v ; j++)
        {
            fscanf(f , "%d " , &e);
            g[i][j] = e;
        }
    printf("\nGraph :\n");
    for(int i=0 ; i<v ; i++)
    {
        for(int j=0 ; j<v ; j++)
            printf("%d " , g[i][j]);
        printf("\n");
    }
    e = count();
    printf("\nIslands : %d \n" , e);
    return 0;
}

/*
6
0 1 1 0 0 0
1 0 1 0 0 0
1 1 0 0 0 0
0 0 0 0 1 1
0 0 0 1 0 1
0 0 0 1 1 0
*/
/*
    for(int i=0 ; i<v ; i++)
        if(reached[i] == 1)
        {
            c++;
            break;
        }*/
