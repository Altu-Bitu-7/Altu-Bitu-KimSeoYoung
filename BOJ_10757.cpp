#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addNum(string a, string b) {
    string reverse_result;

    // 큰 수 자릿수 맞추기
    int max_length = max(a.length(), b.length());
    a = string(max_length - a.length(), '0') + a;
    b = string(max_length - b.length(), '0') + b;

    // 높은 자리 수 부터 계산
    int up_unit = 0; // 올림을 도와줄 변수
    // reverseResult = (a[max_length-1]-'0')+(b[max_length-1]-'0');
    for(int i = max_length-1; i>=0; i--){
        int full_unit = (a[i]-'0') + (b[i]-'0') + up_unit; // 아스키 코드 '0'=48
        up_unit = full_unit/10; // 올림값 저장
        reverse_result += (full_unit%10) + '0'; // int fullUnit을 아스키 코드 값을 활용하여( +'0') 문자로 변환
    }

    if (up_unit > 0) {
        reverse_result += up_unit+'0';
    }

    // reverseResult는 최종 결과에 정확히 reverse함
    reverse(reverse_result.begin(), reverse_result.end());

    return reverse_result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    
    string sum = addNum(num1, num2);
    cout << sum;

    return 0;
}
