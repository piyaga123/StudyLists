// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"

int bsearch(int Arr[], int spos, int epos, int iTarg) {

	int range = epos - spos;
	if (range == 0 && Arr[spos] == iTarg) return spos;
	if (range == 0) return -1;
	if (range == 1 && Arr[spos] == iTarg) 
		return spos;
	else if(range == 1 && Arr[epos] == iTarg) 
		return epos;


	int center = spos + range / 2.0;
	if (Arr[center] > iTarg)
		return bsearch(Arr, spos, center, iTarg);
	else if (Arr[center] < iTarg)
		return bsearch(Arr, center, epos, iTarg);
	else
		return center;

	return -1;
}

int bsearch(int Arr[], int size, int iTarg) {
	if (size < 1) return -1;

	return bsearch(Arr, 0, size - 1, iTarg);
}

int main()
{
	int Arr[] = { 2,5,7,8,9,11,13,34, 67, 89, 111, 222, 333, 444, 555 };
	int f1 = bsearch(Arr, 15, 13);
	int f2 = bsearch(Arr, 15, 9);
	int f22 = bsearch(Arr, 15, 555);
	int f = bsearch(Arr, 15, 2);
	assert(f1 == 6);
	assert(f2 == 4);

	int ArrS1[] = {0};
	int ArrS2[] = { 4 };

	int f3 = bsearch(ArrS2, 1, 4);
	int f4 = bsearch(ArrS2, 1, 5);

	assert(f3 == -1);

    return 0;
}

