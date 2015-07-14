#include<iostream>

#include "cppcbuff.h"

using namespace std;


int main()
{
	circular_buffer buff;
	int capacity = 0;
	int input_elem;
	int choice;

	cout << "Enter buffer capacity: ";
	cin >> capacity;
	buff.set_capacity(capacity);

	while ((choice = buff.menu_input()) != 0)
	{
		switch (choice) {
		case 1:
			cout << "Enter new capacity: ";
			cin >> capacity;
			buff.set_capacity(capacity);
			break;
		case 2:
			cout << "Enter value: ";
			cin >> input_elem;
			buff.enqueue(input_elem);
			break;
		case 3:
			cout << "Removed " << buff.dequeue() << endl;
			break;
		}
		buff.print();
	}

	return 0;
}