/* Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string. */

#include <iostream>
#include <cstring>
#include <string.h>

std::string compressString(std::string str);
std::string buildCompressedStringFromArray(int * chars);



int main(int argc, char const *argv[]) {
	
	std::string test = "This is a test of the tester system. Zork willy!";
	
	std::string result = compressString(test);

	std::cout << result << std::endl;

	return 0;
}


std::string compressString(std::string str) {
	int chars[256] =  { };
	int uncompressedLength = str.length();

	// Count the characters - assumes ASCII
	for (int i = 0 ; i < str.length(); i++) {
		chars[(int) str[i]]++; // increase count of letter
	}

	return buildCompressedStringFromArray(chars);
} 


std::string buildCompressedStringFromArray(int * chars) {
	std::string result = "";

	for (int i = 0; i < 256; i++) {
		// char ch = (char) chars[i];
		// std::string s = ctos(ch);
		if (chars[i] > 0) {
			std::cout << static_cast<char>(chars[i]) << std::endl;
			std::cout << "Appending..." << std::endl;
			result.append(1, (char) chars[i]); // see stack overflow
			std::cout << "Result now: " << result << std::endl;
		}
	}

	return result;
}
