import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Load data
data = np.loadtxt("motion.txt", skiprows=1)
t, x, v = data[:,0], data[:,1], data[:,2]

fig, ax = plt.subplots()
ax.set_xlim(0, max(t))
ax.set_ylim(min(x)-1, max(x)+1)
ax.set_xlabel("Time (s)")
ax.set_ylabel("Position (m)")
ax.set_title("1D Motion under Gravity")

(line,) = ax.plot([], [], 'b-', label="Position")
(point,) = ax.plot([], [], 'ro')
ax.legend()

def init():
    line.set_data([], [])
    point.set_data([], [])
    return line, point

def update(frame):
    line.set_data(t[:frame], x[:frame])
    point.set_data([t[frame]], [x[frame]])  # <-- wrap in [ ]
    return line, point


ani = FuncAnimation(fig, update, frames=len(t), init_func=init, blit=True, interval=20)
plt.show()

