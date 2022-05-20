#include"HTetragon.h"

class HRectangle : public HTetragon {
	double _width, _heigth;
public:
	HRectangle(const Point& p, const double& width, const double& heigth) :
		HTetragon(p), _width(width), _heigth(heigth) {}
	HRectangle(const HRectangle& that) : HTetragon(that._point), 
		_width(that._width), _heigth(that._heigth) {}
	~HRectangle() {}

	HRectangle& operator=(const HRectangle& that) {
		_point = that._point;
		_width = that._width;
		_heigth = that._heigth;
		return *this;
	}

	HTetragon* clone() const override {
		return new HRectangle(*this);
	}

	Point apexA() const override {
		return _point;
	}
	Point apexB() const override {
		return Point(_point.x(), _point.y() + _heigth);
	}
	Point apexC() const override {
		return Point(_point.x() + _width, _point.y() + _heigth);
	}
	Point apexD() const override {
		return Point(_point.x() + _width, _point.y());
	}

	void setA(const Point& point) override {
		Point right_top = apexC();
		if (point.x() > right_top.x()) {
			_point.x() = right_top.x();
			_width = point.x() - right_top.x();
		}
		else {
			_point.x() = point.x();
			_width = right_top.x() - point.x();
		}
		if (point.y() > right_top.y()) {
			_point.y() = right_top.y();
			_heigth = point.y() - right_top.y();
		}
		else {
			_point.y() = point.y();
			_heigth = right_top.y() - point.y();
		}
	}
	void setB(const Point& point) override {
		Point right_bottom = apexD();
		if (point.x() > right_bottom.x()) {
			_point.x() = right_bottom.x();
			_width = point.x() - right_bottom.x();
		}
		else {
			_point.x() = point.x();
			_width = right_bottom.x() - point.x();
		}
		if (point.y() < right_bottom.y()) {
			_point.y() = point.y();
			_heigth = right_bottom.y() - point.y();
		}
		else {
			_heigth = point.y() - right_bottom.y();
		}
	}
	void setC(const Point& point) override {
		Point left_bottom = apexA();
		if (point.x() < left_bottom.x()) {
			_point.x() = point.x();
			_width = left_bottom.x() - point.x();
		}
		else {
			_width = point.x() - left_bottom.x();
		}
		if (point.y() < left_bottom.y()) {
			_point.y() = point.y();
			_heigth = left_bottom.y() - point.y();
		}
		else {
			_heigth = point.y() - left_bottom.y();
		}
	}
	void setD(const Point& point) override {
		Point left_top = apexB();
		if (point.x() < left_top.x()) {
			_point.x() = point.x();
			_width = left_top.x() - point.x();
		}
		else {
			_width = point.x() - left_top.x();
		}
		if (point.y() > left_top.y()) {
			_point.y() = left_top.y();
			_heigth = point.y() - left_top.y();
		}
		else {
			_point.y() = point.y();
			_heigth = left_top.y() - point.y();
		}
	}

	double area() const override {
		return _width * _heigth;
	}
};

HRectangle operator+(const HTetragon& a, const HTetragon& b) {
	double minX, minY, maxX, maxY;

	minX = min(min(a.apexA().x(), a.apexB().x()), min(b.apexA().x(), b.apexB().x()));
	minY = min(min(a.apexA().y(), a.apexD().y()), min(b.apexA().y(), b.apexD().y()));

	maxX = max(max(a.apexC().x(), a.apexD().x()), max(b.apexC().x(), b.apexD().x()));
	maxY = max(max(a.apexB().y(), a.apexC().y()), max(b.apexB().y(), b.apexC().y()));

	return HRectangle(Point(minX, minY), maxX-minX, maxY-minY);
}

class Container {
	HTetragon** _arr;
	size_t _size, _capacity;

	void increase() {
		_capacity = _capacity * 2 + 1;
		HTetragon** newArr = new HTetragon* [_capacity];
		for (int i = 0; i < size(); i++)
			newArr[i] = _arr[i];
		delete[] _arr;
		_arr = newArr;
	}
	void reduce() {
		_capacity /= 2;
		HTetragon** newArr = new HTetragon * [_capacity];
		for (int i = 0; i < size(); i++)
			newArr[i] = _arr[i];
		delete[] _arr;
		_arr = newArr;
	}
public:
	Container(const size_t capacity = 0): 
		_arr(new HTetragon*[capacity]), _size(0), _capacity(capacity) {}
	Container(const Container& that) :
		_arr(new HTetragon* [that._capacity]), 
		_size(that._size), _capacity(that._capacity) {
		for (int i = 0; i < _size; i++)
			_arr[i] = that._arr[i]->clone();
	}
	~Container() { 
		for (int i = 0; i < _size; i++)
			delete _arr[i];
		delete[] _arr;
	}

