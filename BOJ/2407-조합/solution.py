n, m = map(int, input().split())

comb = [[0 for j in range(101)] for i in range(101)]
for i in range(0, 101):
  comb[i][0] = comb[i][i] = 1

for i in range(2, 101):
  for j in range(1, 101):
    comb[i][j] = comb[i-1][j-1] + comb[i-1][j]

print(comb[n][m])