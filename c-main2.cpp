#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	string t;
	string c;
	vector<string> letter;
	vector<string> food;
	vector<string> type;
	vector<string> count1;
	vector<string> count2;

	ifstream inFS("ExampleFile.csv");
	if(!inFS.is_open()) {
		cout << "Error opening file for reading in" << endl;
		return 1;
	}

	while (getline(inFS,t)) {

		stringstream s(t);

		getline(s, c, ',');
		letter.push_back(c);
		getline(s, c, ',');
		food.push_back(c);
		getline(s, c, ',');
		type.push_back(c);
		getline(s, c, ',');
		count1.push_back(c);
		getline(s, c, ',');
		count2.push_back(c);
	}

	inFS.close();

	for (int i = 0; i < letter.size(); ++i) {
		cout << letter.at(i) << " " << food.at(i) << " " << type.at(i) << " " << count1.at(i) << " " << count2.at(i) << endl;
	}

	ofstream outFS("ExampleFile.csv");
	if(!outFS.is_open()) {
		cout << "Error opening file for reading out" << endl;
	}
	
	cout << "Enter letter to exchange" << endl;

	cin >> c;

	for (int i = 0; i < letter.size(); ++i) {
		if (c == letter.at(i)) {
		//	cout << i << " " << letter.at(i) << " " << food.at(i) << " " << type.at(i) << endl;
			cin >> food.at(i);
			cin >> type.at(i);
			cin >> count1.at(i);
			cin >> count2.at(i);			
			break;
		}
	}	

//	for (int i = 0; i < letter.size(); ++i) {
//		cout << letter.at(i) << " " << food.at(i) << " " << type.at(i) << " " << count1.at(i) << " " << count2.at(i) << endl;
//	}

	for (int i = 0; i < letter.size(); ++i) {
		outFS << letter.at(i) << "," << food.at(i) << "," << type.at(i) << "," << count1.at(i) << "," << count2.at(i) << endl;
	}

	outFS.close();

	return 0;
}
