#include<iostream>

using namespace std;

extern "C" {
	bool isFull(int start_idx, int end_idx, bool wasLastWrite);
}

//bool isFull(int start_idx, int end_idx, bool wasLastWrite)
//{
//	// TODO, rewrite this in assembly
//	if ((start_idx == end_idx) && wasLastWrite) {
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

void print_menu()
{
	cout << "------- MENU --------" << endl;
	cout << "1.  Set capacity (clears buffer.\n";
	cout << "2.  Insert.\n";
	cout << "3.  Remove\n";
	cout << "4.  Print.\n";
	cout << "0.  Exit\n";
}

int menu_input() {
	print_menu();
	int choice;
	cin >> choice;

	return choice;
}

void print(int *buff, int start_idx, int end_idx, int capacity, bool wasLastWrite) {
	int len;
	if (isFull(start_idx, end_idx, wasLastWrite))
	{
		len = capacity;
	}
	else
	{
		len = ((capacity - start_idx) + end_idx) % capacity;
	}
	for (int i = 0; i < len; i++) {
		cout << buff[((i + start_idx)) % capacity] << " - ";
	}
	cout << endl;
	cout << "DEBUG: start_idx = " << start_idx << ", end_idx = " << end_idx << endl;
}

int main()
{
	int capacity = 0;
	int input_elem;
	int choice;
	int *buff = NULL;
	int start_idx = 0, end_idx = 0;
	bool wasLastWrite = false;

	cout << "Value of isFull = " << isFull(100, 101, true) << endl;

	cout << "Enter buffer capacity: ";
	cin >> capacity;
	buff = new int[capacity];


	while ((choice = menu_input()) != 0)
	{
		switch (choice) {
		case 1:
			cout << "Enter new capacity: ";
			cin >> capacity;
			//buff.set_capacity(capacity);
			break;
		case 2:
			cout << "Enter value: ";
			cin >> input_elem;
			//buff.enqueue(input_elem);
			break;
		case 3:
			//cout << "Removed " << buff.dequeue() << endl;
			break;
		}
		print(buff, start_idx, end_idx, capacity, wasLastWrite);
	}
}