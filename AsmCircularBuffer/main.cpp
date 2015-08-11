#include<iostream>

using namespace std;

int capacity = 0;
int *buff = NULL;
int start_idx, end_idx = 0;
bool wasLastWrite;

extern "C" {
	bool isFull(int start_idx, int end_idx, bool wasLastWrite);
	int calcNextIdx(int idx, int change, int capacity);
	int enqueue(int *buff, int x, int start_idx, int *end_idx, bool wasLastWrite, int capacity);
}

void set_capacity(int n) {
	if (buff)
	{
		delete buff;
	}

	capacity = n;
	buff = new int[n];
	start_idx = 0;
	end_idx = 0;
	wasLastWrite = false;
}

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
	cout << "Value of calcNextIdx (20 ,3, 25) = " << calcNextIdx(20, 3, 25) << endl;
	cout << "Value of calcNextIdx (18 ,2, 19) = " << calcNextIdx(18, 2, 19) << endl;


	cout << "Enter buffer capacity: ";
	cin >> capacity;
	buff = new int[capacity];
	int cap_tmp = 0;

	int *temp = NULL;
	while ((choice = menu_input()) != 0)
	{
		switch (choice) {
		case 1:
			cout << "Enter new capacity: ";
			cin >> capacity;
			set_capacity(capacity);
			break;
		case 2:
			cout << "Enter value: ";
			cin >> input_elem;
			cap_tmp = enqueue(buff, input_elem, start_idx, &end_idx, wasLastWrite, capacity);
			cout << "cap_temp = " << cap_tmp << endl;
			//end_idx = calcNextIdx(end_idx, 1, capacity);
			break;
		case 3:
			//cout << "Removed " << buff.dequeue() << endl;
			break;
		case 4:
			cout << buff;
			print(buff, start_idx, end_idx, capacity, wasLastWrite);
		}
		print(buff, start_idx, end_idx, capacity, wasLastWrite);
	}
}