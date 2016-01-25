def bfs(adjacencies, N, start):
    distance = [-1] * (N + 1)
    visited = [False] * (N + 1)
    queue = [start]
    visited[start] = True
    distance[start] = 0
    while queue:
        cur = queue.pop(0)
        parent_dist = distance[cur]
        for adjacent in adjacencies[cur]:
            if not visited[adjacent]:
                queue.append(adjacent)
                visited[adjacent] = True
                distance[adjacent] = parent_dist + 6
    for node in range(1, N + 1):
        dist = distance[node]
        if dist is not 0:
            print(str(dist), end=" ")
    print()

T = int(input())
for test in range(0, T):
    N, M = map(int, input().strip().split(' '))
    adjacencies = [[] for i in range(0, N + 1)]
    for e in range(0, M):
        n1, n2 = map(int, input().strip().split(' '))
        adjacencies[n1].append(n2)
        adjacencies[n2].append(n1)
    start = int(input())
    bfs(adjacencies, N, start)