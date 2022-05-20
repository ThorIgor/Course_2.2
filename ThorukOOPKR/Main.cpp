#include"HSquare.h"

void main() {
	HRectangle rec(Point(0, 0), 4, 3);
	HRectangle smallRec(Point(1, 1), 1, 1);
	cout << rec << endl;
	cout << rec.side_a() << endl;
	if (smallRec < rec)
		cout << "<" << endl;
	else
		cout << ">" << endl;
	rec.setD(Point(-1, 5));
	cout << rec << endl;

	HSquare sq(Point(0, 0), 4);
	HSquare smallSq(Point(1, 1), 2);
	cout << sq << endl;
	cout << sq.side_a() << endl;
	if (smallSq < sq)
		cout << "<" << endl;
	else
		cout << ">" << endl;
	sq.setA(Point(1, 2));
	cout << sq << endl;
	cout << sq + smallSq << endl;
	
	Container container;
	container.add(rec);
	container.add(smallRec);
	container.add(sq);
	cout << container << endl;
	cout << container.sum() << endl;
	cout << container.less(smallSq) << endl;
	container.add(smallSq);
	cout << container.capacity() << endl;
	delete& container.pop();
	delete& container.pop();
	delete& container.pop();
	cout << container.capacity() << endl;
	delete& container.pop();
	cout << container.capacity() << endl;
	try {
		container[6];
	}
	catch (const char* error) {
		cout << error << endl;
	}

	HParallelogram par(Point(0, 0), 5, 4, 0.5);
	cout << par << endl;
	cout << par.area() << endl;
	if (rec < par)
		cout << "<" << endl;
	cout << rec + par << endl;
	par.setD(Point(1, 7));
	cout << par << endl;

	container.add(rec);
	container.add(par);
	container.add(rec + par);
	cout << container << endl;

	HRhomb romb(Point(0, 0), 6, 0.5);
	cout << romb << endl;
	if (par < romb)
		cout << "<" << endl;
	cout << par + romb << endl;
	romb.setA(Point(1, 3));
	cout << romb << endl;

	container.add(romb);
	cout << container << endl;
	cout << container.sum() << endl;
	cout << container.less(sq) << endl;
}
