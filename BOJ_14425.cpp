#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <string, bool> m;
    int N,M;
    cin >> N >> M;

    string s;
    int count = 0;

    // 집합 s를 map에 key:string, value:bool으로 저장
    while(N--){
        cin >> s;
        m[s] = true;
    }

    // string M이 m에 존재하지 않으면 count하지 않음
    while(M--){
        cin >> s;
        if(m[s]) count++;
    }

    cout << count;

    return 0;

}