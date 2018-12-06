#include "pch.h"
#include <iostream>

using namespace std;

class Circle;

class TextView
{
public:
	TextView(Circle* circle) : _circle(circle) { }
	void display();
private:
	Circle* _circle;
};

class Circle
{
public:
	Circle() : _x(0), _r(0) { }
	void set_x(int x)
	{
		_x = x;
		_tv->display();
	}
	void set_r(int r)
	{
		_r = r;
		_tv->display();
	}
	int get_x() { return _x; }
	int get_r() { return _r; }
	void bind_view(TextView* tv) { _tv = tv; }
private:
	int _x, _r;
	TextView* _tv;
};

void TextView::display()
{
	cout << _circle->get_x() << _circle->get_r() << endl;
}

int main( void )
{
	return 0;
}
