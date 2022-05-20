#include<cmath>

#include "HRectangle.h"

class HSquare : public HTetragon {
	double _length;
public:
	HSquare(const Point& p, const double& length) : 
		HTetragon(p), _length(length) {}
	HSquare(const HSquare& that) : HTetragon(that._point),
		_length(that._length) {}
	~HSquare() {}

	HSquare& operator=(const HSquare& that) {
		_point = that._point;
		_length = that._length;
		return *this;
	}

	HTetragon* clone() const override {
		return new HSquare(*this);
	}

	Point apexA() const override {
		return _point;
	}
	Point apexB() const override {
		return Point(_point.x(), _point.y() + _length);
	}
	Point apexC() const override {
		return Point(_point.x() + _length, _point.y() + _length);
	}
	Point apexD() const override {
		return Point(_point.x() + _length, _point.y());
	}

	void setA(const Point& point) override {
		Point right_top = apexC();
		double width, heigth;
		if (point.x() > right_top.x()) {
			_point.x() = right_top.x();
			width = point.x() - right_top.x();
		}
		else {
			_point.x() = point.x();
			width = right_top.x() - point.x();
		}
		if (point.y() > right_top.y()) {
			_point.y() = right_top.y();
			heigth = point.y() - right_top.y();
		}
		else {
			_point.y() = point.y();
			heigth = right_top.y() - point.y();
		}
		_length = min(width, heigth);
	}
	void setB(const Point& point) override {
		Point right_bottom = apexD();
		double width, heigth;
		if (point.x() > right_bottom.x()) {
			_point.x() = right_bottom.x();
			width = point.x() - right_bottom.x();
		}
		else {
			_point.x() = point.x();
			width = right_bottom.x() - point.x();
		}
		if (point.y() < right_bottom.y()) {
			_point.y() = point.y();
			heigth = right_bottom.y() - point.y();
		}
		else {
			heigth = point.y() - right_bottom.y();
		}
		_length = min(width, heigth);
	}
	void setC(const Point& point) override {
		Point left_bottom = apexA();
		double width, heigth;
		if (point.x() < left_bottom.x()) {
			_point.x() = point.x();
			width = left_bottom.x() - point.x();
		}
		else {
			width = point.x() - left_bottom.x();
		}
		if (point.y() < left_bottom.y()) {
			_point.y() = point.y();
			heigth = left_bottom.y() - point.y();
		}
		else {
			heigth = point.y() - left_bottom.y();
		}
		_length = min(width, heigth);
	}
	void setD(const Point& point) override {
		Point left_top = apexB();
		double width, heigth;
		if (point.x() < left_top.x()) {
			_point.x() = point.x();
			width = left_top.x() - point.x();
		}
		else {
			width = point.x() - left_top.x();
		}
		if (point.y() > left_top.y()) {
			_point.y() = left_top.y();
			heigth = point.y() - left_top.y();
		}
		else {
			_point.y() = point.y();
			heigth = left_top.y() - point.y();
		}
		_length = min(width, heigth);
	}

	double area() const override {
		return _length * _length;
	}
};

class HRhomb : public HTetragon {
	double _length, _cos;
public:
	HRhomb(const Point& point, const double& length, const double& cos) :
		HTetragon(point), _length(length), _cos(cos) {}
	HRhomb(const HRhomb& that) : HTetragon(that._point), 
		_length(that._length), _cos(that._cos) {}
	~HRhomb() {}

	HTetragon* clone() const override {
		return new HRhomb(*this);
	}

	Point apexA() const override {
		return _point;
	}
	Point apexB() const override {
		double x = _length * _cos;
		double y = sqrt(_length * _length - x * x);
		return Point(_point.x() + x, _point.y() + y);
	}
	Point apexC() const override {
		return Point(apexB().x() + _length, apexB().y());
	}
	Point apexD() const override {
		return Point(apexA().x() + _length, apexA().y());
	}

	void setA(const Point& point) override {
		Point b = apexB();
		if (point.y() > b.y()) {
			_point = b;
			_length = sqrt((point.x() - b.x()) * (point.x() - b.x()) + (point.y() - b.y()) * (point.y() - b.y()));
			_cos = (point.x() - b.x()) / _length;
		}
		else {
			_point = point;
			_length = sqrt((point.x() - b.x()) * (point.x() - b.x()) + (point.y() - b.y()) * (point.y() - b.y()));
			_cos = (b.x() - point.x()) / _length;
		}
	}
	void setB(const Point& point) override {
		Point a = _point;
		if (point.y() < a.y()) {
			_point = point;
			_length = sqrt((point.x() - a.x()) * (point.x() - a.x()) + (point.y() - a.y()) * (point.y() - a.y()));
			_cos = (a.x() - point.x()) / _length;
		}
		else {
			_length = sqrt((point.x() - a.x()) * (point.x() - a.x()) + (point.y() - a.y()) * (point.y() - a.y()));
			_cos = (point.x() - a.x()) / _length;
		}
	}
	void setC(const Point& point) override {
		setB(Point(point.x() - _length, point.y()));
	}
	void setD(const Point& point) override {
		setA(Point(point.x() - _length, point.y()));
	}

	double area() const override {
		return _length * _length * sqrt(1 - _cos * _cos);
	}
};
