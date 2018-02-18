#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	string s = "abcd";
	s.c_str();
	int len = s.length();
	string rev = "";

	for (int i = len - 1; i >= 0; --i) {
		rev += s[i];
	}
	
	std::cout << rev << std::endl;

	return 0;
}
