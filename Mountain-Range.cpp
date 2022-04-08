#include <bits/stdc++.h>

using namespace std;

void preprocessor(int a[], int n, int left[], int right[])
{
    left[0] = 0;
    int lastIncr = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            lastIncr = i;
        left[i] = lastIncr;
    }
    right[n - 1] = n - 1;
    int firstDecr = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            firstDecr = i;
        right[i] = firstDecr;
    }
}

bool MountainForm(int arr[], int left[], int right[], int l, int r)
{
    return (right[l] >= left[r]);
}

int main()
{
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int left[n], right[n];
    int l, r;
    
    preprocessor(a, n, left, right);
    
    cin >> l >> r;

    if (MountainForm(a, left, right, l, r))
        cout << "Yes-Its in Mountain Range" << endl;
    else
        cout << "No-Its not" << endl;

    return 0;
}