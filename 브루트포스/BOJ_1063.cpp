#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    //입력
    int n;
    string king, stone, m;
    cin >> king >> stone >> n;
    //아스키 코드값을 고려한 계산
    int kx = king[0] - 64;
    int ky = king[1] - '0';
    int sx = stone[0] - 64;
    int sy = stone[1] - '0';
    //구현
    for(int i=0; i<n; i++){
        int mx = 0;
        int my = 0;

        switch(m[0]){ //체스판 위에서의 움직임 다뤄주기
            case 'R':
                mx = 1;
                if(m[1]=='T') my = 1;
                if(m[1]=='B') my = -1;
                break;
            case 'L':
                mx = 1;
                if(m[1]=='T') my = 1;
                if(m[1]=='B') my = -1;
                break;
            case 'B':
                my = -1;
                break;
            case 'T' :
                my = 1;
                break;
        }
        int cur_kx = kx+mx, cur_ky = ky+my;
        int cur_sx = sx+mx, cur_sy = sy+my;

        if(cur_kx<1||cur_kx>8||cur_ky<1||cur_ky>8) continue; //체스판 바깥으로 나가면 자리 옮기지 않고 continue
        if(cur_kx==sx && cur_ky==sy){//king과 stone의 위치가 같을때
            if(cur_sx<1||cur_sx>8||cur_sy<1||cur_sy>8)continue;
            sx = cur_sx;
            sy = cur_sy;
        }
        
        kx = cur_kx; //위치 변경
        ky = cur_ky;
    }
    //출력
    cout << (char)(kx+64) << ky << '\n';
    cout << (char)(sx+64) << sy;

    return 0;
}