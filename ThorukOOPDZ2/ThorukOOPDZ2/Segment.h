// 02LAB. Реалізувати і протестувати тип даних Segment



//*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by .....................

//at ....................

//Version 1.0

//*******************************************

#include"Point.h"


// Клас відрізків

class Segment

{

private:

	// Засоби облікування відрізків
	static int _freeID;
	const int _myId;

	// Точка початку відрізку
	Point _a;
	// Точка кінця відрізку
	Point _b;

public:

	// Конструктори відрізків

	// 1) за координатами його кінців
	Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0);

	// 2) за точками початку і кінця
	Segment(const Point& start, const Point& end);

	// 3) копіювальний конструктор
	Segment(const Segment&);

	// Деструктор
	~Segment();

	// Присвоєння
	Segment& operator=(const Segment&);

	// Селектори  точок
	const Point& start() const { return _a; }
	const Point& end() const { return _b; }

	// Селектори-модифікатори точок
	Point& start() { return _a; }
	Point& end() { return _b; }

	// Селектори координат точок
	const double& startX() const { return _a.x(); }
	const double& startY() const { return _a.y(); }
	const double& endX() const { return _b.x(); }
	const double& endY() const { return _b.y(); }

	// Селектори-модифікатори координат точок
	double& startX() { return _a.x(); }
	double& startY() { return _a.y(); }
	double& endX() { return _b.x(); }
	double& endY() { return _b.y(); }

	// Обчислення довжини відрізка
	double length() const;

	// Обчислення відстані від відрізка до точки
	double distance(const Point&) const;

	// Селектор ID
	const int getID() const { return _myId; }

};

ostream& operator<<(ostream&, const Segment&);
