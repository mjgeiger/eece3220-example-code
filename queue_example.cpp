#include <queue>
#include <iostream>

using namespace std;

int main() {
	queue <char>Quirrell;
	string s1 = "stressed";
	string s2 = "insects";
	int i, j;

	for (i = s1.size() - 1; i >= 0; i--)
		Quirrell.push(s1.at(i));			// Remember, s1.at(i) is
											//  similar to s1[i]
	
	// What's state of queue at this point?
	//  (There's no good way in the standard class to print
	//   it without emptying it)

	for (i = 0; i < s2.size(); i += 2) {
		Quirrell.push(Quirrell.front());
		Quirrell.push(s2.at(i));
		for (j = 0; j < 2; j++)
			Quirrell.pop();
	}

	cout << "Final queue state: ";
	while (!Quirrell.empty()) {
		cout << Quirrell.front();
		Quirrell.pop();
	}
	cout << endl;

	return 0;
}