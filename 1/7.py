# O(M*N) in place
def set0(matrix):
    rows = set()
    cols = set()

    m = len(matrix)
    n = len(matrix[0])

    #O(M*N)
    for r in range(0, m):
        for c in range(0, n):
            # O(1)
            if (matrix[r][c] == 0):
                rows.update([r])
                cols.update([c])
    # O(M*N)
    for r in range(0, m):
        for c in range(0, n):
            if (r in rows) or (c in cols):
                matrix[r][c] = 0
    return matrix
                    
matrix = [
        [0,2,3],
        [4,5,6],
        [7,8,9],
        ]

print set0(matrix)
