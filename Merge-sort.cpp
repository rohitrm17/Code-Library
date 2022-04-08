#include <bits/stdc++.h>

using namespace std;

void display(int *a ,int n)
{
    for(int i=0 ; i<n ; i++)
        printf("%d " , a[i]);
    printf("\n");
}

void merge(int *a ,int l ,int mid ,int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int x[n1] , y[n2];

    for(int i=0 ; i<n1 ; i++)
        x[i] = a[i+l];
    for(int i=0 ; i<n2 ; i++)
        y[i] = a[i+mid+1];

    int i=0 , j=0 , k=l;
    while(i<n1 && j<n2)
    {
        if(x[i] < y[j])
        {
            a[k] = x[i];
            i++;
            k++;
        }
        if(x[i] > y[j])
        {
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        a[k] = x[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = y[j];
        j++;
        k++;
    }
}

void mergeSort(int *a ,int l , int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        mergeSort(a , l , mid);
        mergeSort(a , mid+1 , r);
        merge(a , l , mid , r);
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

    mergeSort(a , 0 , n);
    
    printf("\nArray after sorting : ");
    display(a , n);
    return 0;
}