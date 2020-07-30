#include <iostream>

using namespace std;

//하얀색이 먼저인 체스판이라면, 행+열 = 짝수라면 하얀색, 행+열 = 홀수라면 검은색이어야 한다.
//검은색이 먼저인 체스판이라면, 행+열 = 홀수라면 하얀색, 행+열 = 짝수라면 검은색이어야 한다.

int isWhiteBoard(char** board, int N, int M) {
	int result = 0; //고쳐야 되는 체스판 칸 수
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((N + i + M + j) % 2 == 0 && (board[N + i][M + j] == 'B')) result++;
			if ((N + i + M + j) % 2 == 1 && (board[N + i][M + j] =='W')) result++;
		}
	}
	return result;
}

int isBlackBoard(char** board, int N, int M) {
	int result = 0;
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((N + i + M + j) % 2 == 0 && (board[N + i][M + j] == 'W')) result++;
			if ((N + i + M + j) % 2 == 1 && (board[N + i][M + j] == 'B')) result++;
		}
	}

	return result;
}

int min(int num1, int num2) {
	if (num1 >= num2) return num2;
	else return num1;
}

int main(void) {
	int M, N; // N = 가로, M = 세로
	int i, j, tmp = 0, result = 64; // i, j = iterators, min = 최소로 바꿔야 되는 칸 개수
	cin >> N >> M;

	char** board = new char* [N+1];
	for (i = 0; i < N+1; i++) {
		board[i] = new char[M+1];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	
	for (i = 0; i + 8 <= N; i++) {
		for (j = 0; j + 8 <= M; j++) {
			tmp = min(isWhiteBoard(board, i, j), isBlackBoard(board, i, j));
			if (result > tmp) result = tmp;
		}
	} 
	cout << result;

	return 0;
}

/* 
원래 결과 산출하는 부분을 
result = 0으로 두고
for (i = 0; i + 8 <= N; i++) {
		for (j = 0; j + 8 <= M; j++) {
			tmp = min(isWhiteBoard(board, i, j), isBlackBoard(board, i, j));
      if(result ==0){
        result = tmp;
        continue;
      }
      if (result > tmp) result = tmp;
		}
}
이렇게 두면, 만일 9*9 보드에서 오른쪽 구석에 있는 칸만 잘못된 칸이라면, tmp는 계속 0이다가 맨 마지막에서 result = 0 조건에 걸려 result를 1로 출력한다.
*/
