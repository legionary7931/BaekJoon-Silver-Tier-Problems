#include <iostream>
using namespace std;

int gcd(int a, int b) { // 호제법 => gcd(a, b) = gcd(b, r), r = a % b
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b, int c) { //lcm(a, b, c) = lcm(a, lcm(b, c))
	int tmp; //tmp = lcm(b, c)
	tmp = (b * c) / gcd(b, c); //lcm(b, c) = (b * c) / gcd (b * c)

	return (a * tmp) / gcd(a, tmp);
}


int main(void) {
	int min = 987654321;
	int i, j, k;
	int* arr = new int[5];
	
	for (i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 5; j++) {
			for (k = j + 1; k < 5; k++) {
				if (min > lcm(arr[i], arr[j], arr[k])) min = lcm(arr[i], arr[j], arr[k]);
			}
		}
	}

	cout << min << endl;
	
	return 0;
}
