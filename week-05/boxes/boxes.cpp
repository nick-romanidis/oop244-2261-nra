#include <iostream>

#include "Box.h"

using namespace std;
using namespace seneca;

namespace seneca {
	// Helper operator ==
	// Notice it can access private methods when marked as a friend.
	// If you uncomment the friendship line, you must use methods
	// instead of variables.
	bool operator==(const Box& lhs, const Box& rhs) {
		return (
			lhs.m_width == rhs.m_width
			&& lhs.m_height == rhs.m_height
			);
	}
}


int main()
{
	Box b1(2.111, 42.2224);
	Box b2(2.1113, 42.2224);
	
	if (b1 == b2) {
		cout << "IdenticaL";
	}
	else {
		cout << "Different";
	}
	//b1.display();
}
