import numpy as np


x = [1, 2]
w = [1, 1, 1]


def net_input(X: np.ndarray) -> np.float64:
    return np.dot(X, w[1:]) + w[0]


def predict(X: np.ndarray) -> int:
    return 1.0 if net_input(X) >= 0.0 else 0.0


print(predict(x))
