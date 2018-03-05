// created by Jiabin.Li

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

	Point(double x, double y):x(x), y(y) {}
};

class GrowArray {
public:
	Point data[];
	int used;

	GrowArray(int size = 0) {
		size = 0 ? 1 : size;

		data = new Point[size];
		used = 0; 
	}

	void grow() {
		if (used < data.length())
			return;

		//int t[] = data;//not right
		Point* old = data;
//		for (int i = 0; i < data.length(); i++) {
//			t[i] = data[i];
//		}

		data = new Point[2 * data.length()];

		for (int i = 0; i < used; i++) {
			data[i] = old[i];
		}

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

class ConvexHull {
public:
	GrowArray data[];
	int size;
	double minx, miny, maxx, maxy;

	ConvexHull(int s) {
		data = new GrowArray[s * s];
		size = s;

		for (int i = 0; i < s * s; i++) {
			data[i] = new GrowArray();
		}
	}

	void read(const string& filename) {
		fstream f(filename);
		GrowArray t = new GrowArray();
		double minx = DBL_MAX, miny = DBL_MAX, maxx = DBL_MIN, maxy = DBL_MIN;
		
		double x, y;
		string line;
		f.open();
		while (!f.eof()) {
			getline(f, line);
			istringstream iss(line);
			iss >> x;
			iss >> y;

			minx = x > minx ? minx : x;
			miny = y > miny ? miny : y;
			maxx = x > maxx ? x : maxx;
			maxy = y > maxy ? y : maxy;

			Point tp(x, y);
			t.addEnd(tp);
		}
		f.close();

		double rangx = (maxx - minx) / size;
		double rangy = (maxy - miny) / size;

		for (int i = 0; i < t.length(); i++) {
			Point p = t.get(i);
			int xx = (int)((p.x - minx) / rangx);
			int yy = (int)((p.y - miny) / rangy);
			xx = xx == size ? xx - 1 : xx;
			yy = yy == size ? yy - 1 : yy;

			data[xx * size + yy].addEnd(p);
		}
		
		f.close();
	}

	void printMinMax() {
		cout << "minx:" << minx << " miny:" << miny << " maxx:" << maxx << " maxy" << maxy << endl;
	}

	void printAllListSizes() {
		cout << "the size of all lists:" << endl;

		for (auto i: data ) {
			cout << "p" << to_string(i + 1) << ":" << i.length() << endl;
		}
	}

	void printPerimeterClockOrder() {
		cout << "the points in all lists:" << endl;
		for (auto i: data ) {
                        cout << "p" << to_string(i + 1) << ":" << endl;

			for (auto j: i) {
				cout << "(" << j.x << ", " << j.y << ")" << endl;
			}
                }

	}
	
	~ConvexHull() {
		delete[] data;
	}
};

int main() {
  // for homework n=16
	ConvexHull ch(16); // create a 16x16 grid of GrowArray
	ch.read("convexhullpoints.dat");
	ch.printAllListSizes(); // tell us how many are in each list
	ch.printMinMax(); // print minx, maxx, miny, maxy
	ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4,p8,p12,p16..

	return 0;
}  
