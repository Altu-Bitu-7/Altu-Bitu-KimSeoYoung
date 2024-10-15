#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;  // 1m^2 당 참외의 개수
    cin >> k;

    vector<pair<int, int>> edges(6);  // 방향과 길이를 저장할 벡터

    // 방향과 길이 입력 받기
    for (int i = 0; i < 6; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int max_width = 0, max_height = 0;
    int max_width_idx = 0, max_height_idx = 0;

    // 큰 직사각형의 가로와 세로를 찾기
    for (int i = 0; i < 6; i++) {
        if (edges[i].first == 1 || edges[i].first == 2) {  // 동서 방향 (가로)
            if (edges[i].second > max_width) {
                max_width = edges[i].second;
                max_width_idx = i;
            }
        } else if (edges[i].first == 3 || edges[i].first == 4) {  // 남북 방향 (세로)
            if (edges[i].second > max_height) {
                max_height = edges[i].second;
                max_height_idx = i;
            }
        }
    }

    // 작은 직사각형의 가로와 세로 찾기
    int small_width = edges[(max_width_idx + 3) % 6].second;
    int small_height = edges[(max_height_idx + 3) % 6].second;

    // 큰 직사각형의 넓이에서 작은 직사각형의 넓이를 빼서 참외밭의 넓이를 구함
    int area = (max_width * max_height) - (small_width * small_height);

    // 참외밭의 넓이에 1m^2 당 참외의 개수인 k를 곱해 참외의 총 개수를 출력
    cout << area * k << "\n";

    return 0;
}
