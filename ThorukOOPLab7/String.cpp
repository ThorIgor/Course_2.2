#include "String.h"
#pragma warning(disable : 4996)

#define DEBUG

String::String() : _len(0), _str(new char[1])
{
#ifdef DEBUG
	cout << "Default constructor" << endl;
#endif
	_str[0] = '\0';
}

String::String(const char ch) : _len(1), _str(new char[2])
{
#ifdef DEBUG
	cout << ch << " constructor" << endl;
#endif
	_str[0] = ch;
	_str[1] = '\0';
}

String::String(const char* str)
{
#ifdef DEBUG
	cout << str << " constructor" << endl;
#endif
	if (str == nullptr)
		throw "Error, string is nullptr";
	_len = strlen(str);
	_str = new char[_len + 1];
	strcpy(_str, str);
}

String::String(const string& str) : _len(str.length()), _str(new char[_len+1])
{
#ifdef DEBUG
	cout << str << " constructor" << endl;
#endif
	strcpy(_str, str.c_str());
}

String::String(const String& str)
{
#ifdef DEBUG
	cout << str << " copy constructor" << endl;
#endif
	_len = str.length();
	_str = new char[_len + 1];
	strcpy(_str, str._str);
}

String::String(const String& str, const unsigned int multiplayer) : _len(str._len*multiplayer), _str(new char[_len+1])
{
#ifdef DEBUG
	cout << str << " multcopy constructor" << endl;
#endif
	char* target = _str;
	for (int i = 0; i < multiplayer; i++) {
		strcpy(target, str._str);
		target += str._len;
	}
}

String::String(String&& str) noexcept: _len(str._len), _str(str._str)
{
#ifdef DEBUG
	cout << str << " cut constructor" << endl;
#endif
	str._str = nullptr;
}

String::~String()
{
#ifdef DEBUG
	cout << _str << " deconstructor" << endl;
#endif
	delete[] _str;
}

String::operator const char* () const
{
	return _str;
}

String::operator string() const
{
	return string(_str);
}

String& String::operator=(const char ch)
{
	delete[] _str;
	_str = new char[2];
	_str[0] = ch; _str[1] = '\0';
	_len = 1;
	return *this;
}

String& String::operator=(const char* str)
{
	if (str == nullptr)
		return *this;
	delete[] _str;
	_len = strlen(str);
	_str = new char[_len + 1];
	strcpy(_str, str);
	return *this;
}

String& String::operator=(const String& str)
{
	*this = str._str;
	return *this;
}

ostream& operator<<(ostream& os, const String& str)
{
	for (size_t i = 0; i < str.length(); i++) os << str[i];
	return os;
}

char& String::operator[](const size_t i)
{
	if (i >= _len)
		throw "Error, out of bounds";
	return _str[i];
}

const char& String::operator[](const size_t i) const
{
	if (i >= _len)
		throw "Error, out of bounds";
	return _str[i];
}

String String::operator+(const String& str) const
{
	char* temp = new char[_len + str._len + 1];
	strcpy(temp, _str);
	strcpy(temp + _len, _str);
	return String(temp);
}

bool String::operator==(const String& str) const
{
	bool equal = _len == str._len;
	for (int i = 0; (i < _len) && equal; i++)
		equal = *(_str + i) == *(str._str + i);
	return equal;
}
