#include <iostream>

#include "Box.h"

using namespace std;
using namespace seneca;

void modifyByValue(Box b) {
	cout << "[modifyByValue] Before: ";
	b.display();
	b.setSize(999, 999);
	cout << "[modifyByValue] After:  ";
	b.display();
}

void modifyByPointer(Box* b) {
	cout << "[modifyByPointer] Before: ";
	b->display();
	b->setSize(888, 888);
	cout << "[modifyByPointer] After:  ";
	b->display();
}

void modifyByReference(Box& b) {
	cout << "[modifyByReference] Before: ";
	b.display();
	b.setSize(777, 777);
	cout << "[modifyByReference] After:  ";
	b.display();
}

int main()
{
	Box b1;
	b1.setSize(-2, 4);

	modifyByReference(b1);

	b1.display();
}
