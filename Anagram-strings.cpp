#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool anagram = true;
    string s1 , s2;

    cin >> s1 >> s2;

    vector<int> count(26 , 0);

    for(char c : s1)
    {
        ++count[c-'a'];
    }

    for(char c : s2)
    {
        --count[c-'a'];
    }

    for(int i=0 ; i<26 ; i++)
        if(count[i] != 0)
        {
            anagram = false;
            break;
        }

    if(anagram)
        cout << s1 << " and " << s2 << " are anagrams";
    else
        cout << s1 << " and " << s2 << " are not anagrams";

    return 0;
}