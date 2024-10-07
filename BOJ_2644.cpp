from collections import deque

# BFS 함수 정의: start에서 target까지의 촌수를 계산
def bfs(start, target):
    # 각 사람의 방문 여부를 저장할 리스트 (방문하지 않은 경우 0)
    visited = [-1] * (n + 1)
    queue = deque([start])
    
    # 시작점은 0촌으로 설정
    visited[start] = 0
    
    # BFS 탐색
    while queue:
        current = queue.popleft()
        
        # 현재 사람과 연결된 모든 사람들을 확인
        for neighbor in family_graph[current]:
            if visited[neighbor] == -1:  # 방문하지 않은 경우
                visited[neighbor] = visited[current] + 1  # 촌수 증가
                queue.append(neighbor)
    
    # 목표 지점의 촌수 반환
    return visited[target]

# 입력
n = int(input())  # 전체 사람의 수
person1, person2 = map(int, input().split())  # 촌수를 계산할 두 사람
m = int(input())  # 부모 자식 관계의 수

# 각 사람 간의 관계를 저장할 그래프 초기화
family_graph = [[] for _ in range(n + 1)]

# 부모 자식 관계 입력 받기
for _ in range(m):
    parent, child = map(int, input().split())
    family_graph[parent].append(child)
    family_graph[child].append(parent)  # 양방향 연결

# BFS를 이용해 두 사람 사이의 촌수 계산
result = bfs(person1, person2)

# 출력
# 촌수가 존재하지 않으면 -1을 출력
if result == -1:
    print(-1)
else:
    print(result)
