#include <iostream>

using namespace std;

int board[9][9];  // 스도쿠 보드

// 스도쿠 보드 출력 함수
void printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 해당 위치에 숫자를 넣을 수 있는지 확인하는 함수
bool isValid(int row, int col, int num) {
    // 가로줄 확인
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // 세로줄 확인
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // 3x3 박스 확인
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// 스도쿠를 푸는 함수 (백트래킹)
bool solveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            // 빈 칸(0)을 찾으면 숫자를 넣어본다
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    // 유효한 숫자인지 확인하고, 맞다면 숫자를 넣는다
                    if (isValid(row, col, num)) {
                        board[row][col] = num;

                        // 재귀적으로 다음 빈칸을 탐색
                        if (solveSudoku()) {
                            return true;
                        }

                        // 실패하면 다시 빈 칸으로 되돌림
                        board[row][col] = 0;
                    }
                }
                return false;  // 가능한 숫자가 없으면 false 리턴
            }
        }
    }
    return true;  // 모든 칸을 채우면 true 리턴
}

int main() {
    // 스도쿠 보드 입력 받기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    // 스도쿠 풀이 시작
    if (solveSudoku()) {
        printBoard();  // 성공하면 보드 출력
    } else {
        cout << "No solution exists\n";  // 해답이 없으면 출력
    }

    return 0;
}
