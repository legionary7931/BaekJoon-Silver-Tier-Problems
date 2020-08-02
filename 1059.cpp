#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(void) {
	int i, L, N; //i = iterator, L = Lucky Set에 들어가 있는 숫자의 개수, N = Lucky set에서 가장 큰 수보다 작거나 같은 자연수
	int small = 0, big = 0, result = 0;
	cin >> L;
	
	vector<int> num(L);
	for (i = 0; i < L; i++) {
		cin >> num[i];
	}

	cin >> N;
	
	sort(num.begin(), num.end());

	if (N < num[0]) {
		small = 1;
		big = num[0] - 1;

		result = (N - small) + (big - N) + ((N - small) * (big - N));
		cout << result << endl;
		return 0;
	} //N이 Lucky Set의 모든 원소보다 작을때

	for (i = 0; i < L; i++) {
		if (num[i] == N) {
			result = 0;
			cout << result << endl;
			return 0;
		} // N이 Lucky Set 원소중 하나일떄
		
		if (num[i] < N && N < num[i + 1]) {
			small = num[i];
			big = num[i + 1];
			result = (N - small - 1) + (big - N - 1) + ((N - small - 1) * (big - N - 1));
			break;
		} // N이 범위 중간에 들어갈때 
	}

	//cout << small << " " << big << endl;

	cout << result << endl;
	return 0;
}

//case를 잘 나누어서 풀어야 함. 경계값 주의!
//N이 Lucky Set의 모든 원소보다 작을 때, N이 Lucky Set의 원소 중 하나일때, N이 Lucky Set 범위의 중간에 들어갈 떄로 case를 나누어서 각기 다른 식을 적용해야 함
