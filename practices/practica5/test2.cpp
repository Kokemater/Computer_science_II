#include <iostream>

using namespace std;

class ClassA
{
private:
	int x;
	int y;
public:
	void hi(void);
	void set_x_y(int xval, int yval);
	int get_x(void);
	int get_y(void);
};
void ClassA::hi(void)
{
	cout << "hi" << endl;
}
void ClassA::set_x_y(int xval, int yval)
{
	x = xval;
	y = yval;
}
int ClassA::get_x(void)
{
	return x;
}
int ClassA::get_y(void)
{
	return y;
}

int main(void)
{
	ClassA a;
	a.set_x_y(1,2);
	a.hi();
	cout << a.get_x() << endl;
	cout << a.get_y() << endl;
 }