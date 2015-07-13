#include<iostream>
#include "cppcbuff.h"

using namespace std;

circular_buffer::circular_buffer() {

}

void circular_buffer::set_capacity(int n)
{
	if (buff)
	{
		delete buff;
	}

	capacity = n;
	buff = new int[n];
}

void circular_buffer::print() {
	int len = ((capacity - start_idx) + end_idx) % capacity;
	for (int i = 0; i < len; i++) {
		cout << buff[((i + start_idx)) % capacity] << " - ";
	}
	cout << endl;
}

void circular_buffer::enqueue(int x)
{
	/*if ((end_idx + 1) % capacity == start_idx)
	{
	dequeue();
	}*/

	buff[end_idx] = x;
	end_idx = (end_idx + 1) % capacity;
	if (end_idx == start_idx)
	{
		end_idx = capacity + 1;
	}
}

int circular_buffer::dequeue()
{
	if (start_idx == end_idx) {
		cout << "ERROR: ------ Cannot dequeue when buffer is empty.\n";
		return NULL;
	}
	int x = buff[start_idx];
	start_idx = (start_idx + 1) % capacity;
	return x;
}

void circular_buffer::print_menu()
{
	cout << "------- MENU --------" << endl;
	cout << "1.  Set capacity (clears buffer.\n";
	cout << "2.  Insert.\n";
	cout << "3.  Remove\n";
	cout << "4.  Print.\n";
	cout << "0.  Exit\n";
}

int *buffer;


int circular_buffer::menu_input() {
	print_menu();
	int choice;
	cin >> choice;

	return choice;
}