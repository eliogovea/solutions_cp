def main():
    fact = [0] * 301
    fact[0] = 1
    for i in range(1, 301):
        fact[i] = fact[i - 1] * i
    f = [0] * 301;
    f[0] = 1
    f[1] = 1
    for i in range(2, 301):
        for l in range(0, i):
            f[i] = f[i] + f[l] * f[i - 1 - l]
    while True:
        n = int(input())
        if n == 0:
            break
        print(f[n] * fact[n])
        

if __name__ == '__main__':
    main()
