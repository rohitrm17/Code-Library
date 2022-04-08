#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;
    cin >> ch;
    cout << "Lower caase: " << (char)(ch|32) << endl;
    cout << "Upper case: " << (char)(ch&~32) << endl;
    return 0;
}