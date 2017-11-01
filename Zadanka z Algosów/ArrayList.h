#ifndef ArrayList_h
#define ArrayList_h

class ArrayList
{
	int tab[10000];
	int firstFree;

public:
	ArrayList();
	~ArrayList();
	void push_front(int value);
	int pop_front();
	void push_back(int value);
	int pop_back();
	int* find(int value);
	int size() const;
};

#endif