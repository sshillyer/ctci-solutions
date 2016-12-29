// Write a method to replace all spaces in a string with'%20'. You may assume that
// the string has sufficient space at the end of the string to hold the additional
// characters, and that you are given the "true" length of the string. (Note: if implementing
// in Java, please use a character array so that you can perform this operation
// in place.)
// EXAMPLE
// Input: "Mr John Smith
// Output: "Mr%20Dohn%20Smith"

#include <iostream>
#include <cstring>
// using namespace std;

void replaceSpaces(char * str, int len);
int numSpaces(char * str);

int main(int argc, char const *argv[])
{
	char str[] = "Hello World\0\0\0\0\0\0\0\0\0\0\0\0";
	int strLen = std::strlen(str);
	std::cout << str << std::endl;
	std::cout << strLen << std::endl;

	replaceSpaces(str, strLen);
	std::cout << str << std::endl;
	std::cout << strLen << std::endl;


	return 0;
}


void replaceSpaces(char * str, int len) {
	int newIdx = len + (numSpaces(str) * 2);
	str[--newIdx] = '\0';
	// for each character in the original string, starting at the end
	for (int origIdx = len - 1; origIdx >= 0; origIdx--) {
		if (str[origIdx] == ' ') {
			// if space, replace with %20
			str[newIdx] = '0';
			str[newIdx - 1] = '2';
			str[newIdx - 2] = '%';
			newIdx = newIdx - 3;
		} 
		else {
			// otherwise copy the character over
			str[newIdx] = str[origIdx];
			newIdx--;
		}
	}

	return;
}

int numSpaces(char * str) {
	int strLen = std::strlen(str);
	int numSpaces = 0;

	for (int i = 0; i < strLen; i++) {
		if (str[i] == ' ') {
			numSpaces++;
		}
	}
	std::cout << "Spaces: " << numSpaces << "  (" << str << ")" << std::endl;
	return numSpaces;
}