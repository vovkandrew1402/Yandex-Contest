#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOp(int numberOfVessels, vector<int> volumeOfAcid) {

	for (auto it = volumeOfAcid.begin(); it != volumeOfAcid.end() - 1; ++it) {
		if (*it > *(it + 1)) return -1;
	}

	auto pairminmax = minmax_element(volumeOfAcid.begin(), volumeOfAcid.end());
	return *pairminmax.second - *pairminmax.first;
}

	int main() 
	{
		int n;
		cin >> n;
		vector<int> k(n);
		size_t num;
		for (size_t i = 0; i < n; ++i) {
			cin >> num;
			k.at(i) = num;
		}
		cout << countOp(n, k) << endl;
		return 0;
	}