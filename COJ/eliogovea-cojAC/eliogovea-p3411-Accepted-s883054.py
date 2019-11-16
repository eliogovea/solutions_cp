import math

pi = 2 * math.acos(0)

n = int(input())

while n > 0:
    n = n - 1
    r = int(input())
    ans = (pi - 2) * r * r
    print("%.2lf" % ans)
