// Trying to answer student questions about directly invoking constructor ...

#include <iostream>
#include <list>
using namespace std;

class TestClass {
public: 
	TestClass() : a(1), b(-1) { cout << "Constructor\n"; }
	TestClass(int x, int y) : a(x), b(y) { cout << "Parameterized constructor\n"; }
	~TestClass() { cout << "Destructor\n"; }
	int a, b;	
};

template <class T>
class TestContainer {
public:
	TestContainer() { cout << "Initially: " << val.a << ' ' << val.b << '\n'; }
	void add(T v) { val = v; cout << "Added: " << val.a << ' ' << val.b << '\n'; }
	T val;
};

int main() {
	TestContainer <TestClass> TC1;
	list <TestClass> L1;

	cout << "Trying to add a value ... \n";
	TC1.add(TestClass(10, -10));
	cout << "Did it work? " << TC1.val.a << ' ' << TC1.val.b << "\n";

	L1.push_back(TestClass(5, -5));
	cout << "Item in L1: " << L1.back().a << ' ' << L1.back().b << "\n";

	return 0;
}