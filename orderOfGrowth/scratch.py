
import math

for i in range(1,25):
    # math.log()
    left = 2*(i**2) + 4*i + 12
    right = 3*(i**2)
    print("Left: " + str(left) + " right: " + str(right))
    if (left <= right):
        print("     TRUE: left <= right @ " + str(i))
    else:
        print("     FALSE @ " + str(i))
    print("")