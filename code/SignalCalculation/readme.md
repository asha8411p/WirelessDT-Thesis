## Signal Propagation Loss and Signal Strength Estimation

### 1. Propagation Loss Model
Propagation loss refers to the attenuation of the signal as it travels through space, due to various environmental factors like distance, obstacles, and interference. The propagation loss is typically modeled using several standard path loss models. The most common models include the **Free-Space Path Loss (FSPL)** model and the **Logarithmic Distance Path Loss** model.

#### (a) Free-Space Path Loss (FSPL)
The **Free-Space Path Loss** is a model for signal attenuation that assumes line-of-sight (LOS) propagation in an ideal environment without any obstacles.

The formula for free-space path loss is:

$$
L = 20 \log_{10}(d) + 20 \log_{10}(f) - 147.55 \, \text{dB}
$$

Where:
- $L$ is the path loss in dB,
- $d$ is the distance between the signal source and the receiving point (in meters),
- $f$ is the signal frequency (in Hz).

This model assumes that the signal propagates through free space and does not encounter any obstacles, such as walls or buildings. The path loss increases with distance and frequency, as the signal strength diminishes over long distances and higher frequencies.

#### (b) Logarithmic Distance Path Loss
In real-world environments, the signal often propagates through obstructed or non-ideal conditions, such as walls, trees, and buildings. The **Log-Distance Path Loss Model** accounts for these factors and estimates the signal attenuation based on the distance and environment.

The logarithmic distance path loss model is given by:

$$
L(d) = L_0 + 10 \cdot n \log_{10}\left(\frac{d}{d_0}\right)
$$

Where:
- $L(d)$ is the path loss at distance $d$ (in dB),
- $L_0$ is the path loss at a reference distance $d_0$ (in dB),
- $n$ is the path loss exponent (dimensionless), which represents the environment's effect on signal attenuation. Typical values range from 2 (in free space) to 4 or higher (in urban environments),
- $d$ is the distance between the signal source and the receiver (in meters),
- $d_0$ is the reference distance (in meters).

The path loss exponent $n$ varies depending on the environment. For instance:
- In **free space**, $n \approx 2$,
- In **urban environments**, $n$ typically ranges from 2.7 to 4,
- In **dense indoor environments**, $n$ can be higher than 4.

#### (c) Signal Strength Estimation
Signal strength $P_{\text{received}}$ at the receiver can be determined based on the path loss model and the transmitted power $P_{\text{transmitted}}$:

$$
P_{\text{received}} = P_{\text{transmitted}} - L
$$

Where:
- $P_{\text{received}}$ is the received signal strength (in dB),
- $P_{\text{transmitted}}$ is the transmitted signal strength (in dB),
- $L$ is the path loss (in dB).

If multiple paths are considered (due to reflection, refraction, scattering, etc.), the total received signal strength is the sum of the contributions from all paths.

### 2. Positioning Calculation Based on Signal Strength

The positioning system can leverage the signal strength measurements at different locations, computed using Ray Tracing, to estimate the position of the target device. There are two main positioning methods: **Triangulation** and **Fingerprinting**.

#### (a) Triangulation Positioning Method
Triangulation is a widely used technique for determining the position of a target device by using the signal strength differences between multiple known reference points (e.g., base stations or access points). It involves the following steps:

1. **Signal Strength Difference**: Measure the signal strength at the target point from multiple base stations. Let $P_1, P_2, P_3$ be the received signal strengths from three base stations located at known positions $S_1(x_1, y_1)$, $S_2(x_2, y_2)$, and $S_3(x_3, y_3)$.

2. **Path Loss Calculation**: Use the propagation models (e.g., FSPL or logarithmic distance) to compute the signal strength difference between each pair of base stations and the target point.

3. **Distance Estimation**: From the signal strength difference, estimate the distance between the target and each base station. The distance $d_i$ between base station $i$ and the target can be found using the inverse of the propagation loss model, for example:

   $$ 
   d_i = 10^{\frac{P_{\text{transmitted}} - P_{\text{received},i}}{10n}} \quad \text{(for Log-Distance Path Loss)}
   $$

4. **Position Calculation**: Once the distances $d_1, d_2, d_3$ from the three base stations are determined, use **trilateration** to find the target's position $(x, y)$. Trilateration is a geometric method that uses the distances between the target and the base stations to solve for the unknown coordinates of the target.

   The trilateration equations are as follows:
   
   $$ 
   (x - x_1)^2 + (y - y_1)^2 = d_1^2 
   $$
   
   $$ 
   (x - x_2)^2 + (y - y_2)^2 = d_2^2 
   $$

   $$ 
   (x - x_3)^2 + (y - y_3)^2 = d_3^2 
   $$

   These three equations can be solved simultaneously to estimate the position $(x, y)$ of the target device.

#### (b) Fingerprinting Positioning Method
Fingerprinting is a method where signal strength measurements are used to build a database of signal characteristics at known locations. When a target is present at an unknown location, its signal strength is measured and matched with the database to infer its position.

1. **Database Creation**: Collect signal strength data at known locations in the environment. This is typically done by measuring the signal strength $P_{\text{received}}$ from multiple reference points (base stations, access points, etc.) at different locations in the area of interest.

2. **Database Query**: When a target device needs to be located, measure the received signal strength $P_{\text{received}}$ at the unknown location from multiple sources. These measurements will form a "fingerprint" of the environment.

3. **Matching Algorithm**: Compare the target’s fingerprint with the database to find the closest match. The position of the known fingerprint that matches the target’s measurements most closely is taken as the estimated position.

Fingerprinting can be implemented using various matching algorithms, including:
- **Nearest Neighbor (NN)**: Simply find the closest matching fingerprint in the database.
- **K-Nearest Neighbors (K-NN)**: Find the $k$ closest fingerprints and average their positions to estimate the target’s position.
- **Weighted Average**: Weight the fingerprints according to their similarity and compute the weighted average of their positions.

### 3. Positioning Calculation
- **Triangulation** requires multiple base stations with known positions and uses the difference in signal strength to estimate the target's position.
- **Fingerprinting** creates a signal strength database for a given environment and matches the current signal measurements with that database to infer the target’s position.

Both methods rely heavily on accurate signal strength estimation, which is influenced by factors such as path loss, multi-path interference, and environmental obstacles. The reliability of these methods can be improved by using advanced techniques like Ray Tracing, machine learning for fingerprinting, or adaptive filtering for multipath mitigation.
