import numpy as np
import cmake_example


a = cmake_example.add(1, 2)
b = cmake_example.sub(1, 3)
print("add: %d\nsub: %d" %(a, b))

a = [1, 2, 3]
b = [4, 5, 6]
c = a + b
print(c)
print(type(c))

a = np.array([1.1, 3.3, 5.5])
b = cmake_example.mul_by_10(a)
print(b)
print(type(b))