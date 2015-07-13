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
	cout << "DEBUG: start_idx = " << start_idx << ", end_idx = " << end_idx << endl;
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

int circular_buffer::calcNextIdx(int idx, int change)
{
	return (idx + change) % capacity;
}

void circular_buffer::enqueue(int x)
{
	buff[end_idx] = x;
	if (isFull())
	{
		dequeue();
	}

	end_idx = calcNextIdx(end_idx, 1);

	wasLastWrite = true;
}

int circular_buffer::dequeue()
{

	int x = buff[start_idx];
	start_idx = (start_idx + 1) % capacity;
	wasLastWrite = false;
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