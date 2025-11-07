#include <stack>
#include <iostream>

using namespace std;

int main() {
	stack <int> s1;
	stack <double> s2;
	int i;

	for (i = 0; i < 10; i++) {
		s1.push(i);
		s2.push(i * 1.5);
	}

	while (!s1.empty()) {
		cout << "Top of s1: " << s1.top() << endl
			<< "Top of s2: " << s2.top() << endl;
		s1.pop();
		s2.pop();
	}

	return 0;
}