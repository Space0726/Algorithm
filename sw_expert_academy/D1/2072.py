for i in range(int(input())):
    print(f'#{i+1} {sum(filter(lambda x: x%2, map(int, input().split())))}')
