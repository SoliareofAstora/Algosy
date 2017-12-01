#include <string>

struct pair
{
	float x, y;
	bool operator<(pair a) {
		return x < a.x;
	}
	bool operator<=(pair a) {
		return x <= a.x;
	}
	bool operator>(pair a) {
		return x > a.x;
	}
	pair& operator =(pair a) {
		x = a.x;
		y = a.y;
		return *this;
	}
	float operator-(pair a){
		return x - a.x;
	}

	friend std::ostream& operator<<(std::ostream& stream, const pair & a){
		stream << a.x << " x " << a.y;
		return stream;
	}
};

static float distance(pair *a, pair* b)
{
	return sqrt(
		(a->x - b->x)*(a->x - b->x) +
		(a->y - b->y)*(a->y - b->y));
}

static int compareX(const void* a, const void* b)
{
	pair *p1 = (pair *)a;
	pair *p2 = (pair *)b;
	return p1->x > p2->x ? 1 : -1;
}

static int compareY(const void* a, const void* b)
{
	pair *p1 = (pair *)a;
	pair *p2 = (pair *)b;
	return p1->y > p2->y ? 1 : -1;
}