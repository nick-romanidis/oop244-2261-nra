#include <iostream>

using namespace std; 

template <typename T>
class SolidCalculator {
	T m_x;
	T m_y;

public:
	SolidCalculator(T x, T y) {
		m_x = x;
		m_y = y;
	}

	T CalculateSquareArea() {
		return x * y;
	}

	T CalculateTriangleArea() {
		return x * y / static_cast<T>(2);
	}
};

// What operations must the data type implement?
// *, /, =

int main() {
	SolidCalculator<int> calcInt(5, 3);
	cout << calcInt.CalculateSquareArea() << endl;
	cout << calcInt.CalculateTriangleArea() << endl;
}