// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <array>

using namespace std;


void sort(int iA[], int size) {

 // Invariants during partition
 // bottom [0, equal-1]
 // 

}

void test1() {

	string str = "newsIsAllsee";

	str.append("really!?");
	str.push_back('x');
	str.push_back('9');
	str.pop_back();
	str.insert(3, "Gauss");
	str.erase(8, str.length());
	string::iterator itr = str.insert(str.begin() + 3, ',');
	str.insert(str.length(), 3, '.');
	cout << str;

}

int main()
{
	test1();
	int ar[] = { 3, 7, 6, 2, 8, 4 };
	sort(ar);
	cout << ar;
    return 0;
}

