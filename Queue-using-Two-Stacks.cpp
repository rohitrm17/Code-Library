#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    int type, x;
    stack<int> a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        switch (type)
        {
        case 1:
        {
            cin >> x;
            a.push(x);
        }
        break;
        case 2:
        {
            if (b.empty())
                while (!a.empty())
                {
                    b.push(a.top());
                    a.pop();
                }
            b.pop();
        }
        break;
        case 3:
        {
            if (b.empty())
                while (!a.empty())
                {
                    b.push(a.top());
                    a.pop();
                }
            cout << b.top() << "\n";
        }
        break;
        }
    }
    return 0;
}
