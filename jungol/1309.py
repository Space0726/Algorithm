n = int(input())
factorial = lambda x: x*factorial(x-1) if x else 1
for i in range(n, 0, -1):
    if i == 1:
        print(f"{i}! = {i}")
    else:
        print(f"{i}! = {i} * {i-1}!")
print(factorial(n))
