	#include <iostream>
	#include <vector>

	using namespace std;

	long long combination(int n, int r) {
		static long long ans[30][30] = { 0, };
		if (ans[n][r] > 0) return ans[n][r];
		if (n == r || r == 0) return ans[n][r] = 1;
		return ans[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
	}


	int main(void) {
		int num, n, m; 
		vector<long long> result;

		cin >> num;
		result.assign(num, 0);

		for (int i = 0; i < num; i++) {
			cin >> n;
			cin >> m; 
			result[i] = combination(m, n);
		}

		for (int i = 0; i < num; i++) {
			cout << result[i];
			cout << "\n";
		}

		return 0;
	}
