// C++ Program			Lab 11.cpp
// Course				CSE1311/W01
// Name:				Hakeem Wilson
// Assignment #:		Lab 11 
// Due Date:			04/21/2019

/*  The purpose of this program is to use two-dimensional arrays,
	input a set of values in from those arrays,
	create a square of data in size n*n,
	then determine if it is a magic square.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//Global Declarations
int n;
int box[10][10];

//Loop Function to read data from the file.
void readdata(ifstream& fin, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> box[i][j];
		}
	}
}

//Function to print the 2-D arrays in square format.
void print(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << box[i][j] << "\t";
		}
		cout << endl;
	}
}

//Function to summm the rows of the square
int sumRow(int row, int n)
{
	int sum = 0;
	for (int j = 0; j < n; j++)
	{
		sum += box[row][j];
	}
	return sum;
}

//Function to sum the columns of the square
int sumCol(int col, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += box[i][col];
	}
	return sum;
}

//Function to sum the main daignol list of values
int mainDiag(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += box[i][i];
	}
	return sum;
}

//Function to sum the reverse daignol list of values
int revDiag(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += box[i][n - i - 1];
	}
	return sum;
}

//Logic to determine if the square is magic or not.
bool isMagic(int i, int n)		// use reverse logic 
{
	int sum = sumRow(i,n);
	if (mainDiag(n) != revDiag(n))
	{
		return false;
	}
	if (sumCol(i,n) != sum) {
		return false;
	}
	if (sumRow(i,n) != sum || sumCol(i, n) != sum) 
	{
		return false;
	}
	return true;
}

int main()
{
	ifstream fin("data.txt");
	
	int k = 1;
	fin >> n;
	while (n != -1)
	{
		
		int i, j;
		readdata(fin, n);
		cout << "============" << endl;
		cout << "= Square " << k++ << " =" << endl;
		cout << "============" << endl;
		print(n);

		for (i = 0; i < n; i++)
		{
			cout << "The sum of row " << i << " is " << sumRow(i,n) << endl;
		}

		for (i = 0; i < n; i++)
		{
			cout << "The sum of column " << i << " is " << sumCol(i,n) << endl;
		}

		cout << "The main diagonal is " << mainDiag(n) << endl;
		cout << "The other diagonal is " << revDiag(n) << endl;

		if (isMagic(i,n))
		{
			cout << "This matrix is a magic box!" << endl;
		}
		else
		{
			cout << "This matrix is not a magic box!" << endl;
		}
		fin >> n;
	}
	fin.close();
	cout << endl;
	cout << "This was coded by Hakeem Wilson" << endl;
	system("PAUSE");
	return 0;
}