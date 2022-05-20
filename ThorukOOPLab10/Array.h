#include<iostream>

using namespace std;

template <class Elem>
class Array
{
public:
	class BadArray
	{
	public:
		BadArray(size_t index) :_index(index) {};
		const size_t& index() const { return _index; }
	private:
		size_t _index;
	};
	Array(size_t sz) :_size(sz), _ar(new Elem[_size])
	{
	};
	Array(const Array&) = delete;
	Array& operator= (const Array& a) = delete;
	virtual ~Array()
	{
		delete[] _ar;
	};
	Elem& operator[] (size_t index)
	{
		if (index >= _size)
			throw BadArray(index);
		return _ar[index];
	}
	const Elem& operator[] (size_t index) const
	{
		if (index >= _size)
			throw BadArray(index);
		return _ar[index];
	}
	size_t size() const
	{
		return _size;
	}

private:
	size_t _size;
	Elem* _ar;
};
