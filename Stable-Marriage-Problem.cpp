#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second

using namespace std;

int f[555][555], m[555][555];
pair<int, int> fl[555][555], ml[555][555];
int x[555], y[555], bx[555];
int n;

void readin(pair<int, int> a[555][555], int b[555][555]) {
	for (int i=0; i<n; i++) {
		scanf("%*d");
		for (int j=0; j<n; j++) {
			int p;
			scanf("%d", &p);p--;
			a[i][j] = mp(j, p);
			b[i][p] = j;
		}
		sort(a[i], a[i]+n);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int ti=0; ti<t; ti++) {
		scanf("%d", &n);
		readin(ml, m);
		readin(fl, f);
		memset(x, -1, sizeof(x));
		memset(y, -1, sizeof(y));
		memset(bx, 0, sizeof(bx));
		for (int k=0; k<n; k++) {
			for (int i=0; i<n; i++) {
				if (x[i] != -1) continue;
				for (int g=0; g<n; g++) {
					int j = fl[i][g].s;
					if (y[j] == -1 || (m[j][i] < m[j][y[j]])) {
						if (y[j] != -1) {
							x[y[j]] = -1;
						}
						x[i] = j;
						y[j] = i;
						break;
					}
				}
			}
		}
		for (int i=0; i<n; i++) {
			printf("%d %d\n", i+1, x[i]+1);
		}
	}
	return 0;
}