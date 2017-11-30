struct pair
{
	float x, y;
	bool operator<(pair a) {
		return x < a.x;
	}
	bool operator>(pair a) {
		return x > a.x;
	}
	pair& operator =(pair a) {
		x = a.x;
		y = a.y;
		return *this;
	}
};

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