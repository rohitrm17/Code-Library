#include <bits/stdc++.h>

using namespace std;

void subseq(string s , string ans)
{
    if(s.length() == 0)
    {
        cout << ans << "\n";
        return ;
    }

    char ch = s[0];
    string a = s.substr(1);
    subseq(a , ans);
    subseq(a , ans+ch);
}

int main()
{
    string s;
    cin >> s;
    subseq(s , "");
    return 0;
}