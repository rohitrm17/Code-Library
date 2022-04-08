#include <bits/stdc++.h>

using namespace std;

string pangrams(string s)
{
    vector<int> a(27);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]>='A' && s[i]<='Z')
            a[(s[i] - 'A')]++;
        else if (s[i] != ' ')
            a[(s[i] - 'a')]++;
    }

    for (int i = 0; i < 26; i++)
        if (a[i] == 0)
            return "not pangram";

    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
