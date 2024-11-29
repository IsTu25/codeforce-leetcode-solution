# First, check the frequency of the array elements.
# If the frequency of 1 is 0, the answer to the problem is 0 because no valid operations can be performed.
# However, if there is at least one 1, we proceed to calculate the result.
# There might also be zeros in the array, so we need to count their frequency.
# The frequency of zeros will contribute as (2^count(zeros)) to the result.
# Multiply this with the frequency of ones to get the final result.
# Visualize the process to understand it better!

from collections import Counter
for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    freq=Counter(arr)
    if freq.get(1,0)==0:print(0)
    else:
        print(freq.get(1,0)*pow(2,freq.get(0,0)))
