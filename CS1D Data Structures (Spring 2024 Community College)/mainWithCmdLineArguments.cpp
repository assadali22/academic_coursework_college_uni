//This program implements sorting algorithms from the Intro to Algorithms Textbook from Cormen (MIT Press)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


//Function Prototypes
//void printArr(int* arr, int s);
int countElements(string name);
void readNums(int* array, string fileName);
void insertionSort(int* arr, int arrSize);
void bubbleSort(int* arr, int arrSize);

//Merge sort functions
void mergeSort(int* arr, int startIndex, int endIndex);
void mergeArrs(int* arr, int p, int q, int r);

//Heap sort functions
void heapSort(int* arr, int s);
void buildMaxHeap(int* arr, int n);
void maxHeapify(int* arr, int i, int heapSize);

//Quick Sort
void quickSort(int* arr, int start, int endIndex);
int partitionArr(int* arr, int p, int r);

//Counting Sort
int* countingSort(int* arr, int n);
int getLargest(int* arr, int n);

int main(int argc, char *argv[])
{
	//open file for counting, get num elements and make the dynamic array
	//open the file again and populate the array
	//any file I/O issue exits the program with a -1
	string fileName = argv[1]; //Source of text file is passed in with command line
	int userSize = countElements(fileName);

	int* arrInts;
	arrInts = new int[userSize];
	readNums(arrInts, fileName); //read the integers

	cout << "array size = " << userSize << endl;
	//cout << "Initial array: " << endl;
	//printArr(arrInts, userSize);

	//To get the sort code, use atoi() function in cstdlib
	//convert the cstring to a number. argv[2] has the sort code
	int sortCode = atoi(argv[2]);
	switch (sortCode)
	{
		case 0:
		{
			//Insertion Sort (works correctly, completed)
			cout << "Executing insertion sort." << endl;
			insertionSort(arrInts, userSize);
			break;
		}

		case 1:
		{
			//Merge Sort (works correctly, completed)
			cout << "Executing merge sort." << endl;
			mergeSort(arrInts, 0, userSize - 1);
			break;
		}

		case 2:
		{
			//Bubble sort (works correctly, even for 20 numbers!)
			cout << "Executing bubble sort." << endl;
			bubbleSort(arrInts, userSize);
			break;
		}

		case 3:
		{
			//Heap sort (works correctly, completed)
			cout << "Executing heap sort." << endl;
			heapSort(arrInts, userSize - 1); //subtract 1 from array size, very important
			break;
		}

		case 4:
		{
			//Quick sort (works correctly, completed)
			cout << "Executing quick sort." << endl;
			quickSort(arrInts, 0, userSize - 1);

			break;
		}

		case 5:
		{
			//Counting sort (works for 10 and 20 numbers, works correctly)
			cout << "Executing counting sort." << endl;
			int *b;
			b = countingSort(arrInts, userSize);
			//cout << "Sorted array: " << endl;
			//printArr(b, userSize);
			delete [] b;
			break;
		}

		case 6:
		{
			//Radix sort (was unable to do)
			cout << "radix sort" << endl;
			//int *x = radixSort(arrInts, userSize);


			break;
		}


		default:
		{
			cout << "Invalid input..." << endl;
		}

	}
	//end switch
	cout << endl;
	//cout << "Sorted array: " << endl;
	//printArr(arrInts, userSize);

	cout << "Program finished sorting." << endl;
	delete [] arrInts;
	cout << "Array deallocated..." << endl << endl;
	return 0;
}


/*
void printArr(int* arr, int s)
{
	//use only for the test file for 10 or 20 elements
	//to confirm array is sorted correctly
	int i = 0;
	cout << "<";
	for (i = 0; i < s; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << ">" << endl;
}
*/


int countElements(string name)
{
	int count = 0;
	int num;
	ifstream fin;
	fin.open(name);
	if (!fin)
	{
		cout << "Failed to read the file." << endl;
		exit(-1);
	}

	while (fin >> num)
	{
		count++;
	}
	//the while (!fin.eof()) doesn't work here in linux command line, it causes the size
	//to be one more than it actually is. use fin >> num as the condition
	//to read the numbers and avoid the blank line that is forced at the end of the txt file

	fin.close();
	return count;
}


void readNums(int* array, string fileName)
{
	ifstream fin;
	int num;
	fin.open(fileName);
	if (!fin)
	{
		cout << "Failed to read the file." << endl;
		exit(-1);
	}

	int i = 0;
	while (fin >> num) //this condition will properly read in the numbers
	{
		array[i] = num;
		i++;
	}
	//while(!fin.eof()) does not work in linux command line, it reads in the last number twice
	//there is an extra blank line on the bottom of txt file on linux
	//and .eof() won't work properly.
	fin.close();
}



