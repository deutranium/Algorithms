import numpy as np
from perceptron import Perceptron
from plotting import plot, plot_error_history

"""0. Create dataset"""
train_data = (  # x, y, target
    (0.2, 0.3, 0),
    (0.8, 7, 0),
    (2, 1, 0),
    (2, 4, 0),
    (1, 1, 0),
    (2, 1, 0),
    (2, 2.8, 0),
    (2, 2.2, 0),
    (3, 1, 0),
    (5, 3, 1),
    (5, 4, 1),
    (4, 5, 1),
    (4, 7, 1),
    (5, 5.1, 1),
    (5.5, 6, 1),
    (6, 5, 1),
    (6, 6.5, 1),
    (6, 7, 1)
)

validate_data = (
    (1, 1),
    (2, 2),
    (2, 1),
    (5, 4),
    (6, 5),
    (6, 6)
)

X_train = np.array([x[:2] for x in train_data])  # list comprehension
X_validate = np.array([x[:2] for x in validate_data])  # list comprehension
y = np.array([x[-1] for x in train_data])

"""1.Initialization perceptron"""
perceptron = Perceptron(epochs=25, eta=0.01)

"""2.perceptron training"""
perceptron.train(X_train, target=y)
print(f'Weights: {perceptron.w}')

"""3.Prediction"""
prediction = perceptron.predict(X_train)
print(f'Output (Y): {prediction}')

print('last')
plot(X_train, prediction, perceptron, 25, None, perceptron.w)
plot_error_history(perceptron.err)
