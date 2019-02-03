#include <iostream>
#include "CompressedString.h"

using namespace std;

int main(int argc, char* argv[]) {

	string shortString = "abc";
	string longString = "aaaaadddddeeeeffwwwwazwww";


	CompressedString shortCompressed = CompressedString(shortString);
	CompressedString longCompressed = CompressedString(longString);

	shortCompressed.printCompressed();
	cout << endl;
	longCompressed.printCompressed();
	cout << endl;

	cout << shortCompressed << endl;
	cout << longCompressed << endl;


	cin.get();
}

