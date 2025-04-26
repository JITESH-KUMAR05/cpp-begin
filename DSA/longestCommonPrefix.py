s = ["flower","flow","flight"]
def longestCommonPrefix(s):
    if not s:
        return ""
    prefix = s[0]
    for i in s[1:]:
        while not i.startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""
    return prefix
print(longestCommonPrefix(s))
        