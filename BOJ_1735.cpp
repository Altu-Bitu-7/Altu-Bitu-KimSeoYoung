#include <iostream>
#include <vector>
#include <utility> // std::pair 사용을 위한 헤더

using namespace std;

//재귀 이용하여 최대공약수(gcd) 구하기
int getGcdRecur(int a, int b)  {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a%b);
}

//분수 계산하기
pair<int, int> divide(int numer1, int denomin1, int numer2, int denomin2){
    //분모의 최소공배수
    int gcd = getGcdRecur(max(denomin1, denomin2),min(denomin1, denomin2)); //최대공약수 구하기
    int lcm = denomin1 * denomin2 / gcd; //최소공배수 구하기

    int x = lcm / denomin1; //계산을 위해 각 분모 분자에 곱해야 할 수
    int y = lcm / denomin2; //계산을 위해 각 분모 분자에 곱해야 할 수  
    
    int res1 = numer1*x + numer2*y;
    int res2 = lcm;

    return make_pair(res1, res2);
}

int main(){

    //입력
    int a,b;
    int n,m;
    cin >> a >> b >> n >> m;
    

    //출력
    pair<int, int> res = divide(a,b,n,m);
    int res1 = res.first;
    int res2 = res.second;
    cout << res1 << ' ' << res2;

    return 0;
}