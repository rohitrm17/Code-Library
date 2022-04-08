#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n , char a , char aux , char b)
{
    if(n == 0)
        return ;
    towerOfHanoi(n-1 , a , b , aux);
    cout << "Move from " << a << " to " << b << "\n";
    towerOfHanoi(n-1 , aux , a , b);    
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n , 'A' , 'B' , 'C');
    return 0;
}