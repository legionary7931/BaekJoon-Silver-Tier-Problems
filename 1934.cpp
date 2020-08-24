#include <iostream>
using namespace std;

int gcd(int a, int b) { //호제법 -> gcd(a,b)=gcd(b,r) (r = a%b)
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) { //lcm(a, b) = (a*b)/gcd(a, b)
	return (a * b) / gcd(a, b);
}

int main(void) {
	int T, a, b;
	cin >> T;

	int* result = new int[T];

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		result[i] = lcm(a, b);
	}

	for (int i = 0; i < T; i++) {
		cout << result[i] << endl;
	}
	return 0;
}
