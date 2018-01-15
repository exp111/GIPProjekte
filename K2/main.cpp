#include <iostream>
using namespace std;
int main() {
	for (int i = 1; i < 3; i++) {
		for (int k = 1; k <= 4; k++) {
			cout << i << " und " << k << endl;
			if (k == 3) {
				cout << "Break if-3" << endl;
				break;
			}
			switch (k) {
			case 2:
				cout << "Break case-2" << endl;
				break;
			case 3:
				cout << "Break case-3" << endl;
				break;
			}
		}
	}
	system("PAUSE"); //for debugging purposes
	return 0;
}