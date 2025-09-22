#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	ofstream outData;
	stack<int> forwardButton;
	stack<int> backwardButton;
	int newPage = 0;
	int currentPage = 0;

	fin.open("browser.txt");
	outData.open("browserOutput.txt");

	//Begin with start page 0000
	outData << "0000 - start page" << endl;

	while (fin) //continue reading from input file until we reach the end
	{
		fin >> newPage;
		if (newPage == 9999 && backwardButton.empty())
		{
			outData << newPage << " - backward stack empty" << endl;
		}
		else if (newPage == 9998 && forwardButton.empty())
		{
			outData << newPage << " - forward stack empty" << endl;
		}
		else
		{
			//get in this else block if forward or backward button is not empty
			if (newPage == 9999)
			{
				//cout << "backward" << endl;
				//go backward
				forwardButton.push(currentPage);
				currentPage = backwardButton.top();
				backwardButton.pop();
				outData << newPage << " - " << currentPage << endl;
			}
			else if (newPage == 9998)
			{
				//go forward
				backwardButton.push(currentPage);
				currentPage = forwardButton.top();
				forwardButton.pop();
				outData << newPage << " - " << currentPage << endl;
			}
			else
			{
				//visit a page
				backwardButton.push(currentPage);
				currentPage = newPage;
				//clear out forward button stack
				for (size_t i = 0; i < forwardButton.size(); i++)
				{
					forwardButton.pop();
				}
				outData << newPage << " - " << currentPage << endl;
			}
		}

	} //end while


	cout << "output stream bad? " << boolalpha << outData.bad() << endl;
	fin.close();
	outData.close();
	return 0;
}
