import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

# Load the trajectory data
data = np.loadtxt("trajectory_data.txt")

# Extract x, y, z coordinates
x = data[:, 0]
y = data[:, 1]
z = data[:, 2]

# Set up the figure and 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Labels
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# Initialize the plot with empty data
line, = ax.plot([], [], [], label='End Effector Trajectory')
ax.legend()

# Function to initialize the plot (clear the previous data)
def init():
    line.set_data([], [])
    line.set_3d_properties([], 'z')  # Set 'z' as the third axis, not an empty list
    
    # Set dynamic axis limits based on the data range
    ax.set_xlim([min(x), max(x)])
    ax.set_ylim([min(y), max(y)])
    ax.set_zlim([min(z), max(z)])
    
    return line,

# Update function to plot each frame
def update(frame):
    line.set_data(x[:frame], y[:frame])
    line.set_3d_properties(z[:frame])
    return line,

# Create an animation that updates the plot for each frame
ani = FuncAnimation(fig, update, frames=len(x), init_func=init, blit=True, interval=50)

# Show the animation
plt.show()

