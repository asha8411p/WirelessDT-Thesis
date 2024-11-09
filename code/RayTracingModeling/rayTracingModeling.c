#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define constants and helper functions
#define PI 3.14159265359
#define MAX_RECURSION_DEPTH 3
#define LIGHT_INTENSITY 1.0

// Vector structure
typedef struct {
    double x, y, z;
} Vector;

// Ray structure
typedef struct {
    Vector origin;
    Vector direction;
} Ray;

// Sphere structure
typedef struct {
    Vector center;
    double radius;
} Sphere;

// Light structure
typedef struct {
    Vector position;
    double intensity;
} Light;

// Function prototypes
Vector vec_add(Vector a, Vector b);
Vector vec_subtract(Vector a, Vector b);
Vector vec_multiply(Vector v, double scalar);
Vector vec_normalize(Vector v);
double vec_dot(Vector a, Vector b);
Vector vec_reflect(Vector v, Vector n);
Vector vec_cross(Vector a, Vector b);
double ray_sphere_intersect(Ray r, Sphere s);
Vector calculate_color(Ray r, Sphere *spheres, int num_spheres, Light light, int depth);

// Vector operations
Vector vec_add(Vector a, Vector b) {
    Vector result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vector vec_subtract(Vector a, Vector b) {
    Vector result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

Vector vec_multiply(Vector v, double scalar) {
    Vector result = {v.x * scalar, v.y * scalar, v.z * scalar};
    return result;
}

Vector vec_normalize(Vector v) {
    double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    Vector result = {v.x / length, v.y / length, v.z / length};
    return result;
}

double vec_dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector vec_reflect(Vector v, Vector n) {
    double dot = vec_dot(v, n);
    return vec_subtract(v, vec_multiply(n, 2 * dot));
}

Vector vec_cross(Vector a, Vector b) {
    Vector result = {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
    return result;
}

// Ray-sphere intersection
double ray_sphere_intersect(Ray r, Sphere s) {
    Vector oc = vec_subtract(r.origin, s.center);
    double a = vec_dot(r.direction, r.direction);
    double b = 2.0 * vec_dot(oc, r.direction);
    double c = vec_dot(oc, oc) - s.radius * s.radius;
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0) return -1.0;
    else {
        double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
        return fmin(t1, t2); // Return the nearest intersection
    }
}

// Simple lighting calculation
Vector calculate_lighting(Vector point, Vector normal, Light light) {
    Vector light_dir = vec_subtract(light.position, point);
    light_dir = vec_normalize(light_dir);
    double diff = fmax(0.0, vec_dot(normal, light_dir));
    Vector diffuse = vec_multiply(light_dir, diff * light.intensity);

    return diffuse;
}

// Phong reflection model
Vector calculate_specular(Vector point, Vector normal, Ray r, Light light) {
    Vector light_dir = vec_subtract(light.position, point);
    light_dir = vec_normalize(light_dir);
    Vector reflect_dir = vec_reflect(vec_multiply(r.direction, -1.0), normal);
    double spec = pow(fmax(0.0, vec_dot(reflect_dir, light_dir)), 32); // 32 is the shininess coefficient
    return vec_multiply(light_dir, spec * light.intensity);
}

// Calculate the color at a point using ray tracing
Vector calculate_color(Ray r, Sphere *spheres, int num_spheres, Light light, int depth) {
    double t_min = INFINITY;
    Sphere *hit_sphere = NULL;

    // Find the nearest sphere intersection
    for (int i = 0; i < num_spheres; i++) {
        double t = ray_sphere_intersect(r, spheres[i]);
        if (t > 0.0 && t < t_min) {
            t_min = t;
            hit_sphere = &spheres[i];
        }
    }

    // If no intersection, return background color
    if (hit_sphere == NULL) {
        return (Vector){0.0, 0.0, 0.0}; // Black background
    }

    // Calculate intersection point and normal
    Vector intersection = vec_add(r.origin, vec_multiply(r.direction, t_min));
    Vector normal = vec_subtract(intersection, hit_sphere->center);
    normal = vec_normalize(normal);

    // Calculate lighting
    Vector diffuse = calculate_lighting(intersection, normal, light);
    Vector specular = calculate_specular(intersection, normal, r, light);

    // Combine diffuse and specular components
    Vector color = vec_add(diffuse, specular);

    // Reflection: If recursion depth is allowed, reflect the ray
    if (depth < MAX_RECURSION_DEPTH) {
        Vector reflect_dir = vec_reflect(r.direction, normal);
        Ray reflect_ray = {intersection, reflect_dir};
        Vector reflect_color = calculate_color(reflect_ray, spheres, num_spheres, light, depth + 1);
        color = vec_add(color, reflect_color);
    }

    return color;
}

int main() {
    // Set up the scene
    Sphere spheres[] = {
        {{0.0, 0.0, -5.0}, 1.0},
        {{2.0, 0.0, -6.0}, 1.0}
    };
    int num_spheres = sizeof(spheres) / sizeof(Sphere);

    Light light = {{5.0, 5.0, -5.0}, LIGHT_INTENSITY};

    // Set up the camera
    Ray camera_ray = {{0.0, 0.0, 0.0}, {0.0, 0.0, -1.0}};
    
    // Render the image
    int width = 400, height = 400;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double u = (x - width / 2.0) / width;
            double v = (y - height / 2.0) / height;
            
            Ray ray = {{0.0, 0.0, 0.0}, {u, v, -1.0}};
            ray.direction = vec_normalize(ray.direction);
            
            Vector color = calculate_color(ray, spheres, num_spheres, light, 0);
            
            printf("Pixel (%d, %d): Color = (%f, %f, %f)\n", x, y, color.x, color.y, color.z);
        }
    }

    return 0;
}
