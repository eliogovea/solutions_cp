// 2016-2017 CT S03E08: Codeforces Trainings Season 3 Episode 8 - 2005-2006 ACM-ICPC, Tokyo Regional Contest + 2010 Google Code Jam Qualification Round (CGJ 10, Q)
// 101150K2


# (a, b) -> (b, a % b)
def gcd(a, b):
    while b != 0:
        tmp = a % b
        a = b
        b = tmp
    return a

def abs(x):
    if x < 0:
        x = -x
    return x

def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        for j in range(i):
            ans = gcd(ans, abs(a[i] - a[j]))
    ans = ((a[0] + ans - 1) // ans) * ans - a[0]
    print(ans)
        
if __name__ == '__main__':
    main()
