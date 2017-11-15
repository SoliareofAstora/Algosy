#ifndef ArrayList_h
#define ArrayList_h

class SortedArrayList
{
	int tab[10000];
	int firstFree;

public:
	SortedArrayList();
	~SortedArrayList();


	void push(int value);
	void pushSorted(int value);
	int pop();
	int erase(int i);
	int find(int value);
	int size() const;
	void remove(int value);
	void print();
	void unique();
	int getValue(int i) const;
	int maxElements() const { return sizeof tab / 4; }
	static SortedArrayList merge(const SortedArrayList& a,
	                             const SortedArrayList& b);
};

#endif
