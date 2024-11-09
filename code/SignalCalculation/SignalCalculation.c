#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Constants for signal transmission
#define P_TRANSMITTED -50  // Transmitted signal strength in dB (example)

// Function to calculate Free-Space Path Loss (FSPL)
double calculate_fspl(double distance, double frequency) {
    // FSPL formula: L = 20*log10(d) + 20*log10(f) - 147.55
    return 20 * log10(distance) + 20 * log10(frequency) - 147.55;
}

// Function to calculate Log-Distance Path Loss
double calculate_log_distance_loss(double distance, double n, double reference_distance) {
    // Log-distance path loss: L = L0 + 10 * n * log10(d / d0)
    double L0 = 20 * log10(reference_distance) + 20 * log10(1.0); // assuming a reference distance of 1 meter
    return L0 + 10 * n * log10(distance / reference_distance);
}

// Function to calculate received signal strength
double calculate_received_signal(double transmitted_signal, double path_loss) {
    return transmitted_signal - path_loss;
}

// Triangulation Positioning: Using trilateration to solve for the target position
void triangulation_positioning(double d1, double d2, double d3, 
                                double x1, double y1, double x2, double y2, double x3, double y3) {
    // Calculate the intersection of three circles (based on distances and coordinates of base stations)
    double A = 2 * (x2 - x1);
    double B = 2 * (y2 - y1);
    double C = 2 * (x3 - x1);
    double D = 2 * (y3 - y1);
    double E = (d1 * d1 - d2 * d2) + (x2 * x2 - x1 * x1) + (y2 * y2 - y1 * y1);
    double F = (d1 * d1 - d3 * d3) + (x3 * x3 - x1 * x1) + (y3 * y3 - y1 * y1);

    // Solve for x and y using linear equations
    double x = (E - F * B / D) / (A - C * B / D);
    double y = (E - A * x) / B;

    printf("Estimated position: (%.2f, %.2f)\n", x, y);
}

// Fingerprinting Positioning: Match signal strength with known positions
void fingerprint_positioning(double received_signal, double known_signals[], double known_positions[][2], int num_points) {
    double min_distance = INFINITY;
    int closest_point = -1;

    // Find the closest match for the received signal
    for (int i = 0; i < num_points; i++) {
        double distance = fabs(received_signal - known_signals[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_point = i;
        }
    }

    if (closest_point != -1) {
        printf("Target estimated position: (%.2f, %.2f) based on fingerprint matching\n", 
                known_positions[closest_point][0], known_positions[closest_point][1]);
    } else {
        printf("No match found for the received signal.\n");
    }
}

int main() {
    // Example for Free-Space Path Loss Calculation
    double distance = 1000;  // Distance in meters
    double frequency = 2400000000;  // Frequency in Hz (2.4 GHz)
    double path_loss_fspl = calculate_fspl(distance, frequency);
    printf("Free-Space Path Loss: %.2f dB\n", path_loss_fspl);

    // Example for Log-Distance Path Loss Calculation
    double n = 3.5;  // Path loss exponent for urban area
    double reference_distance = 1.0;  // Reference distance in meters
    double path_loss_log = calculate_log_distance_loss(distance, n, reference_distance);
    printf("Log-Distance Path Loss: %.2f dB\n", path_loss_log);

    // Example for Triangulation Positioning
    double d1 = 1000, d2 = 1500, d3 = 1200;  // Distances from three base stations
    double x1 = 0, y1 = 0, x2 = 1000, y2 = 0, x3 = 500, y3 = 800;
    triangulation_positioning(d1, d2, d3, x1, y1, x2, y2, x3, y3);

    // Example for Fingerprinting Positioning
    double received_signal = -60;  // Received signal strength in dB
    double known_signals[] = {-55, -60, -65, -70};  // Signal strengths at known positions
    double known_positions[][2] = {{0, 0}, {100, 0}, {50, 50}, {200, 100}};  // Known positions
    int num_points = 4;
    fingerprint_positioning(received_signal, known_signals, known_positions, num_points);

    return 0;
}
