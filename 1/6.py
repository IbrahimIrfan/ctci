def swap(m, r1, c1, r2, c2):
    print str(m[r1][c1]) + " <--> " + str(m[r2][c2])
    temp = m[r1][c1]
    m[r1][c1] = m[r2][c2]
    m[r2][c2] = temp
    return m 

# Not in place, O(N^2)
def rotate(m):
    new = []
    n = len(m)
    for r in range(0, n):
        new.append([])
        for c in range(0, n):
            new[r].append(0)

    for r in range(0, n):
        for c in range(0, n):
            new[c][n - r - 1] = m[r][c]
    return new

# In place, O(N^2)
def rotateInPlace(m):
    n = len(m)
    count = 0
    for r in range(0, n):
        m[r].reverse() # in place

    for r in range(0, n):
        for c in range(0, n - count):
            m = swap(m, r, c, n - c - 1, n - r - 1)
        count += 1
    return m

matrix = [
        [1,2,3],
        [4,5,6],
        [7,8,9],
        ]
print rotateInPlace(matrix)

'''
    Result:
    [
        [7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]
    ]

    N = 3
    Not in place:
    a,b goes to b,N-a

    In place:
    reverse each row, then:
    a,b goes to N-b,N-a
'''
