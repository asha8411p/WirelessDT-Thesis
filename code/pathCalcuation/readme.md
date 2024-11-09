# Ray Tracing Positioning System - Path Calculation Models

In the Ray Tracing positioning system, path calculation is a key step. It involves simulating the propagation path of the signal from the signal source to the receiving point, considering various physical phenomena that influence signal propagation, such as direct propagation, reflection, refraction, scattering, and multipath effects. Below are the mathematical models and calculation methods for these tasks:

## 1. Environment Modeling
Environment modeling is the foundation for path calculation. Objects and obstacles in the environment (such as walls, ceilings, furniture, etc.) are usually represented using 3D models. These can be generated via CAD models, laser scanning, or other modeling methods.

- **Obstacle model**: Objects in the environment are often modeled by polyhedra, planes (walls, ground, etc.), and curved surfaces (windows, glass, etc.).
- **Signal source and receiving point**: The location of the signal source (e.g., base station or satellite) and the receiving point (e.g., mobile device or sensor) must be clearly defined.

## 2. Mathematical Model of Path Calculation
The core of path calculation is to simulate signal propagation and calculate multiple paths from the signal source to the receiving point. The propagation of each path is affected by objects and obstacles in the environment. Path calculation considers the following main propagation modes:

### (a) Line-of-Sight (LOS)
When the signal travels directly from the source to the receiving point without encountering any obstacles, it is referred to as direct propagation. This is the simplest path calculation.

**Path formula:**
Let \( S \) be the signal source, \( R \) be the receiving point, and when there are no obstacles in the environment, the signal propagates in a straight line. The distance of this path is:

$$
d_{\text{LOS}} = \sqrt{(x_R - x_S)^2 + (y_R - y_S)^2 + (z_R - z_S)^2}
$$

Where \( (x_S, y_S, z_S) \) and \( (x_R, y_R, z_R) \) are the coordinates of the signal source and receiving point, respectively.

### (b) Reflection Propagation
When a signal encounters a flat or curved surface (such as a wall or ground), it will reflect. The calculation of the reflection path is based on the law of reflection, which states that the angle of incidence is equal to the angle of reflection.

**Reflection path calculation:**
Let \( I \) be the incident ray, \( R \) be the reflected ray, \( \theta_i \) be the angle of incidence, and \( \theta_r \) be the angle of reflection. The path after reflection \( d_{\text{ref}} \) can be calculated as follows:

$$
d_{\text{ref}} = \sqrt{(x_R - x_{\text{ref}})^2 + (y_R - y_{\text{ref}})^2 + (z_R - z_{\text{ref}})^2}
$$

Where \( (x_{\text{ref}}, y_{\text{ref}}, z_{\text{ref}}) \) are the coordinates of the reflection point, calculated from the reflection angle and the normal of the reflecting surface.

### (c) Refraction Propagation
Refraction occurs when a signal penetrates a medium interface (e.g., a window or other light-transmitting material) and typically follows Snell's Law.

**Snell's Law:**
The relationship between the angle of refraction \( \theta_t \) and the angle of incidence \( \theta_i \) is:

$$
n_1 \sin(\theta_i) = n_2 \sin(\theta_t)
$$

Where:
- \( n_1 \) and \( n_2 \) are the refractive indices of the incident and refracting media, respectively,
- \( \theta_i \) is the angle of incidence, and
- \( \theta_t \) is the refraction angle.

**Refraction path calculation:**  
The refraction path length can be adjusted by the refraction angle and refractive index, allowing the path of signal propagation to be calculated.

### (d) Scattering Propagation
Scattering occurs when the signal interacts with small objects (e.g., furniture, debris, particles in the air, etc.). Scattering is typically unpredictable but can be modeled using statistical methods.

**Scattering model:**  
Common scattering models include Rayleigh scattering and Mie scattering, which apply to different types of objects and environments. In Ray Tracing, scattering is often simulated by random sampling:

$$
P_{\text{scattered}} = A \cdot e^{-b \cdot \Delta t}
$$

Where:
- \( A \) is the scattering intensity,
- \( b \) is the attenuation coefficient, and
- \( \Delta t \) is the signal propagation time.

### (e) Multipath Effect
Multipath effect refers to the phenomenon where the signal reaches the receiving point through multiple paths, typically caused by reflection, refraction, and scattering. Since the signals from multiple paths arrive at different times, they can cause constructive or destructive interference, leading to signal enhancement or attenuation.

**Multipath model:**  
For each path, the signal strength and arrival time can be calculated as follows:

$$
\text{Signal Strength} = P_0 \cdot d^\alpha \cdot \left( \sum_{i=1}^{N} \alpha_i \cos(\phi_i) \right)
$$

Where:
- \( P_0 \) is the initial signal strength,
- \( d \) is the length of the signal path,
- \( \alpha_i \) is the attenuation factor for the path,
- \( \phi_i \) is the phase offset for the path, and
- \( N \) is the number of multiple paths.

## 3. Signal Attenuation Model
Signal attenuation plays a critical role in Ray Tracing as it directly impacts positioning accuracy and signal strength estimation. Common attenuation models include:

### Free-Space Path Loss:

$$
L = 20 \log_{10}(d) + 20 \log_{10}(f) - 147.55
$$

Where:
- \( L \) is the path loss (in dB),
- \( d \) is the propagation distance (in meters), and
- \( f \) is the signal frequency (in Hertz).

### Log-Distance Path Loss:

$$
L = L_0 + 10 \cdot n \log_{10}\left( \frac{d}{d_0} \right)
$$

Where:
- \( L_0 \) is the loss at the reference distance \( d_0 \),
- \( n \) is the path loss exponent, which indicates the rate of signal attenuation.

## 4. Calculation Methods
Path calculation can be implemented using the following methods:

- **Ray Tracing Algorithm**: Emits rays from the signal source and detects intersections with obstacles to simulate the propagation path of the signal.
- **Monte Carlo Method**: Uses random sampling to simulate irregular scattering and reflection, particularly suitable for modeling scattering and multipath effects.
- **Iterative Algorithm**: Iteratively calculates signal propagation paths, especially in cases of multiple reflections and refractions, to more accurately estimate the final path.

## Summary
In Ray Tracing positioning, path calculation is a crucial mathematical task. It simulates multiple signal propagation paths, considers various propagation phenomena (such as direct propagation, reflection, refraction, scattering, and multipath effects), and applies appropriate mathematical models and calculation methods (e.g., free-space path loss, logarithmic distance path loss, ray tracing, Monte Carlo method, etc.) to achieve positioning. These calculation methods and models help optimize wireless communication systems, improve positioning accuracy, and provide more accurate signal propagation predictions in complex environments.
