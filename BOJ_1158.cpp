#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n>>k;

    queue<int> q; //큐 선언
    for(int i=0; i<n; i++) {
        q.push(i+1);
    }

    //결과값을 저장할 큐 선언
    queue<int>q_res;

    //요세푸스 시작
    while(!q.empty()) {
        for(int i=0; i<2; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        q_res.push(q.front());
        q.pop();
    }


    
    //큐 q_res에 있는 원소 출력
    // cout << "<";
    // while(!q_res.empty()) {
    //     cout << q_res.front() << ", ";
    //     q_res.pop();
    // }
    // cout << ">";

    //큐 q_res에 있는 원소 출력
    cout << "<";
    while(q_res.size()>=2) {
        cout << q_res.front() << ", ";
        q_res.pop();
    }
    cout << q_res.front() << ">";
    q_res.pop();

    return 0;
}