#ifndef ArrayList_h
#define ArrayList_h

template <typename T>
class SortedArrayList
{
	T tab[1000000];
	int firstFree;

public:
	SortedArrayList();
	~SortedArrayList();


	void push(T value);
	void pushSorted(T value);
	T pop();
	T erase(int i);
	int find(T value);
	int size() const;
	void remove(int value);
	void print();
	void unique();
	T getValue(int i) const;
	int maxElements() const { return sizeof tab / sizeof T; }
	static SortedArrayList merge(const SortedArrayList& a,
	                             const SortedArrayList& b);
};

#endif
