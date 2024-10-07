# DFS 함수를 정의합니다.
def dfs(v):
    # 현재 컴퓨터를 방문 처리
    visited[v] = True
    
    # 현재 컴퓨터와 연결된 다른 컴퓨터들을 확인
    for neighbor in network[v]:
        if not visited[neighbor]:  # 방문하지 않은 컴퓨터라면
            dfs(neighbor)  # 재귀적으로 DFS 호출

# 입력
n = int(input())  # 컴퓨터의 수 (노드 수)
m = int(input())  # 네트워크 상에서 직접 연결된 컴퓨터 쌍의 수 (간선 수)

# 그래프 초기화 (네트워크 관계를 저장하는 리스트)
network = [[] for _ in range(n + 1)]

# 네트워크 관계 입력 받기
for _ in range(m):
    u, v = map(int, input().split())
    network[u].append(v)
    network[v].append(u)  # 양방향 연결 (양방향 간선)

# 방문 여부를 체크하는 리스트
visited = [False] * (n + 1)

# DFS 탐색을 시작 (1번 컴퓨터에서 시작)
dfs(1)

# 1번 컴퓨터로부터 감염된 컴퓨터의 수 계산 (1번 컴퓨터 제외)
infected_count = visited.count(True) - 1

# 출력
print(infected_count)
