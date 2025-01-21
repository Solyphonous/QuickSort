#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> parse_csv(const string& input) {
	vector<int> result;
	stringstream ss(input);

	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		result.push_back(stoi(substr));
	}
	return result;
}

void quick_sort(vector<int> &values, int start, int end) {
	if (start >= end) {
		return;
	}

	int swap = start - 1;
	const int pivot_index = end;

	for (int i = start; i <= end; i++) {
		if (values[i] <= values[pivot_index]) {
			swap++;

			if (i > swap) {
				int temp = values[swap];
				values[swap] = values[i];
				values[i] = temp;
			}
		}
	}

	quick_sort(values, start, swap - 1);
	quick_sort(values, swap + 1, end);

}

int main(int argc, char *argv[])
{

	if (argc < 2) {
		cout << "File not specified! Please specify a csv file to sort";
		return 0;
	}

	string fileName = argv[1];
	ifstream file(fileName);

	if (!file) {
		cout << "File does not exist!";
		return 0;
	}

	if ( !(fileName.substr(fileName.find_last_of(".") + 1) == "csv") ) {
		cout << "File is not a csv!";
		return 0;
	}

	string contents;
	file >> contents;

	vector<int> values = parse_csv(contents);

	quick_sort(values, 0, values.size()-1);

	for (int i = 0; i < values.size(); i++) {
		cout << values[i] << ',';
	}

	return 0;
}