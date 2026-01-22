#include "Box.h"

#include <iostream>

using namespace std;

namespace seneca {

	void Box::setWidth(double width) {
		if (width > 0) {
			m_width = width;
		}
		else {
			m_width = 0;
			m_height = 0;
		}
	}

	void Box::setHeight(double height) {
		if (height > 0) {
			m_height = height;
		}
		else {
			m_width = 0;
			m_height = 0;
		}
	}

	void Box::setSize(double w, double h) {
		setWidth(w);
		setHeight(h);
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
			cout << "Width: " << m_width;
			cout << ", Height: " << m_height
				<< ", Area: " << area() << endl;
		}
	}
}