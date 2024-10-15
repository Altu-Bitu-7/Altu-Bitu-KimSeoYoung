#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr[1001];    // 수열 배열
    int dp[1001];     // 해당 인덱스까지의 가장 긴 증가하는 부분 수열의 길이
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // DP 초기화
    for (int i = 0; i < n; i++) {
        dp[i] = 1;  // 모든 수는 최소한 자기 자신을 포함하는 길이 1의 증가 수열을 가짐
    }
    
    // DP 계산
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    // 가장 긴 증가하는 부분 수열의 길이 구하기
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }
    
    cout << result << '\n';
    
    return 0;
}
