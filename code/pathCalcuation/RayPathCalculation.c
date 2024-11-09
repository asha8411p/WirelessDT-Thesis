#include <stdio.h>
#include <math.h>

// Constants
#define PI 3.141592653589793
#define SPEED_OF_LIGHT 3.0e8  // m/s

// 3D Point structure
typedef struct {
    double x;
    double y;
    double z;
} Point;

// Function prototypes
double calculate_distance(Point p1, Point p2);
void line_of_sight(Point source, Point receiver);
void reflection(Point source, Point receiver, Point surface_normal);
void refraction(Point source, Point receiver, double n1, double n2);
double deg_to_rad(double deg);

int main() {
    // Example points (source and receiver)
    Point source = {0.0, 0.0, 0.0};
    Point receiver = {100.0, 0.0, 0.0}; // 100 meters away in x direction

    // Direct Line-of-Sight propagation
    line_of_sight(source, receiver);

    // Reflection example
    Point surface_normal = {0.0, 1.0, 0.0}; // A horizontal surface (Y-axis normal)
    reflection(source, receiver, surface_normal);

    // Refraction example (e.g., air to glass transition)
    refraction(source, receiver, 1.0, 1.5); // Air to Glass (n1 = 1.0, n2 = 1.5)

    return 0;
}

// Calculate the distance between two points in 3D space
double calculate_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

// Line-of-Sight propagation
void line_of_sight(Point source, Point receiver) {
    double distance = calculate_distance(source, receiver);
    printf("Line-of-Sight Distance: %.2f meters\n", distance);
    // Assuming free space, calculate the signal strength based on the free-space path loss formula
    double signal_strength = 1 / (distance * distance);  // Simplified loss model
    printf("Signal Strength (LOS): %.5f\n", signal_strength);
}

// Reflection propagation (simplified)
void reflection(Point source, Point receiver, Point surface_normal) {
    // Reflecting signal at a flat surface (assuming the source and receiver are on opposite sides)
    double distance = calculate_distance(source, receiver);
    printf("Reflection Distance: %.2f meters\n", distance);

    // Reflection angle = incidence angle (simple model assuming perfect reflection)
    double angle_of_incidence = 45.0; // Degrees
    double angle_of_reflection = angle_of_incidence; // For simplicity in this example

    // Convert angle to radians for calculations
    angle_of_reflection = deg_to_rad(angle_of_reflection);

    // Assuming perfect reflection, calculate new path (simplified)
    printf("Reflection Angle: %.2f degrees\n", angle_of_reflection * (180.0 / PI));
    // Calculate reflection path length (simplified)
    double reflected_distance = distance * 1.2;  // Increase distance due to reflection
    printf("Reflected Path Length: %.2f meters\n", reflected_distance);

    // Signal Strength for reflected path (simplified model)
    double signal_strength = 1 / (reflected_distance * reflected_distance);
    printf("Signal Strength (Reflection): %.5f\n", signal_strength);
}

// Refraction propagation (simplified using Snell's law)
void refraction(Point source, Point receiver, double n1, double n2) {
    // n1: refractive index of first medium (e.g., air = 1.0)
    // n2: refractive index of second medium (e.g., glass = 1.5)
    double angle_of_incidence = 30.0; // Degrees

    // Convert angle to radians
    double angle_of_incidence_rad = deg_to_rad(angle_of_incidence);

    // Snell's law: n1 * sin(theta1) = n2 * sin(theta2)
    double sin_theta2 = (n1 / n2) * sin(angle_of_incidence_rad);
    double angle_of_refraction_rad = asin(sin_theta2);
    double angle_of_refraction = angle_of_refraction_rad * (180.0 / PI);

    printf("Refraction Angle: %.2f degrees\n", angle_of_refraction);

    // Calculate new path length in the second medium
    double distance = calculate_distance(source, receiver);
    double refracted_distance = distance * (n1 / n2);  // Distance shortened due to refraction
    printf("Refracted Path Length: %.2f meters\n", refracted_distance);

    // Signal Strength for refracted path (simplified model)
    double signal_strength = 1 / (refracted_distance * refracted_distance);
    printf("Signal Strength (Refraction): %.5f\n", signal_strength);
}

// Convert degrees to radians
double deg_to_rad(double deg) {
    return deg * (PI / 180.0);
}
