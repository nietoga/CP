n = int(input())
e = int(input())
e = e - 1
t = int(input())
m = int(input())

g : list[list] = [[] for _ in range(n)]

for _ in range(m):
  a, b, c = map(int, input().split())

  a = a - 1
  b = b - 1
  g[a].append((b, c))
  g[b].append((a, c))

grev = [[] for _ in range(n)]
for a in range(n):
  for b, c in g[a]:
    grev[b].append((a, c))

costs = [-1 for _ in range(n)]

def go(cur, cost):
  global costs
  costs[cur] = cost

  for b, c in grev[cur]:
    if costs[b] == -1 or costs[b] > cost + c:
      go(b, cost + c)

go(e, 0)
print(n - costs.count(-1))
