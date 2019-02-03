#include "CompressedString.h"





std::ostream & operator<<(std::ostream & out, const CompressedString & input) {
	std::vector<char>::const_iterator vit;
	// maximum in O(9*n) which is O(n)
	for (vit = input.data.begin(); vit < input.data.end(); vit++) {
		char currentChar;
		if (isdigit(*vit)) {
			int numChar = *vit - 48;
			vit++;
			currentChar = *vit;
			// time complexity of this loop is O(k), k being numChar which can maximum be 9
			for (int i = 0; i < numChar; i++) {
				out << currentChar;
			}
		} else {
			currentChar = *vit;
			out << currentChar;
		}
	}
	return out;
}

// worst case time complexity of O(n).  The string is iterated through once and operations of complexity O(1)
// are completed.  This gives a big O of O(n).
CompressedString::CompressedString(std::string input) {
	int length = input.length();
	if (length == 0) {
		return;
	}
	std::string::iterator it;
	int letterCount = 0;
	char lastLetter = *input.begin();

	//handle base case of single first letter
	it = input.begin();
	if (*input.begin() != *(input.begin() + 1)) {
		this->data.push_back(*input.begin());
		it++;
		letterCount = 0;
	}

	for (it; it < input.end(); it++) {
		if (*it == lastLetter) {
			letterCount++;
		} else {
			if (letterCount == 1) {
				this->data.push_back(lastLetter);
			}else if (letterCount > 1) {
				this->data.push_back(letterCount + 48);
				this->data.push_back(lastLetter);
			} 
			letterCount = 1;
		}
		lastLetter = *it;
	}

	if (letterCount == 1) {
		this->data.push_back(lastLetter);
	} else {
		this->data.push_back(letterCount + 48);
		this->data.push_back(lastLetter);
	}

	double percentReduced = (1 - (double)this->data.size() / length) * 100;
	std::cout << "String compressed from: " << length << ", to: " << this->data.size() <<
		", so the string is compressed: " << percentReduced << "%" << std::endl;
}

void CompressedString::printCompressed() {
	std::vector<char>::const_iterator vit;
	for (vit = this->data.begin(); vit < this->data.end(); vit++) {
		std::cout << *vit << " ";
	}
}
