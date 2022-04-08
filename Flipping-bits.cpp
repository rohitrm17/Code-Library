#include <bits/stdc++.h>

using namespace std;

long flippingBits(long n) 
{
    long ans = UINT_MAX; // gives 1111111111111111111111111111111 = 4294967295
    ans = ans ^ n;
    return ans;
}

int main()
{
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;

        long result = flippingBits(n);

        cout << result << "\n";
    }

    return 0;
}
