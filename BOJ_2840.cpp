#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic; // int와 char의 쌍을 간단히 ic로 표현
const int ALPHA = 26; // 알파벳의 개수 (A-Z까지 26개)

// index부터 시계방향으로 바퀴에 적어놓은 알파벳을 출력하는 함수
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = ""; // 최종 결과를 저장할 문자열
    // 바퀴를 돌릴 때와 반대방향으로 출력
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n]; // 현재 index에서 시계 반대방향으로 돌면서 문자 추가
    }
    return ans; // 결과 문자열 반환
}

// 행운의 바퀴 반환
string makeWheel(int n, int k, vector<ic>& record) {
    vector<char> wheel(n, '?'); // 바퀴의 모든 칸을 '?'로 초기화
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크용 배열

    int index = 0; // 화살표가 가리키는 인덱스 (처음에는 0)

    for (int i = 0; i < k; i++) {
        int s = record[i].first; // 화살표가 가리키는 글자가 변하는 횟수 (시계방향으로 회전할 칸 수)
        char ch = record[i].second; // 회전을 멈추었을 때 가리키던 글자

        index = (index + s) % n; // 회전한 후 화살표가 가리키는 인덱스 계산

        // 해당 칸이 이미 ch로 채워져 있는 경우, 문제없으므로 다음 단계로 진행
        if (wheel[index] == ch) {
            continue;
        }

        // 다른 글자로 이미 채워져 있거나, ch가 이미 사용된 알파벳인 경우 실패 처리 ('!' 반환)
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!"; // 무결성 위반 발생 시 '!' 반환
        }

        wheel[index] = ch; // 바퀴의 해당 칸에 글자 ch를 적음
        is_available[ch - 'A'] = true; // 해당 알파벳이 사용되었음을 기록
    }
    return printWheel(n, index, wheel); // 최종적으로 바퀴 상태를 반환
}

int main() {
    ios::sync_with_stdio(false); // C++ 표준 입출력 속도 향상
    cin.tie(NULL); cout.tie(NULL); // 입출력 묶음 해제

    // 입력
    int n, k;
    cin >> n >> k; // n: 바퀴 칸 수, k: 명령 수

    vector<ic> record(k); // 명령을 저장할 벡터
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second; // 각 명령 입력
    }

    // 연산 및 출력
    cout << makeWheel(n, k, record); // 행운의 바퀴 생성 및 출력

    return 0; // 프로그램 종료
}