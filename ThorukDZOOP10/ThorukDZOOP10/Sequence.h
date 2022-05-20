#include"Array.h"

template<typename Elem>
class Sequence {
public:
	class BadSeq {
	private:
		string _explain;
	public:
		BadSeq(string str) : _explain(str) {};
		const string& explain() { return _explain; }
	};
	explicit Sequence(const size_t capacity = _default) : _size(0), _allocator(new Array<Elem>(capacity)) {}
	~Sequence() { delete _allocator; }

	size_t capacity() const { return _allocator->size(); }
	size_t size() const { return _size; }
	bool empty() const { return _size == 0; }
	bool full() const { return size() == capacity(); }

	Sequence& clear() {
		_size = 0;
		return *this;
	}

	const Elem& operator[](const size_t index) const {
		if (index >= _size)
			throw BadSeq("Index is out of bounds");
		return _allocator->operator[](index);
	}
	Elem& operator[](const  size_t index) {
		if (index >= _size)
			throw BadSeq("Index is out of bounds");
		return _allocator->operator[](index);
	}

	Sequence& add(const Elem& elem) {return doinsert(elem, _size);}
	Sequence& insert(const Elem& elem, const  size_t index) {
		if (index >= _size)
			throw BadSeq("Index is out of bounds");
		return doinsert(elem, index);
	}

	Sequence& cut() {return doremove(0);}
	Sequence& remove(const size_t index) {
		if (index >= _size)
			throw BadSeq("Index is out of bounds");
		return doremove(index);
	}

	bool contains(const Elem& elem) {
		for (int i = 0; i < _size; i++)
			if (_allocator->operator[](i) == elem)
				return true;
		return false;
	}
private:
	size_t _size;
	static const size_t _default = 0;
	Array<Elem>* _allocator;


	void reduce(const size_t times = 2) {
		Array<Elem>* reducedCopy = new Array<Elem>(capacity() / times);
		for (int i = 0; i < reducedCopy->size(); i++)
			reducedCopy->operator[](i) = _allocator->operator[](i);
		delete _allocator;
		_allocator = reducedCopy;
	}
	void enlarge(const size_t times = 2) {
		Array<Elem>* enlargedCopy = new Array<Elem>(capacity() * times + 1);
		for (int i = 0; i < _allocator->size(); i++)
			enlargedCopy->operator[](i) = _allocator->operator[](i);
		delete _allocator;
		_allocator = enlargedCopy;
	}

	Sequence& doinsert(const Elem& elem, const size_t index) {
		if (_size + 1 > capacity())
			enlarge();
		++_size;
		for (size_t i = _size - 1; i > index; --i)
			_allocator->operator[](i) = _allocator->operator[](i - 1);
		_allocator->operator[](index) = elem;
		return *this;

	}
	Sequence& doremove(const size_t index) {
		if (empty())
			throw BadSeq("The sequence is empty");
		--_size;
		if (capacity() / 2 > size())
			reduce();
		for (size_t i = index; i < _size - 1; ++i)
			_allocator->operator[](i) = _allocator->operator[](i + 1);
		return *this;
	}

	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);
};

template<typename Elem>
ostream& operator<<(ostream& os, const Sequence<Elem>& seq) {
	os << "{ ";
	for (int i = 0; i < seq.size(); i++)
		os << seq[i] << " ";
	os << "}";
	return os;
}
