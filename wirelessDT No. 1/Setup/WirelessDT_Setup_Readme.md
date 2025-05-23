## Running WirelessDT

### Step 1: Clone the Repository
```sh
git clone https://github.com/codelzz/WirelessDT.git](https://drive.google.com/file/d/1GqdW80Q6eF1428vUqnTjujZy5fJ5J6uT/view?usp=sharing
```

### Step 2: Compile the Project
1. Right-click the `.uproject` file, then select **Switch Unreal Engine Version...** and choose the appropriate source build. This will associate WirelessDT with the WiTracing Unreal Engine.
2. Right-click the `.uproject` file again and select **Generate Visual Studio project file**. A solution file (`.sln`) should appear.
3. Open the `.sln` file in Visual Studio and compile the project.

### Step 3: Run the Digital Twin Platform
After compilation:
1. Double-click the `.uproject` file to launch the platform.
2. The default game level is `DemoOffice_30mx30m`, which can be executed without a Physical Twin.
   - To switch to another map, navigate to **All > Content > Demo > Map** in the Content folder.
   - The `DemoCorridor_Calibration` level is a calibration environment that requires a Physical Twin.
3. Click the **Play** button in the Unreal Editor to start the platform.

