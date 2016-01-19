#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>

using std::cout;
using std::endl;
using std::fstream;
using std::ios;
using std::string;
using std::ifstream;
using std::istringstream;
using std::vector;



int main (int argc, const char * argv[])
{
	//modified from http://linuxconfig.org/c-code-on-how-to-read-characters-from-a-file
	ifstream fin;
	fin.open("MSS_TestProblems-1.txt", ios::in);

	char my_character ;
	int numberElements = 0; //assumes that all the arrays contain at least 1 number

	string numberInput;
	int convertedNumber;

	vector <int> setOfNumbers;

	while (!fin.eof() ) 
	{

		fin.get(my_character);
		if (my_character == '-')
		{
			numberInput += '-';
		}

		if (my_character >= '0' && my_character <= '9')
		{
			numberInput += my_character;
			// cout << numberInput << " ";
		}

		if (my_character == ',' || my_character == ']')
		{
			numberElements++;
			//Taken from http://www.cplusplus.com/articles/D9j2Nwbp/#s2n
			if ( ! (istringstream(numberInput) >> convertedNumber) )
			{
				convertedNumber = 0;
			} 
				
			//add to vector
			setOfNumbers.push_back(convertedNumber);
			numberInput.clear();
		}

		if (my_character == ']')
		{
			for(std::vector<int>::iterator it = setOfNumbers.begin(); it != setOfNumbers.end(); ++it) {
			    std::cout << *it << " ";
			}
			setOfNumbers.clear();
			cout << "number of elements is: " << numberElements << endl;
			numberElements = 0;
		}
	
	}

}
