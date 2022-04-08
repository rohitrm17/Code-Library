#include <bits/stdc++.h>

using namespace std;

void extraLongFactorials(int n)
{
    vector<int> ans;
    int carry = 0, p, j;
    ans.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        for (int k = 0; k < ans.size(); k++)
        {
            p = ans[k] * i + carry;
            ans[k] =  p % 10;
            carry = p / 10;
        }
        while (carry != 0)
        {
            ans.push_back(0);
            ans[ans.size() - 1] = carry % 10;
            carry /= 10;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}

int main()
{
    int n;
    cin >> n;

    extraLongFactorials(n);

    return 0;
}