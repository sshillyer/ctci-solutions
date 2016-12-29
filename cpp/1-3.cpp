#include <iostream>
#include <cstring>

void reverse(char * str);

int main(int argc, char const *argv[])
{
	/* code */
	char str[] = "This is a null terminated string!\0";
	std::cout << str << std::endl;
	std::cout << "Reversing..." << std::endl;
	reverse(str);

	std::cout << str << std::endl;

	return 0;
}

void reverse(char * str) {
	int len = std::strlen(str);

	int i = 0, j = len - 1;

	while (i < j) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++; j--;
	}
}