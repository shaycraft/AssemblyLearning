#include<iostream>
#include "comparisons.h"

using namespace std;

extern "C" {
	short clear(short x);
	int add2ints(int x1, int x2);
}

int main()
{
	int x1, x2;
	cout << "Assembly test program...";
	cout << "Clear = " << clear(22) << "\n";

	cout << "Enter x1: ";
	cin >> x1;
	cout << "Enter x2: ";
	cin >> x2;

	cout << "----------------------ASSEMBLY---------------------";
	cout << x1 << " + " << x2 << " = " << add2ints(x1, x2) << endl;
	cout << "---------------------C++---------------------------";
	cout << x1 << " + " << x2 << " = " << cadd2ints(x1, x2) << endl;

	return EXIT_SUCCESS;
}