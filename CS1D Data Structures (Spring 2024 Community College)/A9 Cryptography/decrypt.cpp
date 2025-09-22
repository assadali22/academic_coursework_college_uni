#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;
	ofstream fout;
	string line;
	char c;
	int asciiNum;

	cout << "Attempting to decrypt text file, right shift by 5 to get original text. (caesar cipher)" << endl;
	if (argc < 2)
	{
		cout << "Please provide a input text file that is encrypted." << endl;
		return -1;
	}

	string fileName = argv[1];
	fin.open(fileName);
	fout.open("decrypted.txt");

	while (fin)
	{
		getline(fin, line); //'\n' at the end automatically discarded

		for (size_t i = 0; i < line.length(); i++)
		{
			c = line[i];
			asciiNum = ((int) (c) - 5) % 128;
			fout << (char) asciiNum;
		}

		fout << endl; //new line on output file
		line.erase();
	}

	cout << "Decryption done." << endl;
	fin.close();
	fout.close(); //forgot to close the files
	return 0;
}
