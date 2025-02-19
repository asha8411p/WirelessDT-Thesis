# Instant-NGP + COLMAP Workflow

This guide walks through the steps to set up and use **Instant-NGP** and **COLMAP** to create a 3D model from images.

---

## Prerequisites
Make sure you have the following installed before starting:
- [Instant-NGP](https://github.com/NVlabs/instant-ngp)
- [COLMAP](https://colmap.github.io/)
- Python 3 with required dependencies

---

## Setup Instructions

### Step 1: Download and Install
1. **Download and install Instant-NGP**: Follow the official repository instructions.
2. **Download and install COLMAP**: Ensure COLMAP is properly installed and working.

### Step 2: Prepare Image Data
1. Create a folder named `images` and place the input images inside it.
2. Inside your working directory, create a subfolder named after your object (e.g., `your_object_name`).
3. Move the `images` folder into `your_object_name/`.
4. Copy the `scripts` folder from `instant-ngp` into `your_object_name/`.

### Step 3: Run COLMAP for 3D Reconstruction
1. Open **COLMAP**.
2. Click **File** → **New Project**.
3. Create a new database file (e.g., `database.db`).
4. Select the `images` folder inside `your_object_name/`.
5. Click **Processing** → **Feature extraction**.
6. Click **Processing** → **Feature matching**.
7. Click **Reconstruction** → **Start reconstruction**.
8. Once the reconstruction is complete, export the model:
   - Click **File** → **Export model as text**.
   - Save it inside `your_object_name/`.

### Step 4: Convert COLMAP Data to NeRF Format
1. Navigate to `your_object_name/` folder in a terminal:
   ```sh
   cd your_object_name
   ```
2. Run the following command:
   ```sh
   python scripts/colmap2nerf.py --images ./images --text ./ --out ./transforms.json
   ```

### Step 5: Run Instant-NGP
1. Open `instant-ngp.bat`.
2. Drag and drop `your_object_name/` folder into the GUI.
3. Wait until the loss value stabilizes (stops decreasing significantly).

### Step 6: Export 3D Model
1. Adjust the model settings as needed.
2. Click **Export** → Choose `mesh`, `volume`, or `slices`.
3. Set mesh render mode to **vertex colors**.
4. Save the output file.
5. The final 3D model (`.obj` file) is now ready!

---

## Notes
- Ensure high-quality input images for better reconstruction results.
- COLMAP may take time to process depending on the dataset size.
- Adjust Instant-NGP settings for better optimization.

---

## References
- [Instant-NGP GitHub](https://github.com/NVlabs/instant-ngp)
- [COLMAP Documentation](https://github.com/colmap/colmap/releases/tag/3.11.1/)