//Counting sort
int* countingSort(int* arr, int n)
{
	int* b;
	int* c;
	int k = getLargest(arr, n);

	b = new int[n];
	c = new int[k + 1]; //array size is k + 1
	//represent numbers up to the max value in original array (for 0-1000, size is 1001)
	//if the largest number is 1000 for example

	//1st for loop
	int i;
	int j;
	for (i = 0; i < k + 1; i++) //line 2 (initialize array with 0's), i < k + 1 is the correct condition
	{
		c[i] = 0; //line 3
	}

	//2nd for loop
	for (j = 0; j < n; j++) //line #4 for textbook pseudocode
	{
		c[arr[j]] = c[arr[j]] + 1;
	}
	//C[i] now contains number of elements equal to i

	//3rd for loop
	for (i = 0; i < k + 1; i++) //lines 7-8
	{
		c[i] = c[i] + c[i - 1];
	}
	//C[i] now contains number of elements less than or equal to i


	//4th for loop
	for (j = n - 1; j >= 0; j--) //lines 11-13
	{
		b[c[arr[j]] - 1] = arr[j]; //c[arr[j]] - 1 is SUPER important
		c[arr[j]] = c[arr[j]] - 1; //handle duplicates
	}

	delete [] c;
	return b;

}

int getLargest(int* arr, int n)
{
	int large = arr[0];
	int p;

	for (p = 1; p < n; p++)
	{
		if (arr[p] > large)
		{
			large = arr[p];
		}
	}

	return large;
}



void insertionSort(int* arr, int arrSize)
{
	int i = 0;
	int j = 0;
	int key = 0;

	for (i = 1; i < arrSize; i++)
	{
		key = arr[i];
		//insert arr[i] into sorted subarray
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}


void bubbleSort(int* arr, int arrSize)
{
	int temp;
	int j;
	for (j = 1; j < arrSize; j++)
	{
		for (int index = 0; index < arrSize - j; index++)
		{
			if (arr[index] > arr[index + 1])
			{
				temp = arr[index];
				arr[index] = arr[index + 1];
				arr[index + 1] = temp;
			}
		}
	}//end of outer loop

}


void heapSort(int* arr, int s)
{
	buildMaxHeap(arr, s);
	int temp;
	int i;
	for (i = s; i >= 0; i--) //>= 0 for first element of array, size - 1 gives last element
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		s--;

		maxHeapify(arr, 0, s);
	}
}


void buildMaxHeap(int* arr, int n)
{
	int size = n;
	int i;

	for (i = n / 2; i >= 0; i--)
	{
		maxHeapify(arr, i, size);
	}
}


void maxHeapify(int* arr, int i, int heapSize)
{
	int tempSwap;
	int largest;
	int left = 2 * i;
	int right = (2 * i) + 1;

	if (left <= heapSize && arr[left] > arr[i])
	{
		largest = left;
	}
	else
	{
		largest = i;
	}

	if (right <= heapSize && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		tempSwap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tempSwap;

		maxHeapify(arr, largest, heapSize);
	}

}



void mergeSort(int* arr, int startIndex, int endIndex)
{
	//start index is p
	//end index is r
	if (startIndex >= endIndex)
	{
		return;
	}

	int midpoint; //or q from algorithms textbook pseudocode
	midpoint = (startIndex + endIndex) / 2;

	mergeSort(arr, startIndex, midpoint); //recursively sort start of array to midpoint
	mergeSort(arr, midpoint + 1, endIndex); //recursively sort from midpoint to end
	mergeArrs(arr, startIndex, midpoint, endIndex);	//merge subarrays together

}


void mergeArrs(int* arr, int p, int q, int r)
{
	int lenLeftHalf = q - p + 1; //length of left half of subarray [N(L) in textbook]
	int lenRightHalf = r - q; //length of right half of the subarray [N(R) in textbook]

	int* leftArr;
	int* rightArr;

	leftArr = new int[lenLeftHalf];
	rightArr = new int[lenRightHalf];

	int i, j;

	for (i = 0; i < lenLeftHalf; i++)
	{
		leftArr[i] = arr[p + i]; //copy first half of array into new left half array
	}

	for (j = 0; j < lenRightHalf; j++)
	{
		rightArr[j] = arr[q + j + 1]; //copy 2nd half of array into new right half array
	}

	//As long as each of the array L and R have an unmerged element,
	//copy smallest unmerged element back into A[p:r]

	i = 0;
	j = 0;
	int k = p;

	while (i < lenLeftHalf && j < lenRightHalf)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}

		k++;
	}

	//After going through one of L and R entirely, copy
	//remainder of the other to the end of A[p:r]

	while (i < lenLeftHalf)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < lenRightHalf)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}

	delete [] leftArr;
	delete [] rightArr;

}

void quickSort(int* arr, int start, int endIndex)
{
	int q;
	if (start < endIndex)
	{
		q = partitionArr(arr, start, endIndex);
		quickSort(arr, start, q - 1);
		quickSort(arr, q + 1, endIndex);
	}
}


int partitionArr(int* arr, int p, int r)
{
	int pivot = arr[r];
	int i = p - 1; //highest index on low side
	int j;
	int temp;

	for (j = p; j < r; j++)
	{
		if (arr[j] <= pivot) //does this element belong on low side
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//end of for loop

	//move pivot just to the right of low side
	temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;

	return i + 1;

}
