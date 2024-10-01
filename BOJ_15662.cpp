#include <iostream>
#include <vector>

using namespace std;

vector<int> gears[1001];  // 최대 1000개의 톱니바퀴

// 톱니바퀴를 회전시키는 함수
void rotate_gear(int gear_idx, int direction) {
    if (direction == 1) {  // 시계 방향 회전
        int last = gears[gear_idx].back();
        gears[gear_idx].pop_back();
        gears[gear_idx].insert(gears[gear_idx].begin(), last);
    } else {  // 반시계 방향 회전
        int first = gears[gear_idx].front();
        gears[gear_idx].erase(gears[gear_idx].begin());
        gears[gear_idx].push_back(first);
    }
}

// 회전할 때의 영향을 처리하는 함수
void process_rotation(int gear_idx, int direction, vector<int>& rotated) {
    rotated[gear_idx] = direction;
    
    // 왼쪽에 있는 톱니바퀴 회전
    if (gear_idx > 0 && rotated[gear_idx - 1] == 0) {
        if (gears[gear_idx][6] != gears[gear_idx - 1][2]) {  // 서로 맞닿은 극이 다르면 반대 방향으로 회전
            process_rotation(gear_idx - 1, -direction, rotated);
        }
    }
    
    // 오른쪽에 있는 톱니바퀴 회전
    if (gear_idx < gears->size() - 1 && rotated[gear_idx + 1] == 0) {
        if (gears[gear_idx][2] != gears[gear_idx + 1][6]) {  // 서로 맞닿은 극이 다르면 반대 방향으로 회전
            process_rotation(gear_idx + 1, -direction, rotated);
        }
    }
}

int main() {
    //입력
    int T, K;
    cin >> T;

    //구현
    // 각 톱니바퀴 상태 입력받기
    for (int i = 0; i < T; i++) {
        string gear;
        cin >> gear;
        for (char ch : gear) {
            gears[i].push_back(ch - '0');
        }
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        int gear_idx, direction;
        cin >> gear_idx >> direction;
        gear_idx--;  // 톱니바퀴 인덱스 0부터 시작하도록 조정
        
        vector<int> rotated(T, 0);  // 회전 여부를 추적하는 배열
        process_rotation(gear_idx, direction, rotated);

        // 각 톱니바퀴 실제 회전시키기
        for (int j = 0; j < T; j++) {
            if (rotated[j] != 0) {
                rotate_gear(j, rotated[j]);
            }
        }
    }

    // 12시 방향이 S극(1)인 톱니바퀴의 개수 세기
    int count = 0;
    for (int i = 0; i < T; i++) {
        if (gears[i][0] == 1) {  // 12시 방향은 gears[i][0]에 위치
            count++;
        }
    }
    
    //출력
    cout << count << endl;

    return 0;
}
