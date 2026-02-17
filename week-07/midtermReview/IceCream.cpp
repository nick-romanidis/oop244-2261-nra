#include "IceCream.h"

#include <cstring>
#include <iomanip>

using namespace std;


namespace seneca {
	IceCream::IceCream() {
		m_numOfScoops = 0;
		m_flavour[0] = '\0';
	}

	IceCream::IceCream(int numOfScoops, const char* flavour) {
		bool isValid = numOfScoops >= 1 && numOfScoops <= 5;

		if (isValid) {
			isValid = flavour != NULL
				&& flavour[0] != '\0'
				&& strnlen(flavour, MAX_LEN) <= MAX_LEN;
		}

		if (isValid) {
			m_numOfScoops = numOfScoops;

			strncpy(m_flavour, flavour, MAX_LEN);
			m_flavour[MAX_LEN - 1] = '\0';
		}
		else {
			*this = IceCream();
		}
	}

	bool IceCream::isEmpty() const {
		return m_numOfScoops == 0;
	}

	void IceCream::display(ostream& os) const {
		if (isEmpty()) {
			os << "Argh!" << endl;
		}
		else {
			// IO MANIP
			os << setfill('0') << setw(3) << m_numOfScoops << setfill(' ');

			// Old way, old people like your professor use.
			char oldFill = os.fill('0');
			os.width(3);
			os << m_numOfScoops;
			os.fill(oldFill);

			os << " " << m_flavour;
		}
	}

	IceCream& IceCream::operator++(int) {
		if (!isEmpty()) {
			m_numOfScoops++;
		}

		return *this;
	}

	IceCream& IceCream::operator-(int rhs) const {
		IceCream temp = *this;

		if (!isEmpty()) {
			temp.m_numOfScoops - rhs;

			if (temp.m_numOfScoops < 1) {
				temp.m_numOfScoops = 1;
			}
			else if (temp.m_numOfScoops > 5) {
				temp.m_numOfScoops = 1;
			}
		}

		return temp;
	}
}