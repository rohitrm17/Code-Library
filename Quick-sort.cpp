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

int partition(int *a , int l , int r)
{
    int i=l , j=r+1 , p=l;
    while(i < j)
    {
        do
        {
            i++;
        }while(a[i] <= a[p]);
        do
        {
            j--;
        }while(a[j] > a[p]);
        if(i < j)
            swap(&a[j] , &a[i]);
    }
    swap(&a[j] , &a[p]);
    return j;
}

void quickSort(int *a , int l , int r)
{
    int p;
    if(l < r)
    {
        p = partition(a , l , r);
        quickSort(a , l , p-1);
        quickSort(a , p+1 , r);
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

    quickSort(a , 0 , n);
    
    printf("\nArray after sorting : ");
    display(a , n);
    return 0;
}