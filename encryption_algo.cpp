#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class encdec {
	int key;
	string file = "data.txt";
	char c;
	public:
	void encrypt();
	void decrypt();
};

void encdec::encrypt()
{	
	cout << "key: ";
	cin >> key;
	// Input stream
	fstream fin, fout;
	// Open input file
	// ios::binary- reading file
	// character by character
	fin.open("data.txt", fstream::in);
	fout.open("encrypt.txt", fstream::out);

	// Reading original file till
	// end of file
	while (fin >> noskipws >> c) {
		int temp = (c + key);
		// Write temp as char in
		// output file
		fout << (char)temp;
	}
	// Closing both files
	fin.close();
	fout.close();
}

// Definition of decryption function
void encdec::decrypt()
{
	cout << "key: ";
	cin >> key;
	fstream fin;
	fstream fout;
	fin.open("encrypt.txt", fstream::in);
	fout.open("decrypt.txt", fstream::out);

	while (fin >> noskipws >> c) {

		// Remove the key from the
		// character
		int temp = (c - key);
		fout << (char)temp;
	}

	fin.close();
	fout.close();
}

// Driver Code
int main()
{
	encdec enc;
	char c;
	cout << "\n";
	int choice = 0;
	do{
		cout << "Enter Your Choice : -> \n";
		cout << "1. encrypt \n";
		cout << "2. decrypt \n";
		cout << "Press any key to exit \n";
		cin >> c;
		cin.ignore();
		choice = (c == '1' || c == '2') ? 1 : 0;
		switch (c) {
			case '1': {
				enc.encrypt();
				break;
			}
			case '2': {
				enc.decrypt();
				break;
			}
			default: {
				break;
			}
		}
	}while(choice);
}

