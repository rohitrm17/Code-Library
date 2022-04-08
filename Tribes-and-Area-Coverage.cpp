/*
https://www.hackerrank.com/contests/aps-2022-vie-01/challenges/tribes-and-area-coverage
*/

// Try 1
/*
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
    cout<<endl<<endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+2 , vector<int>(n+2 , 0));
    vector<vector<int>> v2 , v3;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            cin >> v[i][j];
    v2 = v;
    v3 = v;

    int maxArea=0 ,  i , j , k , l , tribeCount=0 , area , zeroCount=0;
    int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4;

    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
        {
            v2[i][j] += v2[i-1][j] + v2[i][j-1] - v2[i-1][j-1];
            if(v[i][j] == 0)
                zeroCount++;
        }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            k = i;
            l = j;
            if(v[k][l]==1 && v[k][l+1]==0 && v[k][l-1]==0 && v[k+1][l]==0 && v[k-1][l]==0)
            {
                tribeCount++;
                area = 1;
                v[k][l] = 0;
                zeroCount++;
                continue;
            }
            
            x1=y1=x2=y2=x3=y3=x4=y4=-1;
            if(v[k][l]==1 && v[k][l+1]==1 && v[k+1][l]==1)
            {
                x1 = k-1;
                y1 = l-1;
                v[k][l] = 0;
                zeroCount++;
                while(v[k][l+1]==1 && k<=n && l<=n)
                {
                    l++;
                    if(v[k][l]==1 && v[k+1][l]==1 && k<=n && l<=n)
                    {
                        x2 = k-1;
                        y2 = l;
                        v[k][l] = 0;
                        zeroCount++;
                        while(v[k+1][l]==1 && k<=n && l<=n)
                        {
                            k++;
                            if(v[k][l]==1 && v[k][l-1]==1 && k<=n && l<=n)
                            {
                                x3 = k;
                                y3 = l;
                                x4 = k;
                                y4 = y1;
                            }
                            v[k][l] = 0;
                            zeroCount++;
                        }
                    }
                    v[k][l] = 0;
                    zeroCount++;
                }
            }
            if(x1!=-1 && y1!=-1 && x2!=-1 && y2!=-1 && x3!=-1 && y3!=-1 && x4!=-1 && y4!=-1)
            {
                area = v2[x3][y3] - v2[x2][y2] - v2[x4][y4] + v2[x1][y1];
                cout<<"Area "<<area<<endl;
                for(int a1=x1+1 ; a1<=x4 ; a1++)                
                    for(int a2=x1+1 ; a2<=y2 ; a2++)
                    {
                        if(v[a1][a2] == 1)
                            zeroCount++;
                        v[a1][a2] = 0;
                    }

                if(maxArea < area)
                    maxArea = area;
                    
                tribeCount++;
            }
            print(v);
        }
        // if(zeroCount == n*n)
        //     break;
    }
    
    cout<<tribeCount<<"\n"<<maxArea;
    return 0;
}
*/

// Try 2
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
    cout<<endl<<endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+2 , vector<int>(n+2 , 0));
    vector<vector<int>> v2 , v3;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            cin >> v[i][j];
    v2 = v;
    v3 = v;

    int maxArea=0 ,  i , j , k , l , tribeCount=0 , area=0 , zeroCount=0;
    int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 , t;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if(v[i][j]==1 && v[i][j+1]==0 && v[i][j-1]==0 && v[i+1][j]==0 && v[i-1][j]==0)
            {
                tribeCount++;
                area = 1;
            }
            else
            if(v[i][j] == 1)
            {
                tribeCount++;
                x1 = i;
                y1 = j;
                t = j+1;
                v[i][j] = 0;
                while(v[i][t] == 1)
                {
                    v[i][t] = 0;
                    t++;
                }
                x2 = i;
                y2 = t-1;
                t = x1+1;
                while(v[t][y1]==1 && v[t][y2]==1)
                {
                    v[t][y1] = 0;
                    v[t][y2] = 0;
                    t++;
                }
                x3 = t-1;
                y3 = y2;
                x4 = t-1;
                y4 = y1;
                for(t=y4 ; t<=y3 ; t++)
                    v[x4][t] = 0;
                
                cout<<"x1: "<<x1<<" y1: "<<y1<<endl;
                cout<<"x2: "<<x2<<" y2: "<<y2<<endl;
                cout<<"x3: "<<x3<<" y3: "<<y3<<endl;
                cout<<"x4: "<<x4<<" y4: "<<y4<<endl;
                
                if(v[x1+1][y1+1] == 0)
                {
                    area = 2*(y2 - y1 + 1) + 2*(x4 - x1 - 1);
                }
                else
                {
                    for(int t1=x1+1 ; t1<=x4-1 ; t1++)
                        for(int t2=y1+1 ; t2<=y2-1 ; t2++)
                            v[t1][t2] = 0;
                    
                    area = (y2 - y1 + 1)*(x4 - x1 + 1);
                }
                print(v);  
            }
            maxArea = max(maxArea , area);
        }
    }
    
    cout<<tribeCount<<"\n"<<maxArea;
    return 0;
}
