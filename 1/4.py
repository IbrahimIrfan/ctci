# O((s log s)*(a log a)*(min(s,a)))
def anagram(s, a):
    s = ''.join(sorted(s)) # O(s log s)
    a = ''.join(sorted(a)) # O(a log a)
    return s == a        # O(min(s,a))

# O(s*a*(min(s,a))
def anagram2(s, a):
    sChars = {}
    aChars = {}

    # O(s)
    for c in s:
        if c in sChars:
            sChars[c] += 1
        else:
            sChars[c] = 1

    # O(a)
    for c in a:
        if c in aChars:
            aChars[c] += 1
        else:
            aChars[c] = 1

    # worst case here:
    # all unique sChars == all unique aChars
    # O(min(a, s))
    return sChars == aChars
    
print anagram2("aba", "aab")
print anagram2("abc", "cba")
print anagram2("abc", "cxa")
