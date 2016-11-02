// PalindromeWithStringCleanup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

void cleanUpString(string& iStr) {	
	iStr.erase(remove_if(iStr.begin(), iStr.end(), [](auto c) {return !isalpha(c); }), iStr.end());
	transform(iStr.begin(), iStr.end(), iStr.begin(), ::tolower);
}



bool IsPalindrome(const string& iStr) {

	string str(iStr);
	cleanUpString(str);

	for (int ii = 0, jj = str.length() - 1; ii <(int) str.length()/2; ii++, jj--) {
		if (str[ii] != str[jj])
			return false;
	}
	return true;
}

int main()
{
	string str("D  AD");
	bool ok = IsPalindrome(str);
	return 0;
}

