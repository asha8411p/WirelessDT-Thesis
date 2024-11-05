# Mathematical Modeling of Ray Tracing

Ray tracing is a powerful rendering technique used in computer graphics to simulate the behavior of light as rays that travel through a scene and interact with surfaces. The basic idea of ray tracing involves tracing the path of rays from a camera (viewer's perspective) into a 3D scene, determining what objects the rays intersect, and calculating the lighting at the intersection points to generate realistic images.

## 1. Ray Representation

A ray $\mathbf{r}(t)$ can be mathematically represented as a parametric equation of a line:

$$
\mathbf{r}(t) = \mathbf{o} + t \cdot \mathbf{d}
$$

Where:

- $\mathbf{o}$ is the ray's origin (the point where the ray starts, typically the camera or the eye).
- $\mathbf{d}$ is the direction of the ray (a unit vector indicating the direction in which the ray travels).
- $t$ is the parameter that controls how far along the ray the point lies (i.e., the distance from the origin). As$ t$ increases, the ray extends further from its origin.

## 2. Ray-Object Intersection

To find what the ray intersects in the scene, we need to solve for the intersection points between the ray and objects in the scene. The most common objects in ray tracing are spheres and planes.

### a) Ray-Sphere Intersection

For a ray $\mathbf{r}(t) = \mathbf{o} + t \cdot \mathbf{d}$ and a sphere with center $\mathbf{C}$ and radius $r$, the intersection condition is:

$$
\| \mathbf{r}(t) - \mathbf{C} \|^2 = r^2
$$

Substituting the ray equation into this gives:

$$
\| \mathbf{o} + t \cdot \mathbf{d} - \mathbf{C} \|^2 = r^2
$$

Expanding this equation leads to a quadratic equation in$ t$:

$$
A t^2 + B t + C = 0
$$

Where:

- $A = \mathbf{d} \cdot \mathbf{d}$
- $B = 2 \cdot \mathbf{d} \cdot (\mathbf{o} - \mathbf{C})$
- $C = (\mathbf{o} - \mathbf{C}) \cdot (\mathbf{o} - \mathbf{C}) - r^2$

Solving this quadratic equation for $t$ gives the points where the ray intersects the sphere. If the discriminant $\Delta = B^2 - 4AC$ is negative, there is no intersection; if$\Delta \geq 0$, the ray intersects the sphere at one or two points.

### b) Ray-Plane Intersection

For a ray $\mathbf{r}(t) = \mathbf{o} + t \cdot \mathbf{d}$ and a plane with normal vector $\mathbf{n}$ and a point $\mathbf{p_0}$ on the plane, the intersection can be found using:

$$
( \mathbf{r}(t) - \mathbf{p_0} ) \cdot \mathbf{n} = 0
$$

Substituting$\mathbf{r}(t) = \mathbf{o} + t \cdot \mathbf{d}$ into this equation, we get:

$$
( \mathbf{o} + t \cdot \mathbf{d} - \mathbf{p_0} ) \cdot \mathbf{n} = 0
$$

Solving for$ t$:

$$
t = \frac{( \mathbf{p_0} - \mathbf{o} ) \cdot \mathbf{n}}{\mathbf{d} \cdot \mathbf{n}}
$$

If $\mathbf{d} \cdot \mathbf{n} = 0$, the ray is parallel to the plane, and if $t$ is positive, the ray intersects the plane at a point.

## 3. Shading and Lighting

Once the intersection point is found, the next step is to calculate the lighting at that point to determine the color and intensity of the pixel. The lighting model typically consists of the following components:

- **Ambient light**: A constant amount of light that affects all surfaces equally, regardless of their orientation.
- **Diffuse reflection**: Light scattered in all directions from the surface, based on the angle between the surface normal and the incoming light direction.
- **Specular reflection**: The bright spots that appear on shiny surfaces due to light reflecting off the surface at a particular angle.

### a) Lambertian Diffuse Lighting

The diffuse reflection is computed using Lambert’s law:

$$
I_{\text{diffuse}} = I_{\text{light}} \cdot \max(0, \mathbf{n} \cdot \mathbf{l})
$$

Where:

- $I_{\text{light}}$ is the intensity of the light source.
- $\mathbf{n}$ is the normal vector at the intersection point.
- $\mathbf{l}$ is the normalized direction from the intersection point to the light source.

### b) Phong Specular Lighting

The specular reflection can be computed using the Phong reflection model:

$$
I_{\text{specular}} = I_{\text{light}} \cdot \max(0, \mathbf{r} \cdot \mathbf{v})^\alpha
$$

Where:

- $\mathbf{r}$ is the reflection vector of the incoming light direction.
- $\mathbf{v}$ is the normalized view direction (from the intersection point to the camera).
- $\alpha$ is the shininess exponent (controls the size of the specular highlight).

### c) Total Lighting

The total lighting$ I_{\text{total}}$ at the intersection point is the sum of the ambient, diffuse, and specular components:

$$
I_{\text{total}} = I_{\text{ambient}} + I_{\text{diffuse}} + I_{\text{specular}}
$$

## 4. Reflection and Refraction

In ray tracing, we also account for reflection and refraction, which allows rays to bounce off surfaces or pass through transparent objects.

### a) Reflection

The reflection direction is computed using the reflection formula:

$$
\mathbf{r}_{\text{reflected}} = \mathbf{d} - 2 (\mathbf{d} \cdot \mathbf{n}) \cdot \mathbf{n}
$$

Where$\mathbf{d}$ is the incoming ray direction and$\mathbf{n}$ is the normal vector at the intersection point.

### b) Refraction

For transparent surfaces, refraction is calculated using Snell’s law:

$$
\frac{\sin(\theta_1)}{\sin(\theta_2)} = \frac{n_1}{n_2}
$$

Where$\theta_1$ is the angle of incidence,$\theta_2$ is the angle of refraction, and$ n_1$ and$ n_2$ are the refractive indices of the two media. The direction of the refracted ray can be computed accordingly.

## 5. Recursive Ray Tracing

Ray tracing can be recursive: After finding an intersection, if the surface is reflective or transparent, we trace additional rays (reflection rays and refraction rays) and compute their intersections and lighting. This process continues recursively until a maximum recursion depth is reached, or the rays no longer interact with any objects (e.g., they go into infinity).

## Summary of the Mathematical Model

In ray tracing, the main computational steps are:

- **Ray Equation**: A ray is defined by an origin$\mathbf{o}$ and a direction$\mathbf{d}$.
- **Ray-Object Intersection**: Find the intersection between rays and objects (e.g., spheres, planes, or other geometric shapes).
- **Lighting Calculation**: Compute lighting based on the intersection point using ambient, diffuse, and specular components.
- **Reflection and Refraction**: Handle reflective and refractive surfaces by recursively tracing new rays.
- **Shading**: Apply appropriate shading models (e.g., Lambertian diffuse, Phong specular) to compute the final pixel color.

These ray tracing algorithms are widely used in high-quality rendering in graphics, computer games, and visual effects.
