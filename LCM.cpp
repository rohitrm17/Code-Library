#include <bits/stdc++.h>

using namespace std;

int GCD(int a , int b)
{
    if(b == 0)
        return a;

    return GCD(b , a%b);
}

int main()
{
    int a , b;
    cin >> a >> b;
    
    int lcm = (a*b) / GCD(a , b);

    cout << "LCM: " << lcm << endl;
    return 0;
}