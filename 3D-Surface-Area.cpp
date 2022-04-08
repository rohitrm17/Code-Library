#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector<vector<int>> a)
{
    int s = 0, r = a.size(), c = a[0].size();

    for (int i = 1; i < r - 1; i++)
        for (int j = 1; j < c - 1; j++)
        {
            if (a[i][j] > a[i - 1][j])
                s += a[i][j] - a[i - 1][j];

            if (a[i][j] > a[i][j - 1])
                s += a[i][j] - a[i][j - 1];

            if (a[i][j] > a[i + 1][j])
                s += a[i][j] - a[i + 1][j];

            if (a[i][j] > a[i][j + 1])
                s += a[i][j] - a[i][j + 1];
        }
    s += 2 * (r - 2) * (c - 2);
    return s;
}

int main()
{

    int H, W;

    cin >> H >> W;

    H += 2;
    W += 2;

    vector<vector<int>> A(H, vector<int>(W));

    for (int i = 1; i < H - 1; i++)
        for (int j = 1; j < W - 1; j++)
            cin >> A[i][j];

    int result = surfaceArea(A);

    cout << result << "\n";

    return 0;
}