#ifndef SENECA_ICE_CREAM_H
#define SENECA_ICE_CREAM_H

#include <iostream>

namespace seneca {

	const int MAX_LEN = 20;

	class IceCream {
		int m_numOfScoops;
		char m_flavour[MAX_LEN + 1];

	public:
		IceCream();
		IceCream(int, const char*);

		bool isEmpty() const;
		void display(std::ostream&) const;

		IceCream& operator++(int);
		IceCream& operator-(int) const;
	};

}


#endif
