#include <iostream>
#include <vector>

using namespace std;

int main() {
    //입력
    int N;
    cin >> N;
    vector<long long> speeds(N);
    
    //구현
    // 각 평행 우주의 속도 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> speeds[i];
    }
    
    // 마지막 평행 우주의 요구 속도가 초기 최소 속도
    long long min_speed = speeds[N - 1];
    
    // 역순으로 최소 요구 속도를 계산
    for (int i = N - 2; i >= 0; i--) {
        // 올림 처리: (min_speed + speeds[i] - 1) / speeds[i]
        if (min_speed % speeds[i] != 0) {
            min_speed = (min_speed / speeds[i] + 1) * speeds[i];
        }
    }
    //출력
    cout << min_speed << "\n";
    return 0;
}
