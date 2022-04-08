#include <bits/stdc++.h>

using namespace std;

string timeInWords(int h, int m)
{
    string tiw = "";
    int r;
    string a[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    if (m == 0)
        tiw = a[h - 1] + " o' clock";
    else if (m == 1)
        tiw = a[m - 1] + " minute past " + a[h - 1];
    else if (m == 15)
        tiw = "quarter past " + a[h - 1];
    else if (m == 30)
        tiw = "half past " + a[h - 1];
    else if (m > 20 && m < 30)
        tiw = a[19] + " " + a[m - 21] + " minutes past " + a[h - 1];
    else if (m < 30)
        tiw = a[m - 1] + " minutes past " + a[h - 1];
    else if (m > 30)
    {
        r = 60 - m;
        if (r == 15)
            tiw = "quarter to " + a[h];
        else if (r == 1)
            tiw = a[r - 1] + " minute to " + a[h];
        else if (r > 1 && r <= 20)
            tiw = a[r - 1] + " minutes to " + a[h];
        else if (r > 20 && r < 30)
            tiw = a[19] + " " + a[r - 21] + " minutes to " + a[h];
    }
    return tiw;
}

int main()
{
    int h, m;

    cin >> h >> m;

    string result = timeInWords(h, m);

    cout << result << "\n";

    return 0;
}
