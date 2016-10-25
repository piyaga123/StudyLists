// PalindromeWithStringCleanup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

string& cleanUpString(string& iStr) {
	
	string retStr = iStr;
	retStr.erase(remove_if(iStr.begin(), iStr.end(), [](auto c)->bool {return !isalpha(c); }));
	return retStr;
}



bool IsPalindrome(const string& iStr) {
	for (int ii = 0, jj = iStr.length() - 1; ii < iStr.length()/2; ii++, jj--) {
		if (iStr[ii] != iStr[jj])
			return false;
	}
	return true;
}

int main()
{
	string str("D  AD");
	bool ok = IsPalindrome(cleanUpString(str));
	return 0;
}