	Container& operator=(const Container& that) {
		for (int i = 0; i < _capacity; i++)
			delete _arr[i];
		delete[] _arr;
		_arr = new HTetragon * [that._capacity];
		_size = that._size;
		_capacity = that._capacity;
		for (int i = 0; i < _size; i++)
			_arr[i] = that._arr[i]->clone();
		return *this;
	}

	HTetragon& operator[](const size_t& i) {
		if (i >= _size)
			throw "Out of bounds error";
		return *_arr[i];
	}
	const HTetragon& operator[](const size_t& i) const {
		if (i >= _size)
			throw "Out of bounds error";
		return *_arr[i];
	}

	bool empty() const { return _size == 0; }

	const size_t& size() const { return _size; }
	const size_t& capacity() const { return _capacity; }

	void add(const HTetragon& tetr) {
		if (_size == _capacity)
			increase();
		_arr[_size++] = tetr.clone();
	}
	HTetragon& pop() {
		if (_size <= _capacity / 2)
			reduce();
		HTetragon* del = _arr[--_size];
		_arr[_size] = nullptr;
		return *del;
	}

	Container less(const HTetragon& tetr) const {
		Container less;
		for (int i = 0; i < size(); i++) {
			if (*_arr[i] < tetr)
			{
				less.add(*_arr[i]);
			}
		}
		return less;
	}
	HRectangle sum() const {
		if (empty())
			throw "Container is empty";
		HRectangle sum = *_arr[0] + *_arr[0];
		for (int i = 1; i < size(); i++)
			sum = sum + *_arr[i];
		return sum;
	}
};

ostream& operator<<(ostream& os, const Container& con) {
	os << "Container: {" << endl;
	for (int i = 0; i < con.size(); i++)
		os << i+1 << ". " << con[i] << endl;
	os << "}";
	return os;
}

class HParallelogram : public HTetragon {
	double _width, _heigth, _cos;
public:
	HParallelogram(const Point& point, const double& width, const double& heigth, const double& cos) :
		HTetragon(point), _width(width), _heigth(heigth){
		if (cos < -1 || cos > 1)
			throw "Cos < -1 or > 1";
		_cos = cos;
	}
	HParallelogram(const HParallelogram& that) : HTetragon(that._point), 
		_width(that._width), _heigth(that._heigth), _cos(that._cos) {}
	~HParallelogram() {}

	HParallelogram& operator=(const HParallelogram& that) {
		_point = that._point;
		_width = that._width;
		_heigth = that._heigth;
		_cos = that._cos;
	}

	HTetragon* clone() const override {
		return new HParallelogram(*this);
	}

	Point apexA() const override {
		return _point;
	}
	Point apexB() const override {
		double x = _heigth * _cos;
		double y = sqrt(_heigth * _heigth - x * x);
		return Point(_point.x() + x, _point.y() + y);
	}
	Point apexC() const override {
		return Point(apexB().x() + _width, apexB().y());
	}
	Point apexD() const override {
		return Point(_point.x() + _width, _point.y());
	}

	void setA(const Point& point) override {
		Point b = apexB();
		if (point.y() > b.y()) {
			_point = b;
			_heigth = sqrt((point.x() - b.x()) * (point.x() - b.x()) + (point.y() - b.y()) * (point.y() - b.y()));
			_cos = (point.x() - b.x()) / _heigth;
		}
		else {
			_point = point;
			_heigth = sqrt((point.x() - b.x()) * (point.x() - b.x()) + (point.y() - b.y()) * (point.y() - b.y()));
			_cos = (b.x() - point.x()) / _heigth;
		}
	}
	void setB(const Point& point) override {
		Point a = _point;
		if (point.y() < a.y()) {
			_point = point;
			_heigth = sqrt((point.x() - a.x()) * (point.x() - a.x()) + (point.y() - a.y()) * (point.y() - a.y()));
			_cos = (a.x() - point.x()) / _heigth;
		}
		else {
			_heigth = sqrt((point.x() - a.x()) * (point.x() - a.x()) + (point.y() - a.y()) * (point.y() - a.y()));
			_cos = (point.x() - a.x()) / _heigth;
		}
	}
	void setC(const Point& point) override {
		setB(Point(point.x() - _width, point.y()));
	}
	void setD(const Point& point) override {
		setA(Point(point.x() - _width, point.y()));
	}

	void setWidth(const double& width) {
		if (width <= 0)
			throw "Width must be > 0";
		_width = width;
	}

	double area() const override {
		return _width * _heigth * sqrt(1 - _cos*_cos);
	}

};