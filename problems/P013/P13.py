with open('problems/P013/P13.in') as f:
    numbers = [int(x) for x in f.readlines()]

print(str(sum(numbers))[:10])