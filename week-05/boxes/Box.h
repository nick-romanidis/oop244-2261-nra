#ifndef SENECA_BOX_H
#define SENECA_BOX_H

namespace seneca {

	class Box {
		double m_width;
		double m_height;

	public:
		Box();
		Box(double w, double h);

		void setSize(double w, double h);

		double getWidth() const;
		double getHeight() const;
		double area() const;

		void display() const;

		// Implement == outside of the class as a friend.
		friend bool operator==(const Box& lhs, const Box& rhs);

		// Implement == operator within the class.
		//bool operator==(const Box& rhs) {
		//	return (
		//			m_width == rhs.m_width
		//			&& m_height == rhs.m_height
		//		);
		//}
	};

#endif // !SENECA_BOX_H

}
