#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<bool>> setPassengers(int numOfSeats) {
	vector<vector<bool>> seats(numOfSeats);
	for (auto i = 0; i < seats.size(); ++i) {
		string str;
		cin >> str;
		vector<bool> row(6);
		for (auto j = 0; j < str.size(); ++j) {
			switch (str[j]) {
			case '.':
				j < 3 ? row.at(j) = true : row.at(j - 1) = true;
				break;
			default:
				break;
			}
		}
		seats.at(i) = row;
	}
	return seats;
}

vector<string> split(const string& s, char delim) {
	vector<string> elems;
	stringstream ss;
	ss.str(s);
	string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

struct Group {
	int count;
	string direction; // left or right
	string place;     // aisle or window
	Group(int count, string direction, string place) : count(count), direction(direction), place(place) {}
};


string getSeats(vector<vector<bool>>& seats, string passengers) {
	vector<string> group = split(passengers, ' ');

	Group newGroup(stoi(group.at(0)), group.at(1), group.at(2));
	int start, end;

	if (newGroup.direction == "left") {
		if (newGroup.place == "window") {
			start = 0;
			end = newGroup.count;
		}
		else {
			start = 3 - newGroup.count;
			end = 3;
		}
	}
	else {
		if (newGroup.place == "window") {
			start = 6 - newGroup.count;
			end = 6;
		}
		else {
			start = 3;
			end = 3 + newGroup.count;
		}
	}

	for (int i = 0; i < seats.size(); i++) {
		bool ok = true;
		for (int j = start; j < end; j++) {
			if (!seats[i][j]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			string ans = "Passengers can take seats:";

			for (int j = start; j < end; j++) {
				seats[i][j] = false;
				ans = ans + " " + to_string(i + 1) + (char)(65 + j);
			}
			ans += "\n";
			for (int k = 0; k < seats.size(); ++k) {
				for (int j = 0; j < 6; ++j) {
					if (j >= start && j < end && k == i) ans += "X";
					else ans += seats[k][j] ? "." : "#";
					if (j == 2) ans += "_";
				}
				ans += "\n";
			}
			return ans;
		}
	}

	return "Cannot fulfill passengers requirements\n";
}

int main() {
	int num;
	cin >> num;
	vector<vector<bool>> pas = setPassengers(num);
	int m;
	cin >> m;
	string seat;
	cin.ignore(32767, '\n');
	for (int i = 0; i < m; ++i) {
		getline(cin, seat);
		cout << getSeats(pas, seat);
	}
}