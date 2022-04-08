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

void bubbleSort(int *a ,int n)
{
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n-1-i ; j++)
        {
            if(a[j] > a[j+1])
                swap(&a[j] , &a[j+1]);
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

    bubbleSort(a , n);
    
    printf("\nArray after sorting : ");
    display(a , n);
    return 0;
}