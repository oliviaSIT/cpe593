#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

class Point {
public:
	double x, y;

	Point(double x = 0, double y = 0):x(x), y(y) {}
};

class GrowArray {
public:
	Point* data;
	int used;
	int size;

	GrowArray(int s = 0) {
		size = s == 0 ? 1 : s;

		data = new Point[size];
		used = 0; 
	}

	void grow() {
		if (used < size)
			return;

		//int t[] = data;//not right
		Point* old = data;
//		for (int i = 0; i < data.length(); i++) {
//			t[i] = data[i];
//		}

		data = new Point[2 * size];

		for (int i = 0; i < used; i++) {
			data[i] = old[i];
		}
		
		size *= 2;
		delete[] old;
	}

	int length() {
		return used;
	}

	Point get(int index) {
		return data[index];
	}

	void addEnd(Point p) {
		grow();
		data[used++] = p;
	}

	~GrowArray() {
		delete[] data;
	}

};

int main() {
	Point p1(2.1, 5.4), p2(3.9, 1.1), p3(-2.3, -3.9);
	GrowArray a(2);
	cout << a.length() << ' ' << a.size << endl;
	a.addEnd(p1);
	a.addEnd(p2);
	a.addEnd(p3);
	cout << a.length() << ' ' << a.size << endl;
	cout << a.get(a.length() - 1).x << endl;
	return 0;
}
