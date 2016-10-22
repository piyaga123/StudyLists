// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include <limits.h>
#define INT_BITS 32

int absVal(int x) {
	int m = x >> 31;
	return (m^x) + (~m + 1);
}
int rotateLeft(int d, int n) {
	/* In n<<d, last d bits are 0. To put first 3 bits of n at
	last, do bitwise or of n<<d with n >>(INT_BITS - d) */
	//unsigned int n = 0x87654321;
	//unsigned int d = 4;
	unsigned int x = (n << d) | (n >> (INT_BITS - d));
	return x;
}

int addOK(int x, int y) {
	int m = x >> 31;
	int n = y >> 31;
	int sum = (x + y) >> 31;

	return ((!!(m^n)) | (!(sum ^ m)));
}

/*
* ezThreeFourths - multiplies by 3/4 rounding toward 0,
*   Should exactly duplicate effect of C expression (x*3/4),
*   including overflow behavior.
*   Examples: ezThreeFourths(11) = 8
*             ezThreeFourths(-9) = -6
*             ezThreeFourths(1073741824) = -268435456 (overflow)
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 12
*   Rating: 3
*/
int ezThreeFourths(int x) {
	//return ((x >> 1) + (x >> 2));
	x = (x << 1 )+ x;
	return x >> 2;
}

int ezThreeFourthsVrinda(int x) {
	//return ((x >> 1) + (x >> 2));
	int triple_x = x + x + x;
	int sign = triple_x >> 31;
	int part1 = ((triple_x >> 2) );
	int part2 = (~0) ^ sign ;// (((triple_x + 1) >> 2)&(sign)+(~0));
	int result = ((triple_x + part2) >> 2);
	return result;
}

int ThreeFourths(int x)
{
	int x3 = x + x + x;
	return (x3 >= 0) ? (x3 >> 2) : -(int)((UINT_MAX - x3 + 1) >> 2);
}
int ezThreeFourthsGit(int x) {
	int mask;
	int whatSign;
	int bias;
	int divByFour;
	x = ((x << 1) + x); //multiply by 3 and then use pwrof2
	mask = (1 << 2) + ~0;
	whatSign = x >> 31;
	bias = mask&whatSign;
	divByFour = ((x + bias) >> 2);
	return divByFour;
}
/*
* multFiveEighths - multiplies by 5/8 rounding toward 0.
*   Should exactly duplicate effect of C expression (x*5/8),
*   including overflow behavior.
*   Examples: multFiveEighths(77) = 48
*             multFiveEighths(-22) = -13
*             multFiveEighths(1073741824) = 13421728 (overflow)
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 12
*   Rating: 3
*/
int multFiveEighths(int x) {
	return (((x + 1) >> 1) + (x >> 3) + 1);
}
int multFiveEighthsGit(int x) {
	int mask;
	int whatSign;
	int bias;
	int divByEight;
	x = ((x << 2) + x); //multiply by 4 and then use pwrof2
	mask = (1 << 3) + ~0;
	whatSign = x >> 31;
	bias = mask&whatSign;
	divByEight = ((x + bias) >> 3);
	return divByEight;
}

/*
* satAdd - adds two numbers but when positive overflow occurs, returns
*          maximum possible value, and when negative overflow occurs,
*          it returns minimum positive value.
*   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
*             satAdd(0x80000000,0xffffffff) = 0x80000000
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 30
*   Rating: 4
*/
int satAdd(int x, int y) {
	int overflow = ((x^y) | (x^~(x + y))) >> 31; // left side 10011^10001 = 00010 | 10011^11011 = 01000 , 01010 shift to see sign
	return (overflow & (x + y)) | (~overflow&(((x + y) >> 31) ^ (1 << 31)));
}


/*
* trueThreeFourths - multiplies by 3/4 rounding toward 0,
*   avoiding errors due to overflow
*   Examples: trueThreeFourths(11) = 8
*             trueThreeFourths(-9) = -6
*             trueThreeFourths(1073741824) = 805306368 (no overflow)
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 20
*   Rating: 4
*/
int trueThreeFourths(int x) {
	/*First, we obtain the absolute value of the value x. Then we obtain quarter, which is a fourth of x. By taking its negative, shifting it by two,
	then adding it to the absolute value of x, we obtain three-fourths of x. Using the sign, we can determine whether to make it negative again or not.*/
	int sign = x >> 31;
	int absx = (x^sign) + ~sign + 1;
	int quarter = (~absx + 1);
	quarter = quarter >> 2;

	absx = absx + quarter;

	return (~sign&absx) | (sign&(~absx + 1));
}
/*
* trueFiveEighths - multiplies by 5/8 rounding toward 0,
*  avoiding errors due to overflow
*  Examples: trueFiveEighths(11) = 6
*            trueFiveEighths(-9) = -5
*            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
*  Legal ops: ! ~ & ^ | + << >>
*  Max ops: 25
*  Rating: 4
*/
int trueFiveEighths(int x)
{
	int sign = x >> 31;
	int absx = (x^sign) + ~sign + 1;
	int quarter = (~absx + 1);
	quarter = quarter >> 3;

	absx = absx + quarter;

	return (~sign&absx) | (sign&(~absx + 1));

}
int main()
{
	int a = 1073741824;
	int n = a * 3/4;
	int expected = 0x1E000000;
	int v1 = ezThreeFourthsGit(a);
	//int vrinda = ezThreeFourthsVrinda(x);
	//int vrinda = multFiveEighths(a);
	int git = trueThreeFourths(a);
	int expc = n;
	
	/*int x = 0x80000000;
	int y = 0xffffffff;
	int result = satAdd(x, y);
	*/
	return 0;
}




