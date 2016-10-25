// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"
#include "BinarySearch.h"

int AddInts::AddThem() {
	return m_x + m_y; 
}

int bsearchPAL(int Arr[], int spos, int epos, int iTarg) {

	AddInts a(7, 8);
	//Assert::AreEqual(a.AddThem(), 15);

	int range = epos - spos;
	if (range == 0 && Arr[spos] == iTarg) return spos;
	if (range == 0) return -1;
	if (range == 1 && Arr[spos] == iTarg) 
		return spos;
	else if(range == 1 && Arr[epos] == iTarg) 
		return epos;


	int center = spos + range / 2;
	if (Arr[center] > iTarg)
		return bsearchPAL(Arr, spos, center, iTarg);
	else if (Arr[center] < iTarg)
		return bsearchPAL(Arr, center, epos, iTarg);
	else
		return center;

	return -1;
}

int bsearchPAL(int Arr[], int size, int iTarg) {
	if (size < 1) return -1;

	return bsearchPAL(Arr, 0, size - 1, iTarg);
}

int main()
{
    return 0;
}

