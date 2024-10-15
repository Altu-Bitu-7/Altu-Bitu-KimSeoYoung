#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 입력
    int n;
    cin >> n;
    
    int stairs[301] = {0};  // 계단의 점수 배열
    int dp[301] = {0};      // 해당 계단까지의 최대 점수 저장 배열
    
    // 구현
    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }
    
    // 초기값 설정
    dp[1] = stairs[1];
    if (n >= 2) {
        dp[2] = stairs[1] + stairs[2];
    }
    
    // DP 계산
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-2], dp[i-3] + stairs[i-1]) + stairs[i];
    }
    
    // 출력
    cout << dp[n] << '\n';
    
    return 0;
}