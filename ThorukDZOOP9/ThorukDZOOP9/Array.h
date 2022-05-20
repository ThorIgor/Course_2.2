#include<iostream>

using namespace std;

class BadIndex {
	size_t _index;
public:
	BadIndex(const size_t index) : _index(index) {}
	~BadIndex() {}
	
	size_t index() const{
		return _index;
	}
};

template <const size_t n, typename Type>
class Array {
	const size_t _size;
	Type* _array;

	Array(const Array&);
	Array& operator=(const Array&);
public:
	Array() :_size(n), _array(new Type[_size]) {};
	~Array() { delete[] _array; }

	Type& operator[](const size_t index) {
		if (index >= _size)
			throw BadIndex(index);
		return _array[index];
	}
	const Type& operator[](const size_t index) const {
		if (index >= _size)
			throw BadIndex(index);
		return _array[index];
	}

	size_t size() const {
		return _size;
	}
};

template<size_t size, typename Type>
ostream& operator<<(ostream& os, const Array<size, Type>& arr) {
	os << "{ ";
	for (int i = 0; i < arr.size(); i++)
		os << arr[i] << " ";
	os << "}";
	return os;
}

ostream& operator<<(ostream& os, const BadIndex& er) {
	os << er.index() << " is invalid index";
	return os;
}
