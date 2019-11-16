// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090B

from decimal import *

def main():
    n, k = map(int, input().split())
    getcontext().prec = k + 20
    s = str(Decimal(n).sqrt())
    if s.find('.') == -1:
        ans = s + '.' + '0' * k
    else:
        a, b = s.split('.')
        if len(b) >= k:
            ans = a + '.' + b[0 : k]
        else:
            ans = a + '.' + b + [0] * (k - len(b))
    print(ans)

if __name__ == '__main__':
    main()
