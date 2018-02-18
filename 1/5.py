# O(n)
def spaces(s):
    new = ""
    for c in s:
        if c == " ":
            new += "%20"
        else:
            new += c
    return new

print spaces("hello, world")
print spaces(" hello, world ")

