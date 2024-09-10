#include<iostream>

using namespace std;


int main(){
    //입력
    int N, ans, cnt, temp;
	ans = 0; // 영화 제목
	cnt = 0; // 현재 몇번쨰 종말의 수인가
    cin >> N;
    //구현
	while (cnt != N){
        ans++;
		temp = ans;

		// 수에 6이 적어도 3개이상 들어가는지 판별
		while (temp != 0){
			if (temp % 1000 == 666){ // 종말의 숫자라면
				cnt++;
				break;
			}
			else temp /= 10; // 일의 자리수 삭제
		}
    }
    //출력
	cout << ans;

    return 0;
}