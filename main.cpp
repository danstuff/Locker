#include "main.h"

void xorencrypt(string filename, string key){
	//add all of file to a string
	fstream file(filename, ios::in);

	string unencrypted = "";
	string line = "";

	while(!file.eof()){
		getline(file, line);
		unencrypted += line;
	}
	
	file.close();

	//encrypt the file
	string encrypted = "";

	for(uint i = 0; i < unencrypted.length(); i++){
		encrypted += unencrypted.at(i) ^ key.at(i%key.length());
	}

	//replace file with encrypted data
	file.open(filename, ios::out);

	file << encrypted;

	file.close();
}

int main(){
	for(uint i = 0; i < 36; i++)
		cout << char(219);
	cout << " LOCKER ";
	for(uint i = 0; i < 36; i++)
		cout << char(219);

	cout << "Enter Key:" << endl;
	cout << "> ";

	string key;

	cin >> key;

	xorencrypt("locker.txt", key);

	return 0;
}