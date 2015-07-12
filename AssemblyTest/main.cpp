#include<iostream>

using namespace std;

extern "C" {
	short clear(short x);
}

int main()
{
	cout << "Assembly test program...";
	cout << "Clear = " << clear(22);

	return EXIT_SUCCESS;
}