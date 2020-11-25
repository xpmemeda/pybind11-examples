import cmake_example


a = cmake_example.add(1, 2)

b = cmake_example.sub(1, 3)

print("add: %d\nsub: %d" %(a, b))

a = [1, 2, 3]

b = [4, 5, 6]

print(a + b)

print(type(a + b))