# Ray Tracing Positioning Code 
This code folder contains the core implementation for a Ray Tracing-based positioning system. The goal of this system is to simulate signal propagation in complex environments, estimate signal strength, and provide accurate positioning based on the Ray Tracing method. The code is organized into several modules, each dedicated to a specific part of the positioning process.

## Modules Overview
### 1. **RayTracingModeling**
The `RayTracingModeling` module is responsible for creating and maintaining the 3D environmental model used in Ray Tracing simulations. This model includes all the physical obstacles, terrain features, and surfaces that may affect the propagation of signals. The module uses geometric data to represent the environment, which is critical for simulating how signals interact with different materials, such as walls, windows, and furniture.

Key functionalities of this module:
- Construction of 3D models based on input data (CAD files, scanned data, or sensor readings).
- Representation of various environmental features, including reflective and refractive surfaces.
- Support for dynamic environments (if applicable).

### 2. **SignalCalculation**
The `SignalCalculation` module focuses on estimating signal strength and attenuation along the paths simulated by Ray Tracing. It calculates the power loss and signal degradation caused by distance, reflection, refraction, and other environmental factors. This module uses different path loss models to determine the expected signal strength at the receiver, taking into account the interaction of the signal with the environment.

Key functionalities of this module:
- Calculation of signal attenuation using path loss models (e.g., free space, log-distance).
- Estimation of received signal strength based on path characteristics.
- Handling of multipath effects, including constructive and destructive interference.

### 3. **PathCalculation**
The `PathCalculation` module is the core engine for simulating the paths that a signal can take from the source to the receiver. This module calculates both the direct Line-of-Sight (LOS) path and the reflected, refracted, or scattered paths. It is responsible for modeling how electromagnetic waves propagate through the environment, including handling multipath propagation and signal interference.

Key functionalities of this module:
- Calculation of direct and indirect signal paths.
- Simulation of reflection, refraction, and scattering effects.
- Handling of multipath propagation and interference effects.
- Generation of path loss distribution maps.

## Code Structure
The code is modularized into distinct components to allow easy testing, maintenance, and extension. The modules can be integrated together to simulate a complete Ray Tracing positioning system. Below is a brief overview of the directory structure:

