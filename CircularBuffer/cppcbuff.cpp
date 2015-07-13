#include<iostream>
#include "cppcbuff.h"

using namespace std;

circular_buffer::circular_buffer() {
	wasLastWrite = false;
}

void circular_buffer::set_capacity(int n)
{
	if (buff)
	{
		delete buff;
	}

	capacity = n;
	buff = new int[n];
	start_idx = 0;
	end_idx = 0;
}

void circular_buffer::print() {
	int len;
	if (isFull())
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
}

bool circular_buffer::isFull()
{
	if ((start_idx == end_idx) && wasLastWrite) {
		return true;
	}
	else
	{
		return false;
	}
}

void circular_buffer::enqueue(int x)
{
	/*if ((end_idx + 1) % capacity == start_idx)
	{
	dequeue();
	}*/

	buff[end_idx] = x;
	if (!isFull())
	{

		end_idx = (end_idx + 1) % capacity;
	}

	wasLastWrite = true;
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