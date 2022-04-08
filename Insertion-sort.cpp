#include <bits/stdc++.h>

using namespace std;

void display(int *a ,int n)
{
    for(int i=0 ; i<n ; i++)
        printf("%d " , a[i]);
    printf("\n");
}

void insertionSort(int *a ,int n)
{
    for(int i=1 ; i<n ; i++)
    {
        int j = i-1 , temp = a[i];
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
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

    insertionSort(a , n);
    
    printf("\nArray after sorting : ");
    display(a , n);
    return 0;
}