//풀지 못함. Brute Force 문제임.

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int cnt = 0;
	int N; //N번째를 의미함.
	int standard = 665; //숫자 확인을 위한 기준, 추후 문자열로 변형되어 "666"이 포함되는지 검사
	string cntString;

	cin >> N;

	while (++standard) {
		cntString = to_string(standard); //standard를 문자열로 변경하여 cntString으로 만들어줌.

		if (cntString.find("666") != -1) { //cntString내에서 "666"이라는 문자를 찾았다면, 그건 cnt+1번째 정답이 될 것임.
			++cnt;
		}

		if (cnt == N) { //cnt와 N이 똑같다면 그것은 N번째 수가 된다.
			cout << standard << endl;
			break;
		}
	}

	return 0;
}
