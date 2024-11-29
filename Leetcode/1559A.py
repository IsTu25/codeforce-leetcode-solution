from functools import reduce
import operator
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(reduce(operator.and_,a))
