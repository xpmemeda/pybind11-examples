import example
import numpy as np


def test_add():
    a = np.random.rand()
    b = np.random.rand()
    np.testing.assert_allclose(example.add(a, b), a + b)

def test_sub():
    a = np.random.rand()
    b = np.random.rand()
    np.testing.assert_allclose(example.sub(a, b), a - b)

def test_add_list():
    a = np.random.rand(10)
    b = np.random.rand(10)
    np.testing.assert_allclose(example.add_list(list(a), list(b)), a + b)
