#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 입력
    int N, M;
    cin >> N >> M; // N: 카드 수, M: 라운드 수

    deque<int> do_deck, su_deck;   // 두 명의 플레이어 덱 (도도, 수연)
    deque<int> do_ground, su_ground;  // 각 플레이어의 그라운드에 놓인 카드
    
    // 구현
    // 도도와 수연의 덱 초기화
    for (int i = 0; i < N; i++) {
        int d, s;
        cin >> d >> s;
        do_deck.push_back(d);  // 도도의 덱
        su_deck.push_back(s);  // 수연의 덱
    }

    bool turn = true;  // true: 도도의 턴, false: 수연의 턴

    while (M--) {
        // 현재 턴의 플레이어가 덱에서 카드를 그라운드에 내려놓음
        if (turn) {  // 도도의 턴
            do_ground.push_front(do_deck.back());  // 도도 그라운드에 카드 추가
            do_deck.pop_back();  // 도도 덱에서 카드 제거
            if (do_deck.empty()) {
                cout << "su" << endl;  // 도도의 덱이 비었으면 수연 승리
                return 0;
            }
        } else {  // 수연의 턴
            su_ground.push_front(su_deck.back());  // 수연 그라운드에 카드 추가
            su_deck.pop_back();  // 수연 덱에서 카드 제거
            if (su_deck.empty()) {
                cout << "do" << endl;  // 수연의 덱이 비었으면 도도 승리
                return 0;
            }
        }

        // 종을 칠 수 있는 조건 체크
        if (!do_ground.empty() && !su_ground.empty()) {
            // 1. 그라운드 카드들의 합이 5라면 수연이 종을 칠 수 있음
            if (do_ground.front() + su_ground.front() == 5) {
                while (!do_ground.empty()) {
                    su_deck.push_front(do_ground.back());
                    do_ground.pop_back();
                }
                while (!su_ground.empty()) {
                    su_deck.push_front(su_ground.back());
                    su_ground.pop_back();
                }
            }
            // 2. 도도의 그라운드 맨 위 카드가 5라면 도도가 종을 칠 수 있음
            else if (do_ground.front() == 5) {
                while (!su_ground.empty()) {
                    do_deck.push_front(su_ground.back());
                    su_ground.pop_back();
                }
                while (!do_ground.empty()) {
                    do_deck.push_front(do_ground.back());
                    do_ground.pop_back();
                }
            }
        }

        // 턴 교체
        turn = !turn;
    }

    // 출력
    // 게임이 끝난 후 카드 수가 더 많은 플레이어가 승리
    if (do_deck.size() > su_deck.size()) {
        cout << "do" << '\n';
    } else if (do_deck.size() < su_deck.size()) {
        cout << "su" << '\n';
    } else {
        cout << "dosu" << '\n';  // 카드 수가 같다면 무승부
    }

    return 0;
}
