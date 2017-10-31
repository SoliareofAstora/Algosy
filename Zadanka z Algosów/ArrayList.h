#ifndef ArrayList_h
#define ArrayList_h

class ArrayList
{
 int tab[10000];
 int firstFree;

public:
	ArrayList();
	 void push_front(int x);
	 int pop_front();
	 void push_back(int x);
	 int pop_back();
	 int* find(int x);
	 int size() const;
};

#endif