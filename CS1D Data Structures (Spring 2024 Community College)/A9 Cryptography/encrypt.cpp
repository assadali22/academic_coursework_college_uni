#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	ifstream inFile;
	ofstream outFile;
	string sentence;
	char character;
	int asciiCode;
	//can hardcode the number to shift the characters
	//command line argument to take 1 file (file name is in index 1)
	cout << "Encrypting text file for ceaser cipher, left shift by 5 (A becomes F)" << endl;
	if (argc < 2)
	{
		cout << "Please provide 1 input text file, one argument maximum." << endl;
		return -1;
	}

	string fileName = argv[1];
	inFile.open(fileName);
	outFile.open("encrypted.txt");

	//should be able to encrypt a \n and a blank line containing \n
	while (inFile)
	{
		getline(inFile, sentence); //getline actually discards the \n, next line is ready to be read
		//cout << sentence << endl; //debug with sample text file
		//cout << sentence.length() << endl; //debug with sample text file

		for (size_t i = 0; i < sentence.length(); i++)
		{
			character = sentence[i];
			asciiCode = ((int) (character) + 5) % 128;
			outFile << (char) asciiCode;
		}

		//outFile << (int) ('\n' + 5) % 128; //THIS LINE IS WRONG

		//inFile.ignore(100, '\n'); //caused problems
		outFile << endl;
		sentence.erase();
	}

	cout << "Encrpytion done." << endl;
	inFile.close();
	outFile.close();
	return 0;
}

