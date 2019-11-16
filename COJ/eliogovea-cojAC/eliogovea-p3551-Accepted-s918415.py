import math

def fun(angle):
    A1 = (angle - math.sin(angle)) / 2.0;
    A2 = math.pi - A1;
    return A1 / A2;

def solve(r, k):
    lo = 0;
    hi = math.pi;
    for it in range(1, 200):
        mid = (lo + hi) / 2.0;
        if fun(mid) < k:
            lo = mid;
        else:
            hi = mid;
    return (lo + hi) / 2.0;

#file = open("000.in", "r");
#t = int(file.readline());
t = int(raw_input());
while t > 0:
    t = t - 1;
    #r, k = map(float, file.readline().split());
    r, k = map(float, raw_input().split());
    angle = solve(r, k);
    x = r * math.cos(angle);
    y = r * math.sin(angle);
    print("%.5f %.5f" % (x, y));
