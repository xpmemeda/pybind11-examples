import numpy as np
import example


def test_multiply():
    a = np.random.rand(3)
    b = np.random.rand(3)
    np.testing.assert_allclose(example.numpy_functions.multiply(a, b), a * b)

def test_reduce():
    a = np.random.randint(0, 128, size=(3, 3))
    np.testing.assert_allclose(example.numpy_functions.reduce(a), np.add.reduce(a, 1))
