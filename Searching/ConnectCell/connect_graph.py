import copy

adjacencies = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]

def print_matrix(matrix):
    for row in matrix:
        print(row)

def get_region_size(matrix, row_start, col_start, m, n):
    stack = []
    stack.append((row_start, col_start))
    matrix[row_start][col_start] = -1
    region_size = 1
    
    while stack:
        r, c = stack.pop()
        row_cur = copy.deepcopy(r)
        col_cur = copy.deepcopy(c)

        #check adjacents
        for drow, dcol in adjacencies:
            row = row_cur + drow
            col = col_cur + dcol
            if row >= 0 and col >= 0 and row < m and col < n:
                if matrix[row][col] is 1:
                    matrix[row][col] = -1
                    region_size += 1
                    stack.append((row, col))
    return region_size

m = int(input())
n = int(input())
matrix =[]
for r in range(0, m):
    matrix.append(list(map(int, input().strip().split(' '))))
max_region = 0
for row in range(0, m):
    for col in range(0, n):
        if matrix[row][col] is 1:
            max_region = max(get_region_size(matrix, row, col, m, n), max_region)

print(str(max_region))