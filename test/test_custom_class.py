import example


def test_pet():
    pet = example.custom_class.Pet("x")
    assert pet.name == "x"
    pet.name = "y"
    assert pet.name == "y"

def test_dog():
    dog = example.custom_class.Dot("x")
    assert dog.name == "x"
    dog.name = "y"
    assert dog.name == "y"
    assert dog.bark() == "woof"
