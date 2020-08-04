#include <iostream>
#include <vector>
using namespace std;

bool isGroupWord(string word) {
	int i, j;
	string tmp;
  
  // word를 한 index씩 탐색하면서 탐색이 끝난 문자를 tmp에 하나씩 덧붙여준다.
  // 만일, word[i]가 tmp내에 존재한다면 경우의 수는 2가지가 있다.
  // 1. 그룹단어가 아닌경우(떨어져 있는 경우) = 이 경우에는 word[i-1] == word[i]가 성립하지 않을 것이다.
  // 2. 그룹단어일 경우 word[i-1] == word[i]가 성립할 것이다.


	for (i = 0; i < word.length(); i++) {
		for (j = 0; j < tmp.length(); j++) {
			if (tmp[j] == word[i]) { 
				if (word[i - 1] == word[i]) continue;
				else return false;
			}
		}
		tmp += word[i];
	}
	
	return true;
}


int main(void) {
	int result = 0; //result: 최종 결과
	int i, N; //N: 단어의 개수, i: iterators
	string word;
	
	cin >> N;
	
	for (i = 0; i < N; i++) {
		cin >> word;
		if (isGroupWord(word)) result++;
	}

	cout << result << endl;

	return 0;
}
