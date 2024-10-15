#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
vector<int> numbers;
set<vector<int>> result_set;

void backtrack(vector<int>& result) {
    if (result.size() == m) {
        result_set.insert(result);  // 중복을 피하기 위해 set에 넣음
        return;
    }

    for (int i = 0; i < n; i++) {
        result.push_back(numbers[i]);
        backtrack(result);
        result.pop_back();  // 백트래킹을 위해 마지막 원소 제거
    }
}

int main() {
    // 입력 받기
    cin >> n >> m;
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // numbers 배열 정렬
    sort(numbers.begin(), numbers.end());

    // 백트래킹 시작
    vector<int> result;
    backtrack(result);

    // 결과 출력
    for (const auto& seq : result_set) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
