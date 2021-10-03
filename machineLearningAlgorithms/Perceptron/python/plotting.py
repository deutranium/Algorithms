from mlxtend.plotting import plot_decision_regions
import matplotlib.pyplot as plt


def plot(x, prediction, clf, epoch=None, accuracy=None, weights=None):
    plot_decision_regions(x, prediction, clf=clf)

    plt.title(f'Perceptron {weights}')

    if epoch is not None:
        plt.annotate(f'Epoch: {epoch}', xy=(2, 0), xytext=(5, 0.5))

    if accuracy is not None:
        plt.annotate(f'Accuracy: {accuracy}%', xy=(2, 0), xytext=(5, 0))

    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()


def plot_error_history(err):
    print(len(err))
    plt.plot(err)
    plt.show()
