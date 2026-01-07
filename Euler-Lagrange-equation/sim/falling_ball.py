import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Load simulation data
data = np.loadtxt("motion.txt", skiprows=1)
t, x, v = data[:,0], data[:,1], data[:,2]

# Normalize position so ground = 0
x = x - min(x)

# Setup figure
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(4,6))
plt.tight_layout(pad=3)

# --- Top: real motion view ---
ax1.set_xlim(-1, 1)
ax1.set_ylim(0, max(x) + 1)
ax1.set_title("Falling Ball Simulation")
ax1.set_xlabel("Horizontal (fixed)")
ax1.set_ylabel("Height (m)")
(ball,) = ax1.plot([], [], "ro", markersize=15)

# --- Bottom: velocity vs time ---
ax2.set_xlim(0, max(t))
ax2.set_ylim(min(v)-1, max(v)+1)
ax2.set_xlabel("Time (s)")
ax2.set_ylabel("Velocity (m/s)")
(line,) = ax2.plot([], [], "b-")

def init():
    ball.set_data([], [])
    line.set_data([], [])
    return ball, line

def update(frame):
    # Ball motion (height)
    ball.set_data([0], [x[frame]])   # wrap both in [ ]

    # Velocity plot
    line.set_data(t[:frame], v[:frame])

    return ball, line


ani = FuncAnimation(fig, update, frames=len(t), init_func=init, blit=True, interval=20)
plt.show()

