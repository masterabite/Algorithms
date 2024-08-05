#include <iostream>
#include <string>

using namespace std;

long long p[100001];
const long long m = 10000007;
const long long k = 7;

long long getHash(string str) {
	long long res = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		res += p[str.size() - i] * str[i];
	}
	return res % m;
}

int main()
{
	string str;
	string subStr;

	getline(cin, str);
	getline(cin, subStr);

	int len = str.size();
	int subLen = subStr.size();

	p[0] = 1;
	for (int i = 1; i <= subLen; ++i) {
		p[i] = (p[i - 1] * k) % m;
	}

	long long subHash = getHash(subStr);
	long long hash = getHash(str.substr(0, subLen));

	bool check = false;

	for (int i = 0; i <= len - subLen; ++i) {
		if (hash == subHash && str.substr(i, subLen) == subStr) {
			check = true;
			cout << i << '\n';
		}
		if (p[subLen] * str[i] > hash) {
			hash += (p[subLen] * str[i] / m) * (m*k);
		}
		hash -= p[subLen] * str[i];
		hash += str[i + subLen];
		hash *= k;
		hash %= m;
	}
	if (!check) cout << -1;
	return 0;
}
