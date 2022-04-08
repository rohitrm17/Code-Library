#include <bits/stdc++.h>

using namespace std;

void display(int *a ,int n)
{
    for(int i=0 ; i<n ; i++)
        printf("%d " , a[i]);
    printf("\n");
}

void swap(int *x , int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int *a , int n , int l)
{
    int largest = l;
    int x = 2*l+1;
    int y = 2*l+2;

    if(x<n && a[x]>a[largest])
        largest = x;
    if(y<n && a[y]>a[largest])
        largest = y;

    if(largest != l)
    {
        swap(&a[largest] , &a[l]);
        heapify(a , n , largest);
    }
}

void heapSort(int *a , int n)
{
    for(int i=(n/2-1) ; i>=0 ; i--)
        heapify(a , n , i);

    for(int i=n-1 ; i>=0 ; i--)
    {
        swap(&a[0] , &a[i]);
        heapify(a , i , 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];

    printf("\nArray before sorting : ");
    display(a , n);

    heapSort(a , n);
    
    printf("\nArray after sorting : ");
    display(a , n);
    return 0;
}