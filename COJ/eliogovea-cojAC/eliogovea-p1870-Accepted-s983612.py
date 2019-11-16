def solve(n):
    pos = 0
    res = 0
    while n != 0:
        r = n % 3
        n = n // 3
        res = res + r * (4 ** pos)
        pos = pos + 1
    return res

def main():
    t = int(input())
    while t > 0:
        t = t - 1
        n = int(input())
        print(solve(n))

if __name__ == '__main__':
    main()
