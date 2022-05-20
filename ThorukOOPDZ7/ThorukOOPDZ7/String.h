#include<iostream>

using namespace std;

class String {
	char* _str;
	size_t _len;
public:
	String();
	String(const char ch);
	String(const char* str);
	String(const string& str);
	String(const String& str);
	String(const String& str, const unsigned int multiplayer);
	String(String&& str) noexcept;

	~String();

	operator const char* () const;
	operator string () const;

	size_t length() const { return _len; }
	const char* c_str() const { return _str; }

	String& operator=(const char ch);
	String& operator=(const char* str);
	String& operator=(const String& str);

	char& operator[](const size_t i);
	const char& operator[](const size_t i) const;
	String operator+(const String& str) const;
	bool operator==(const String& str) const;
	bool operator!=(const String& str) const{
		return !(*this == str);
	}

};

ostream& operator<<(ostream& os, const String& str);
