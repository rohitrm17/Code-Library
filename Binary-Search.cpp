#include <bits/stdc++.h>

using namespace std;

int BinarySearch(int a[], int l, int r, int k)
{
    if (r >= l)
    {
        int m = l + (r - 1) / 2;

        if (a[m] == k)
            return m;
        if (a[m] > k)
            return BinarySearch(a, l, m - 1, k);
        return BinarySearch(a, m + 1, r, k);
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    int result = BinarySearch(a, 0, n - 1, k);
    if (result != -1)
        cout << "Found at " << result << endl;
    else
        cout << "Element not found!" << endl;
    return 0;
}