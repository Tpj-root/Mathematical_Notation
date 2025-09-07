

### **1. Differential Equation (DE) – Basics**

A **differential equation** is an equation that involves a function and its derivatives.
It shows how a quantity changes.

**Example:**

$$
\frac{dy}{dx} = 3y
$$

This says: “the rate of change of $y$ with respect to $x$ is 3 times $y$.”

---

### **2. Ordinary Differential Equation (ODE)**

* Involves **one independent variable** (like $x$) and **one dependent variable** (like $y$).
* Only derivatives w\.r.t that one variable appear.

**Example:**

$$
\frac{dy}{dx} + 2y = 0
$$

* Here $y$ depends on $x$ only.
* Solve to get $y(x) = Ce^{-2x}$ (C = constant).

---

### **3. Partial Differential Equation (PDE)**

* Involves **more than one independent variable** (like $x$ and $t$) and partial derivatives.
* Used when a quantity depends on **more than one variable**.

**Example:**

$$
\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial x^2}
$$

* Heat equation: $u(x,t)$ depends on position $x$ and time $t$.

---

### **4. Key Difference**

| Feature     | ODE                    | PDE                             |
| ----------- | ---------------------- | ------------------------------- |
| Variables   | 1 independent variable | 2 or more independent variables |
| Derivatives | Ordinary derivatives   | Partial derivatives             |
| Example     | dy/dx = 3y             | ∂u/∂t = ∂²u/∂x²                 |

---




### **1. What is a Differential Equation?**

A **differential equation (DE)** is an equation involving:

* A function (like $y(t)$, $u(x,t)$)
* Its derivatives (rates of change)

It describes **how something changes over time or space**.

**Simple analogy:**

* If your speed is changing, DE tells you how your position changes over time.

---

### **2. Why is it useful in real-world?**

Differential equations model **dynamic systems**. Anything that changes continuously can often be described by DEs.

#### **Examples in Real Life:**

1. **Physics**

   * Motion of planets (Newton’s laws → ODEs)
   * Pendulum swinging: $\frac{d^2\theta}{dt^2} + \frac{g}{l}\sin\theta = 0$

2. **Engineering**

   * Electrical circuits: $L \frac{di}{dt} + Ri + \frac{1}{C} \int i\, dt = V(t)$
   * Control systems: speed control of a motor

3. **Biology**

   * Population growth: $\frac{dP}{dt} = rP$
   * Spread of diseases (SIR model):
     $\frac{dS}{dt} = -\beta SI$, $\frac{dI}{dt} = \beta SI - \gamma I$

4. **Economics**

   * Modeling investment growth: $\frac{dP}{dt} = rP$
   * Predicting stock prices (stochastic DEs)

5. **Chemistry**

   * Reaction rates: $\frac{d[A]}{dt} = -k[A]$ (first-order reaction)

6. **Environmental Science**

   * Pollution spread in a river (PDEs): $\frac{\partial C}{\partial t} + v \frac{\partial C}{\partial x} = D \frac{\partial^2 C}{\partial x^2}$

---

### **3. How to recognize when to use DE**

Ask yourself:

* Is the system changing continuously?
* Can I express the rate of change in terms of current state?
* Are there more than one variable affecting the change?


---

