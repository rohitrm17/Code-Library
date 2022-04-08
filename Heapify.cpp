#include <bits/stdc++.h>

using namespace std;

void Heapify(int a[] , int n , int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l] > a[largest]) 
        largest = l;
    if(r<n && a[r] > a[largest]) 
        largest = r;
    if(largest!=i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        Heapify(a , n , largest);
    }
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for(int i=0 ; i<n ; i++)
        cin >> v[i];

    cout << "Before Heaification: \n";
    for(int i=0 ; i<n ; i++)
        cout << v[i] << " ";

    Heapify(v , n , 0);

    cout << "\nAfter Heaification: \n";
    for(int i=0 ; i<n ; i++)
        cout << v[i] << " ";

    return 0;
}