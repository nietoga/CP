cnt = 1

while True:
    n, m = map(int, input().split())

    if n == 0 and m == 0:
        break

    g = [0] * n

    for i in range(n):
        g[i] = i

    def get_g(i):
        if g[i] == i:
            return i

        g[i] = get_g(g[i])
        return g[i]

    def correlate(i, j):
        gi = get_g(i)
        gj = get_g(j)

        m = min(gi, gj)

        g[gi] = m
        g[gj] = m

    for _ in range(m):
        i, j = map(int, input().split())
        correlate(i - 1, j - 1)

    gset = set()

    for i in range(n):
        gset.add(get_g(i))

    print("Case {}: {}".format(cnt, len(gset)))
    cnt += 1
