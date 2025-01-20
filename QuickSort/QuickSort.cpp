// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

ifstream validateFile(const string &filename) {
	ifstream file;
	file.open(filename);
	if (file) {
		return file;
	}
	else {
		return ifstream ();
	}
}

int main(int argc, char *argv[])
{

	if (argc < 2) {
		cout << "File not specified! Please specify a csv file to sort";
		return 0;
	}

	string fileName = argv[1];
	ifstream file;
	file.open(fileName);

	if (!file) {
		cout << "File does not exist!";
		return 0;
	}

	if ( !(fileName.substr(fileName.find_last_of(".") + 1) == "csv") ) {
		cout << "File is not csv!";
		return 0;
	}

	//fs::path cwd = fs::current_path();
	//cout << cwd;

	//file.open("bingozing.txt", ios::out);

	//if (file.is_open()) {
	//	file << "yo";
	//	file.close();
	//}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
