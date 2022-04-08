#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool checkAnagram(string a, string b)
{
    vector<int> ar(26, 0), br(26, 0);

    for (int i = 0, n = a.size(); i < n; i++)
        ar[a[i] - 'a']++;

    for (int i = 0, n = b.size(); i < n; i++)
        br[b[i] - 'a']++;

    for (int i = 0; i < 26; i++)
    {
        cout << ar[i] << " ";
        if (ar[i] != br[i])
            return false;
    }

    return true;
}

int sherlockAndAnagrams(string s)
{

    int count = 0;
    string s1;
    map<string, int> mp;
    int n = s.size();

    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            s1 = s.substr(i, len);
            sort(s1.begin(), s1.end());
            mp[s1]++;
        }
    }

    for (auto t : mp)
    {
        count = count + (t.second * (t.second - 1)) / 2;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
