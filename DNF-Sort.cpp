#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> v)
{
    for(int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

vector<int> dnfSort(vector<int> v)
{
    int low=0 , mid=0 , high=v.size()-1;
    while(mid <= high)
    {
        if(v[mid] == 0)
        {
            swap(v[low] , v[mid]);
            low++;
            mid++;
        }
        else
        if(v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid] , v[high]);
            high--;
        }
    }
    return v;
}

int main()
{
    int n;
    cout<<"DNF sorting done on only array containing 3 unique elements\n";
    cout<<"\nEnter n: ";
    cin>>n;
    vector<int> v(n);
    cout<<"\nEnter array : ";
    for(int i=0 ; i<n ; i++)
        cin>>v[i];
    v = dnfSort(v);
    display(v);
    return 0;
}