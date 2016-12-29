// Given an image represented by an NxN matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?

/* 
i = 0
newCol = n - i - 1 ==  5 - 0 - 1 = 4
0,0 -> 0,4     newRow = j
0,1 -> 1,4	  
0,2 -> 2,4
0,3 -> 3,4
0,4 -> 4,4

1,0 -> 0,3
1,1 -> 1,3
1,2 -> 2,3
1,3 -> 3,3
1,4 -> 4,3


a b c d e    
f g h i j
k l m n o
p q r s t
u v w x y

u p k f a
v q l g b
w r m h c
x s n i d
y t o j e

*/

#include <iostream>

// my O(n) space solution
char** rotateImage(char image[][5], int n) {
	char ** newImg = new char *[n];
	for (int i = 0; i < n; i++) {
		newImg[i] = new char[n];
	}

	for (int i = 0; i < n; i++) {
		int newCol = n - i - 1;
		for (int j = 0; j < n; j++) {
			int newRow = j;
			newImg[newRow][newCol] = image[i][j];
		}
	}
	return newImg;
}

// Cite: CTCI
void rotateImageInPlace(char image[][5], int n) {
	// Rotate each layer, moving outside to inside
	for (int layer = 0; layer < (n/2); ++layer){
		int first = layer, // move diagnol towards center during each iteration
			last = n - 1 - layer; // move diagnol from the end of the row backwards

		for (int i = first; i < last; ++i) {
			int offset = i - first;
			
			// Save top as we move left to right through cur layer
			char top = image[first][i];

			// left --> top
			image[first][i] = image[last-offset][first];

			// bottom --> left
			image[last-offset][first] = image[last][last - offset];

			// right --> bottom
			image[last][last-offset] = image[i][last];

			// top --> right
			image[i][last] = top;
		}
	}
}

int main(int argc, char const *argv[])
{
	// I think a char and an int is 4 bytes if its 32 bits, soo...
	int n = 5;
	char image[5][5] = {
		{'a','b','c','d','e'},
		{'f','g','h','i','j'},
		{'k','l','m','n','o'},
		{'p','q','r','s','t'},
		{'u','v','w','x','y'}
	};

	std::cout << "Original array:\n\n";

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << image[i][j];
		}
		std::cout << std::endl;
	}


	std::cout << "\n\nRotated array:\n\n";
	rotateImageInPlace(image, 5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << image[i][j];
		}
		std::cout << std::endl;
	}

	char ** newImage = rotateImage(image, n);

	std::cout << "\n\nRotated array and saved in new array:\n\n";

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << newImage[i][j];
		}
		std::cout << std::endl;
	}

	return 0;
}

