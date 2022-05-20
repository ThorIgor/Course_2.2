#include"Sequence.h"

void main() {
	try {
		Sequence<double> seq;
		for(int i = 0; i < 5; i++)
			seq.add(5);
		seq.insert(4, 2);
		seq.insert(2, 4);
		seq.cut();
		if (seq.contains(4))
			cout << seq << " contains 4" << endl;
		seq.remove(1);
		if (!seq.contains(4))
			cout << seq << " not contains 4" << endl;
		cout << seq << endl;
	}
	catch (Sequence<class Elem>::BadSeq bs) {
		cout << bs.explain() << endl;
	}
}