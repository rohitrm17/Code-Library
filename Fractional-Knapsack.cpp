#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;
};

bool comp(Item x , Item y)
{
    double a=((double)x.value/x.weight);    
    double b=((double)y.value/y.weight);    
    return a > b;
}
    
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr , arr+n , comp);
    
    double w=0 , ans=0;
    
    for(int i=0 ; i<n ; i++)
    {
        if(w+arr[i].weight <= W)
        {
            w = w + arr[i].weight;
            ans = ans + arr[i].value;
        }
        else
        {
            double rem = W - w;
            ans = ans + arr[i].value*(rem/arr[i].weight);
            break;
        }
    }      
    return ans;
}

int main()
{
    int n , W;
    cin >> n >> W;

    Item arr[n];
    for(int i=0 ; i<n ; i++)
        cin >> arr[i].value >> arr[i].weight;

    cout << fractionalKnapsack(W , arr , n) << endl;

    return 0;
}