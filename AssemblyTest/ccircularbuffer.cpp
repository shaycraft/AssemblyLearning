#include<iostream>

using namespace std;

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
};

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
		}
		buff.print();
	}

	return 0;
}