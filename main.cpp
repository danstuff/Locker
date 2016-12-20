#include "main.h"

string xorencrypt(string filein, string fileout, string key, bool delete_in) {
	//add all of file to a string
	fstream file;
	file.open(filein.c_str(), ios::in);

	if (!file.is_open()) {
		cout << "[ERROR] File not found: please add \"" << filein
				<< "\" to continue" << endl;
	}

	string unencrypted = "";
	string line = "";

	while (!file.eof()) {
		getline(file, line);
		unencrypted += line;
	}

	file.close();

	if(delete_in){
		remove(filein.c_str());
	}

	//encrypt the file
	string encrypted = "";

	for (uint i = 0; i < unencrypted.length(); i++) {
		encrypted += unencrypted.at(i) ^ key.at(i % key.length());
	}

	//replace out file with encrypted data
	fstream fout;
	fout.open(fileout.c_str(), ios::out);

	if (!fout.is_open()) {
		cout << "[ERROR] File not found: please add \"" << fileout
				<< "\" to continue" << endl;
	}

	fout << encrypted;

	fout.close();

	return encrypted;
}

int main() {
	for (uint i = 0; i < 36; i++)
		cout << char(219);

	cout << " LOCKER ";

	for (uint i = 0; i < 36; i++)
		cout << char(219);

	while (true) {
		cout << endl;

		cout << ">";

		string command;
		cin >> command;

		if (command == "lock") {
			cout << "Enter Key:";

			string key;
			cin >> key;

			xorencrypt("unlock.txt", "locker.dat", key, true);
			cout << "File locked using key \"" << key << "\"" << endl;
		} else if (command == "unlock") {
			cout << "Enter Key:";

			string key;
			cin >> key;

			cout << xorencrypt("locker.dat", "unlock.txt", key, false) << endl;
			cout << "File unlocked using key \"" << key << "\"" << endl;
		} else if (command == "quit") {
			return 0;
		}else{
			cout << "Invalid command \"" << command << ".\" Valid commands are \"lock,\" \"unlock,\" and \"quit.\"" << endl;
		}
	}
}
