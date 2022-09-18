import collections

t = int(input())
for i in range(t):
    word = str(input())
    dq = collections.deque()
    for w in word:
        dq.append(w)

    isPalindrom = True
    count = 0
    while len(dq) > 1:
        count += 1
        if dq.popleft() != dq.pop():
            isPalindrom = False
            break
        
    if isPalindrom:
        print(int(isPalindrom), count + 1)
    else:
        print(int(isPalindrom), count)
