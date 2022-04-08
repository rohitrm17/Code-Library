#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, flag = 0;
    cin >> n;

    for (int i=2; i<=n/2; i++)
    {
        if (n % i == 0)
        {
            cout << "Number is not Prime." << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "Number is Prime." << endl;
    return 0;
}