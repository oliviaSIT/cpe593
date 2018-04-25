#include <iostream>
#include <vector>

using namespace std;

class HashMapLinearProbing {
private:
	class Bucket {
	public:
		int val;
		bool present;
		Bucket() { present = false; }
	};
	Bucket *table;
	uint32_t size;
	uint32_t used;
	uint32_t histogram[52] = { 0 };
	void grow() {
		uint32_t oldsize = size;
		Bucket *old = table;
		size *= 2;
		table = new Bucket[size];
		used = 0;
		for (int i = 0; i < oldsize; i++)
			if (old[i].present)
				addHash(old[i].val);
		delete[] old;
		histogram[0] = size - used;
	}
public:
	HashMapLinearProbing(uint32_t initialSize = 1024) :size(initialSize), used(0) {
		int digit = 0;
		for (int i = 0; i < 32; i++) {
			digit += size & 1;
			size = size >> 1;
		}
		size = initialSize;
		if (digit != 1 && !(size & 0x80000000)) {
			int c;
			for (c = 0; c < 32 && !(size & 0x80000000); c++) {
				size = size << 1;
			}
			size = 0x80000000;
			c--;
			while (c) {
				size = size >> 1;
				c--;
			}
		}
		table = new Bucket[size];
		histogram[0] = size - used;
	}
	~HashMapLinearProbing() {
		delete[] table;
	}
	HashMapLinearProbing(const HashMapLinearProbing& orig) :size(orig.size), used(orig.used) {
		table = new Bucket[size];
		for (int i = 0; i < size; i++)
			if (orig.table[i].present) {
				table[i].val = orig.table[i].val;
				table[i].present = true;
			}
		histogram[0] = size - used;
		for (int i = 1; i < 52; i++)
			histogram[i] = 0;
	}
	void addHash(int n) {
		uint32_t index = n & (size - 1);
		uint32_t count = 1;
		while (table[index].present) {
			index++;
			index = index & (size - 1);
			count++;
		}
		table[index].val = n;
		table[index].present = true;
		used++;
		if (count > 50)
			count = 51;
		histogram[count]++;
		histogram[0]--;
		if (used * 2 > size)
			grow();
	}
	bool findHash(int n) {
		uint32_t index = n & (size - 1);
		while (table[index].present) {
			if (table[index].val == n)
				return true;
			index++;
			index = index & (size - 1);
		}
		return false;
	}
	void displayHistogram() {
		for (int i = 0; i < 51; i++)
			cout << i << ":\t" << histogram[i] << endl;
		cout << ">50:\t" << histogram[51] << endl;
	}
};

int main() {
	HashMapLinearProbing hash(8);

/*
	int n;
	cout << "Input n: ";
	cin >> n;
*/

	vector<int> v{1,9,10,17};
	for (int i = 0; i < 4; i++)
		hash.addHash(v[i]);
	hash.displayHistogram();


	//	system("pause");
	return 0;
}
