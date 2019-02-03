#pragma once
#include <string>
#include <iostream>
#include <vector>

class CompressedString {

	friend std::ostream& operator<<(std::ostream &out, const CompressedString& input);

private:

	std::vector<char> data;
	std::vector<int> numbers;


public:


	CompressedString(std::string);
	
	void printCompressed();




};
