#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string N;
	int result = 0, max = 0, numcnt[10] = { 0, };

	cin >> N;

	for (int i = 0; i < N.length(); i++) {
		numcnt[N[i] - '0']++;
	} //숫자 문자열에 들어가는 숫자의 종류별로 카운트
	max = (numcnt[6] + numcnt[9]) / 2; //일단 6, 9가 기준이 되어야 함.
	if ((numcnt[6] + numcnt[9]) % 2 == 1) max++; //6, 9가 총 홀수 번 나올 경우, 나누기 2했을때 1개 더 큰 숫자 세트가 필요함.

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue; //6, 9는 이미 카운트 했으므로 세지 않음.
		if (max < numcnt[i]) max = numcnt[i]; //가장 많이 나온 숫자의 개수만큼 숫자 세트를 준비해야 한다.
	}

	cout << max << endl;

	return 0;
}
