#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// 소수인지 확인하는 함수
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 주어진 숫자로 만들 수 있는 모든 숫자를 찾아 소수를 찾는 함수
int solution(string numbers) {
    set<int> primeNumbers;  // 소수를 저장할 set (중복 방지)
    
    // 모든 자릿수 조합에 대해 순열을 생성
    for (int i = 1; i <= numbers.size(); i++) {
        vector<bool> select(numbers.size() - i, false);
        select.insert(select.end(), i, true);

        do {
            string temp = "";
            for (int j = 0; j < numbers.size(); j++) {
                if (select[j]) {
                    temp += numbers[j];
                }
            }

            sort(temp.begin(), temp.end());  // 순열을 만들기 위해 정렬
            do {
                int num = stoi(temp);  // 숫자로 변환
                if (isPrime(num)) {
                    primeNumbers.insert(num);  // 소수라면 set에 삽입
                }
            } while (next_permutation(temp.begin(), temp.end()));
        } while (next_permutation(select.begin(), select.end()));
    }

    return primeNumbers.size();  // 찾은 소수의 개수를 반환
}

int main() {
    string numbers;
    cout << "Enter numbers: ";
    cin >> numbers;

    cout << "Number of prime numbers: " << solution(numbers) << endl;

    return 0;
}
