def isUnique2(s):
    seen = set()
    for c in s:
        if c in seen:
            return False
        else:
            seen.update(c)
    return True

def isUnique(s):
    s = ''.join(sorted(s))
    l = len(s)
    for i in range(0,l-1):
        if s[i] == s[i+1]:
            return False
    return True

print isUnique("abba")
print isUnique("aba")
print isUnique("abcdefghijklmnop")
