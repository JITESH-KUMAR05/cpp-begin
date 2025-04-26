s1 = "egg"
s2 = "add"

map_s1_to_s2 = {}
map_s2_to_s1 = {}
for c1,c2 in zip(s1,s2):
    if c1 in map_s1_to_s2:
        if map_s1_to_s2[c1] != c2:
            print(False)
            break
    if c2 in map_s2_to_s1:
        if map_s2_to_s1[c2] != c1:
            print(False)
            break
    map_s1_to_s2[c1] = c2
    map_s2_to_s1[c2] = c1

print(True)
print(s1[:-1])