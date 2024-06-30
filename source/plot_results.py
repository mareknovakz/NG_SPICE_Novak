import matplotlib.pyplot as plt
import numpy as np

# Load solution vector x from file
data = np.loadtxt('solution.txt', delimiter='\t')
indices = data[:, 0]
values = data[:, 1]

# Plotting
plt.figure(figsize=(10, 6))
plt.bar(indices, values, width=0.4)
plt.xlabel('Index')
plt.ylabel('Solution Value')
plt.title('Solution Vector x')
plt.grid(True)
plt.tight_layout()

# Save or display plot
plt.savefig('solution_plot.png')
plt.show()
