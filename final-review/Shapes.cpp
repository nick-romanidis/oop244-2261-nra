#include <iostream>

// Remember, this should not be done in a header file.
// But for today, I am going to cheat.
using namespace std;

struct Vertex {
	float m_x;
	float m_y;

	Vertex() {
		m_x = 0;
		m_y = 0;
	}

	Vertex(float x, float y) {
		m_x = x;
		m_y = y;
	}

	void print(std::ostream& os) const {
		os.precision(2);
		os.setf(ios::fixed);

		cout << "(" << m_x << ", " << m_y << ")";

		os.unsetf(ios::fixed);
	}
};

class iShape {
public:
	virtual void draw(std::ostream& os) const = 0;
	virtual float area() const = 0;
	virtual ~iShape() = default;
};

class Rectangle : public iShape {
	Vertex* m_vertices;
	size_t m_verticeCount;
	float m_width;
	float m_height;

public:
	Rectangle() {
		m_vertices = nullptr;
		m_width = 0.0F;
		m_height = 0.0F;
		m_verticeCount = 0;
	}

	Rectangle(Vertex topLeft, Vertex botRight) {
		if (botRight.m_x > topLeft.m_x
			&& botRight.m_y < topLeft.m_y) {
			// Valid

			m_width = botRight.m_x - topLeft.m_x;
			m_height = topLeft.m_y - botRight.m_y;

			m_verticeCount = 2;
			m_vertices = new Vertex[m_verticeCount];
			m_vertices[0] = topLeft;
			m_vertices[1] = botRight;
		}
		else {
			*this = Rectangle();
		}
	}

	Rectangle(const Rectangle& src) {
		*this = src;
	}

	Rectangle& operator=(const Rectangle& src) {
		// Self-Assignment check
		if (this != &src) {
			// Delete dynamic memory
			delete[] m_vertices;
			m_vertices = nullptr;

			// Shallow copy
			m_width = src.m_width;
			m_height = src.m_height;
			m_verticeCount = src.m_verticeCount;

			// Deep copy
			if (src.m_vertices != nullptr && src.m_verticeCount > 0) {
				m_vertices = new Vertex[m_verticeCount];

				for (size_t i = 0; i < m_verticeCount; i++) {
					m_vertices[i] = src.m_vertices[i];
				}
			}
		}

		return *this;
	}

	virtual ~Rectangle() {
		delete[] m_vertices;
		m_vertices = nullptr;
	}

	virtual void draw(std::ostream& os) const {
		if (m_vertices != nullptr) {
			auto precision = os.precision(2);
			os.setf(ios::fixed);

			if (m_width == m_height) {
				os << "Square: ";
			}
			else if (m_width == m_height) {
				os << "Rectangle: ";
			}

			os << "[width=" << m_width << "," << "height=" << m_height;

			for (size_t i = 0; i < m_verticeCount; i++) {
				m_vertices[i].print(os);
			}

			os << endl;

			os.precision(precision);
			os.unsetf(ios::fixed);
		}
	}

	virtual float area() const {
		return m_width * m_height;
	}

	std::ostream& operator<<(std::ostream&& os) {
		draw(os);
		return os;
	}
};

class Square : public Rectangle {

	Square() = default;

	// On your quiz, this is what I was expecting.
	// Square(float size) : Rectangle (size, size)

	Square(Vertex topLeft, float size) : Rectangle(topLeft, Vertex(topLeft.m_x + size, topLeft.m_y - size)) {
	}

	virtual ~Square() = default;

};

