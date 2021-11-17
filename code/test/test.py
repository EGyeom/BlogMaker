
from typing import *

def Solution(target: int, array: List):
    map = dict()
    temp = 0
    for i in range(len(array)):
        temp = target - array[i]
        if temp in map:
            print("{},{}".format(map[temp],i))
        map[array[i]] = i


array = [11,3,6,13,5]
target_num = 8

Solution(target_num,array)
