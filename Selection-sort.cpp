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

void selectionSort(int *a ,int n)
{
    int min;
    for(int i=0 ; i<n ; i++)
    {
        min = i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        swap(&a[i] , &a[min]);
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

    selectionSort(a , n);
    
    printf("\nArray after sorting : ");
    display(a , n);
    return 0;
}