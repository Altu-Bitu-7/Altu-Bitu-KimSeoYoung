#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b){
    int a_size = a.size();
    int b_size = b.size();
    int a_sum = 0;
    int b_sum = 0;

    //1. 문자열 a,b 길이가 다르면 짧은것이 먼저 온다.
    if(a_size != b_size){
        return a_size < b_size;
    }

    //2. 문자열 a,b 길이가 서로 같으면 a의 모든 자리수의 합과 b의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인것만 더한다.)
    for(int i=0; i<a.size(); i++){
        //문자열 a의 합 구하기
        if(a[i]>='0' && a[i]<=9)
            a_sum += int(a[i])-48; //문자열 숫자의 아스키 코드값 고려
        //문자열 b의  합 구하기
        if(b[i]>='0' && b[i]<='9')
            b_sum += int(b[i])-48; //문자열 숫자의 아스키 코드값 고려
    }
    if(a_sum != b_sum)
        return a_sum < b_sum;

    //3. 1,2번 조건으로 비교할 수 없으면, 사전순으로 비교한다.
    return a < b;
}

int main(){
    int n;
    string serial[50];

    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> serial[i];
    
    //정렬
    sort(serial, serial+n, compare);

    for(int i=0; i<n; i++)
        cout << serial[i] << "\n";

    return 0;

}