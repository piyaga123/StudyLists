// StringPermutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "vector"

using namespace std;

void ReverseStr(string& iStr)
{
	for (int ii = 0; ii <= (int)iStr.length() / 2; ii++)
		iStr[ii] = iStr[iStr.length() - ii];
	return;
}
void FindPermutations(const string iStr, vector<string> oStrings)
{
	//Base case 1
	if (iStr.length() == 1)
	{
		oStrings.push_back(iStr);
		return;
	}

	//Base case 2
	if (iStr.length() == 2)
	{
		oStrings.push_back(iStr);
		string str = iStr;
		ReverseStr(str);
		oStrings.push_back(str);
		return;
	}

	for (unsigned ii = 0; ii <= iStr.length()-1; ii++)
	{

	}
}

int main()
{
	string str = "ab";
	vector<string> strs;
	FindPermutations(str, strs);



    return 0;
}

