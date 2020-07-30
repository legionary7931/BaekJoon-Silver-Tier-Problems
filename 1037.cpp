#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(void) {
	int num, answer;
	cin >> num;

	vector<int> realnum(num);
	for (int i = 0; i < num; i++) {
		cin >> realnum[i];
	}

	sort(realnum.begin(), realnum.end()); //진짜약수가 꼭 오름차순으로만 주어지지 않으므로, 오름차순 정렬을 해주는 과정이 필요하다.
	answer = realnum.front() * realnum.back();
	cout << answer;

	return 0;
}
