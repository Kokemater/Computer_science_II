#include <iostream>

using namespace std;

class ClassA
{
public:
	void set_a(int val);
	int get_a(void);
private:
	int a;
};

int ClassA::get_a(void)
{
	return a;
}
void ClassA::set_a(int val)
{
	a = val;
}
int main(void)
{
	ClassA a;
	a.set_a(20);
	cout << "a = " << a.get_a() << endl;
	return (0);
}