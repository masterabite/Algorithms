#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define ull unsigned long long

ull a[100000];
ull pw[64], temp;
ull realAns = 0;
int n;

bool cmp(ull n1, ull n2) {
	return n1 > n2;
}

void bitPrint(ull n) {
	for (int i = 32; i >= 0; --i) {
		if (n >= pw[i]) {
			cout << 1;
			n -= pw[i];
		} else cout << 0;
	}
	cout << '\n';
}

void rec(int pos, ull xr) {
	realAns = max(xr, realAns);
	if (pos >= n) return;
	rec(pos + 1, xr ^ a[pos]);
	rec(pos + 1, xr);
}

int main()
{
	pw[0] = 1;
	for (int i = 1; i < 64; ++i) {
		pw[i] = pw[i - 1] * 2;
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	rec(0, 0);
	
	for (int i = 0; i < n; ++i) {
		bitPrint(a[i]);
	}

	unsigned long long ans = 0;
	int k = 63;
	for (int j = 63; j >= 0; --j) {
		int i = 0;
		for (; i < n && a[i] < pw[j]; ++i);
		ans = max(ans, ans ^ a[i]);
		for (int i2 = i+1; i2 < n; ++i2) {
			if (a[i2] >= pw[j]) a[i2] ^= a[i];
		}
		a[i] = 0;

	}
	cout << "answer: ";
	cout << ans << '\n';
	bitPrint(ans);
	
	cout << "real answer: ";
	cout << realAns << '\n';
	bitPrint(realAns);
	return 0;
}
