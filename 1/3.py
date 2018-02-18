def removeDupes(s):
    seen = set()
    l = len(s)
    s = list(s)
    i = 0
    while (i < l):
        c = s[i]
        if c in seen:
            del s[i]
            l -= 1
        else:
            seen.update(c)
            i += 1
            
    final = ""
    for c in s:
        final += c
    return final

print removeDupes("abc")
print removeDupes("abab")
print removeDupes("aabb")
