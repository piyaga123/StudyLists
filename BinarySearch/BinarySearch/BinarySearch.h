#pragma once

class __declspec(dllexport)  AddInts {

public:
	AddInts(int x, int y) { m_x = x; m_y = y; }
	AddInts() { m_x = 0; m_y = 0; }

	int AddThem();
	int m_x;
	int m_y;
};

//int bsearch(int Arr[], int size, int iTarg);

__declspec(dllexport) int bsearchPAL(int Arr[], int spos, int epos, int iTarg);

__declspec(dllexport) int bsearchPAL(int Arr[], int size, int iTarg);
