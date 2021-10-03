import numpy as np
from plotting import plot
from sklearn.metrics import accuracy_score

"""
File: perceptron.py
Author: Lashuk1729
Description: Perceptron Rule
"""


class Perceptron(object):

    def __init__(self, eta: float = 0.01, epochs: int = 50):
        self.eta = eta  # learning reate
        self.epochs = epochs

    def train(self, X: np.ndarray, target: np.ndarray):  # Perceptron Rule
        self.w = np.zeros(1 + X.shape[1])
        self.err = []

        print('Training progress..')
        for epoch in range(self.epochs):
            errors = 0
            for x, y in zip(X, target):
                update = self.eta * (y - self.predict(x))
                self.w[1:] += update * x
                self.w[0] += update
                errors += int(update != 0.0)

            accuracy = int(accuracy_score(self.predict(X), target) * 100)
            self.err.append(accuracy)
            plot(X, target, self, epoch, accuracy, self.w)
        return self

    def dot_product(self, X: np.ndarray) -> np.float64:
        return np.dot(X, self.w[1:]) + self.w[0]

    def predict(self, X: np.ndarray) -> int:
        return np.where(self.dot_product(X) >= 0.0, 1, 0)
