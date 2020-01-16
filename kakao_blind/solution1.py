INF = 1234567890

def len_(n):
    ret = 0
    while n:
        ret += 1
        n /= 10
    return ret

def solve(N, n, s):
    ret, st = 0, 1
    for i in range(0, N, n):
        print(s[i:i+n], s[i+n:i+n+n])
        if i+n+n > N or s[i:i+n] != s[i+n:i+n+n]:
            ret += min(n, N-i)
            if st > 1:
                ret +=  len_(st)
            st = 1
        else:
            st += 1
    return ret

def solution(S):
    s = S
    N = len(s)
    res = INF
    for i in range(1, N+1):
        res = min(res, solve(N, i, s))
    return res

print(solution("ababaca"))