import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np

# Sample data (5x5 matrix)
data = np.array([
    [1, 2, 3, 4, 5],
    [5, 4, 3, 2, 1],
    [2, 3, 4, 5, 6],
    [6, 5, 4, 3, 2],
    [1, 3, 5, 7, 9]
])

# Create a heatmap
sns.heatmap(data, annot=True, cmap="coolwarm")

# Add title
plt.title("Heatmap Example")

# Show the plot
plt.show()
