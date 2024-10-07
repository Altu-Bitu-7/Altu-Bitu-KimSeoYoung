# 방향을 정의합니다. [가로, 세로, 우상향 대각선, 우하향 대각선]
dx = [0, 1, 1, -1]
dy = [1, 0, 1, 1]

# 보드 크기 및 입력 받기
board = [list(map(int, input().split())) for _ in range(19)]

# 범위 내에 있는지 확인하는 함수
def in_bounds(x, y):
    return 0 <= x < 19 and 0 <= y < 19

# 승부 확인 함수
def check_winner(x, y):
    current_color = board[x][y]
    
    # 돌이 없는 경우 승부를 체크할 필요가 없음
    if current_color == 0:
        return False
    
    # 네 방향에 대해 오목 여부를 확인
    for direction in range(4):
        count = 1  # 현재 돌을 포함하므로 시작은 1
        
        # 해당 방향으로 계속 진행하며 같은 돌이 있는지 확인
        nx, ny = x + dx[direction], y + dy[direction]
        while in_bounds(nx, ny) and board[nx][ny] == current_color:
            count += 1
            if count > 5:  # 6목 이상이면 오목이 아님
                break
            nx, ny = nx + dx[direction], ny + dy[direction]
        
        if count == 5:
            # 반대 방향을 확인하여 연속된 돌이 더 있는지 검사
            back_x, back_y = x - dx[direction], y - dy[direction]
            if in_bounds(back_x, back_y) and board[back_x][back_y] == current_color:
                continue  # 반대편에도 같은 돌이 있으면 6목 이상이므로 패스
            
            # 오목 발견, 승리자와 그 위치를 반환
            return True
    
    # 오목이 아니면 False 반환
    return False

# 보드를 순차적으로 확인하여 오목을 찾음
for i in range(19):
    for j in range(19):
        if board[i][j] != 0 and check_winner(i, j):
            print(board[i][j])
            print(i + 1, j + 1)  # 좌표는 1-based로 출력해야 하므로 +1
            exit()  # 가장 먼저 발견된 오목에서 종료

# 오목이 없으면 0 출력
print(0)
