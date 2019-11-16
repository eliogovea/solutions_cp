// Problem: pace=1&num=1036
// Verdict: Accepted

n, s = map(int, input().split())

if s % 2 == 1:
    print("0")
    exit()

dp = [[0] * (s + 1) for l in range(n + 1)]

dp[0][0] = 1
for l in range(n):
    for x in range(s + 1):
        for d in range(10):
            if x + d <= s:
                dp[l + 1][x + d] += dp[l][x]

print(dp[n][s // 2] ** 2)
