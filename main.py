import numpy as np
import example


a = example.add(1, 2)
b = example.sub(1, 3)
print("add: %d\nsub: %d" %(a, b))

a = [1, 2, 3]
b = [4, 5, 6]
c = a + b
print(c)
print(type(c))

a = np.array([1.1, 3.3, 5.5])
b = example.mul_by_10(a)
print(b)
print(type(b))


x = np.arange(1, 9, dtype=np.int8).reshape(4, 2)
y = example.numpy_functions.square(x)
print(y)


pet = example.custom_class.Pet("Laifu")

print(pet)

print("name %s" % pet.name)
pet.name = "Wangcai"
print("rename")
print("name %s" % pet.name)

print("-" * 20)

print("public name %s" % pet.public_name)
pet.public_name = "Wangcai"
print("rename public name")
print("public name %s" % pet.public_name)

print(example.custom_class.Pet)

print(example.custom_class.Dot)
dog = example.custom_class.Dot("laifu")
print(isinstance(dog, example.custom_class.Pet))

dog = example.custom_class.get_dog("laimao")
print(dog.name)
