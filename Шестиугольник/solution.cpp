#include <iostream>
#include <vector>

using namespace std;

int main() {
	short n, m;
	cin >> n >> m;
	vector<vector<char>> field(n);

	for (short i = 0; i < n; ++i) {
		field.at(i) = vector<char>(m);
		for (short j = 0; j < m; ++j) {
			cin >> field.at(i).at(j);
		}
		reverse(field.at(i).begin(), field.at(i).end());
	}

	for (short j = 0; j < m; ++j) {
		for (short i = 0; i < n / 2; ++i) {
			swap(field.at(i).at(j), field.at(n - i - 1).at(j));
		}
	}

	for (short i = n - 1; i >= 0; --i) {
		for (short j = 0; j < m; ++j) {
			if (field.at(i).at(j) == '/' or field.at(i).at(j) == '\\') {
				field.at(i + 1).at(j) = field.at(i).at(j);
				field.at(i).at(j) = '.';
			}
		}
	}

	for (short i = 0; i < n; ++i) {
		for (short j = 0; j < m; ++j) {
			cout << field.at(i).at(j);
		}
		cout << endl;
	}
}