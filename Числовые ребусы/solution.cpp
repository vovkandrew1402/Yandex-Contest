#include <iostream>
#include <cmath>

using namespace std;

int main() {
	short n;
	cin >> n;
	int res = 0;
	for (short i = 0; i < n; ++i) {
		int letter;
		cin >> letter;
		int code = 97 + log2(abs(letter - res));
		cout << (code != 123 ? static_cast<char>(code) : ' ');
		res = letter;
	}
}