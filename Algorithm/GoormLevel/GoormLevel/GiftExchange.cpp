#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	int tCount;
	long long m, n, k;
	int output[10000];

	cin >> tCount;
	for (int i = 0; i < tCount; i++) {
		cin >> n >> m;
		k = n / 5 < (n + m) / 12 ? n / 5 : (n + m) / 12;

		while (n + m < 12 * k) {
			if (k == 0)break;
			k--;
		}
		output[i] = (int)k;
	}
	for (int i = 0; i < tCount; i++) {
		cout << output[i];
	}
	return 0;
}