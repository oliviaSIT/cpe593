//created by Jiabin Li

#include <iostream>

using namespace std;

class HashMapLinearProbing {
private:
	class Bucket {
	public:
		int val;
		bool exist;
		Bucket() { 
			exist = false; 
		}
	};

	Bucket* bin;
	uint32_t size;
	uint32_t used;
	uint32_t histogram[52] = {0};
	void grow() {
		uint32_t oldsize = size;
		Bucket* old = bin;
		size *= 2;
		bin = new Bucket[size];
		used = 0;
		for (int i = 0; i < (int)oldsize; i++) {
			if (old[i].exist)
				add(old[i].val);
		}

		delete[] old;
		histogram[0] = size - used;
	}

public:
	HashMapLinearProbing(uint32_t initialSize = 1024): size(initialSize), used(0) {
		uint32_t i = 1, n = 0;

		while (i < size && n < 32) {
			i *= 2;
			n++;
		}

		size = i;

		bin = new Bucket[size];
		histogram[0] = size - used;
	}

	~HashMapLinearProbing() {
		delete[] bin;
	}

	HashMapLinearProbing(const HashMapLinearProbing& orig) :size(orig.size), used(orig.used) {
		bin = new Bucket[size];

		for (int i = 0; i < (int)size; i++) {
			if (orig.bin[i].exist) {
				bin[i].val = orig.bin[i].val;
				bin[i].exist = true;
			}
		}

		histogram[0] = size - used;

		for (int i = 1; i < 52; i++)
			histogram[i] = 0;
	}

	void add(int n) {
		uint32_t index = n % size;
		uint32_t count = 1;

		while (bin[index].exist) {
			index++;
			index = index % size;
			count++;
		}

		bin[index].val = n;
		bin[index].exist = true;
		used++;

		if (count > 50)
			count = 51;

		histogram[count]++;
		histogram[0]--;

		if (used * 2 > size)
			grow();
	}

	bool find(int n) {
		uint32_t index = n % size;

		while (bin[index].exist) {
			if (bin[index].val == n)
				return true;

			index++;
			index = index % size;
		}

		return false;
	}

	void displayHistogram() {
		for (int i = 0; i < 51; i++)
			cout << i << ": " << histogram[i] << endl;
		cout << ">50: " << histogram[51] << endl;
	}
};

int main() {
	HashMapLinearProbing m;

	int n;
	cout << "Please input n: ";
	cin >> n;

/*
	vector<int> v{1,9,10,17};
	for (int i = 0; i < 4; i++)
		m.add(v[i]);
*/
	
	for (int i = 0; i < n; i++)
		m.add(rand());
	
	m.displayHistogram();

	return 0;
}
