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
	};

#endif // !SENECA_BOX_H

}