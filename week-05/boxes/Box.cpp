#include "Box.h"

#include <iostream>

using namespace std;

namespace seneca {
	Box::Box() {
		m_width = 0;
		m_height = 0;
	}

	Box::Box(double w, double h) {
		if (w <= 0 || h <= 0) {
			// Set an empty state.
			*this = Box();
		}
		else {
			m_width = w;
			m_height = h;
		}
	}

	void Box::setSize(double w, double h) {
		*this = Box(w, h);
	}

	double Box::getWidth() const {
		return m_width;
	}

	double Box::getHeight() const {
		return m_height;
	}

	double Box::area() const {
		return m_width * m_height;
	}

	void Box::display() const {
		if (m_width == 0) {
			cout << "BAD OBJECT" << endl;
		}
		else {
			cout.setf(ios::fixed);
			cout.precision(2);

			auto oldFill = cout.fill('*');
			cout.width(15);
			cout << "Width: " << m_width << endl;

			cout.width(15);
			cout << "Height: " << m_height << endl;

			cout.width(15);
			cout << "Area: " << area() << endl;

			cout.unsetf(ios::fixed);
			cout.fill(oldFill);
		}
	}
}