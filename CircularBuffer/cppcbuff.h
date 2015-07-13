#include<iostream>

#ifndef CPPCBUFF_H
#define CPPCBUFF_H

class circular_buffer
{
public:
	circular_buffer();
	void print_menu();
	int menu_input();
	void set_capacity(int n);
	void enqueue(int n);
	int dequeue();
	void print();
private:
	int capacity = 0;
	int *buff = NULL;
	int start_idx, end_idx = 0;
	bool wasLastWrite;
	bool isFull();
};

#endif