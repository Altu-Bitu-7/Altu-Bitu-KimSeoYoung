#include <iostream>
#include <string>

using namespace std;

char res[51];
int alpha[27]; //알파벳 빈도수 저장할 배열 선언

void solve(int cnt, int size){

    if(cnt > 1){
        cout << "I'm Sorry Hansoo";
        return;
    } else {
        int l=0, r=size-1;
        for(int i=0; i<26; i++){
            while(alpha[i]){
                res[l++] = i + 'A';
                res[r--] = i + 'A';
                alpha[i] -= 2;
            }
        }
        for(int i=0; i<size; i++){
            cout << res[i];
        }
    }
}

int main(){
    // 입력
    string str;
    int cnt = 0;
    cin >> str;

    //구현
    for(int i=0; i<str.size(); i++){ //알파벳 빈도수 세기
        alpha[str[i]-'A']++;
    }
    
    for(int i=0; i<26; i++){ //각 알파벳이 짝수개씩 있는지 홀수개씩 있는지 확인
        if(alpha[i]%2){
            cnt++;
            res[str.size()/2] = i + 'A';
            alpha[i+'A']--;
        }
    }

    //출력
    solve(cnt,str.size());

    return 0;
}