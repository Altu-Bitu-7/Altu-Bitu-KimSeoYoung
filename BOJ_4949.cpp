#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        string str;
        getline(cin, str); //한줄씩 받기
        stack<char> s; //스택 선언 (괄호 저장)
        bool ans = true; //"yes" or "no" 확인

        if(str.length()==1 || str[0] == '.') break;

        for(int i=0; i<str.length(); i++){
            if(str[i] == '(' || str[i]=='[') s.push(str[i]);
            
            if(str[i]==')'){
                if(s.empty()||s.top()=='['){
                    ans = false;
                    break;
                }
                else s.pop();
            }

            if(str[i]==']'){
                if(s.empty() || s.top()=='('){
                    ans = false;
                    break;
                } 
                else s.pop();
            }

        }

        if(s.empty() && ans) cout << "yes" << "\n"; // 한줄 다 확인 했을때 stack이 empty, ans가 true일때 yes 출력
        else cout << "no" << "\n"; // 한줄 다 확인 했을때 stack이 empty, ans가 false일때 no 출력
    }

    return 0;
}