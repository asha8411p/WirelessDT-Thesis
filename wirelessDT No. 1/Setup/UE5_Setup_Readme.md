# Unreal Engine 5 Setup Guide

This guide will walk you through setting up Unreal Engine 5 using Visual Studio.

---

## **Prerequisites**
- Windows 10/11
- Visual Studio 2022

---

## **Setup Instructions**

### **1. Download and Install Visual Studio**
1. Visit the [Visual Studio Official Website](https://visualstudio.microsoft.com/downloads/).
2. Download **Visual Studio 2022**.
3. Run the installer and follow the on-screen instructions.

---

### **2. Configure Visual Studio with .vsconfig**
To ensure the correct dependencies are installed, follow these steps:

1. **Launch Visual Studio Installer**.
2. Click on **"More"** (next to the installed Visual Studio version) and select **"Import configuration"**.
3. Browse to your project folder and select the `.vsconfig` file.
4. Click **"Open"**, then **"Modify"** to install the required components.
5. Wait for the installation to complete and restart Visual Studio.

---

### 3. Extract the Project Files

1. Download the required executable files:
   - [Visual Studio Installer EXE](https://drive.google.com/file/d/1bUPm428iqz7NHhr-odVWgWr5wosULWfb/view?usp=sharing)
   - [.NET Runtime EXE](https://drive.google.com/file/d/1SQtCK8G5Zqb4p-IWlxjCzt86Nv0U95Uo/view?usp=sharing)

2. Run both `.exe` files to install the necessary components.

3. Download the project source files:
   - [code_ue.zip](https://drive.google.com/file/d/1OdG1_JK2qkAv8jQt84gWu3lo08Pr6R62/view?usp=sharing)

4. Locate the downloaded `code_ue.zip` file.

5. Right-click on the file and select **"Extract All..."**.

6. Choose a destination folder (e.g., `C:\UE5Project\`) and extract the contents.


---

### **4. Run the Setup Script**
1. Navigate to the extracted folder.
2. Locate `Setup.bat`.
3. Right-click `Setup.bat` and select **"Run as administrator"**.
4. Wait for the script to download and install required dependencies.
5. Close the window once the setup is complete.

---

### **5. Generate Project Files**
1. In the same folder, locate `GenerateProjectFiles.bat`.
2. Right-click and select **"Run as administrator"**.
3. The script will generate Visual Studio solution files (`.sln`).
4. Wait for the process to complete.

---

### **6. Open Unreal Engine Solution in Visual Studio**
1. Open the extracted project directory.
2. Locate **`UE5.sln`**.
3. Double-click `UE5.sln` to launch it in **Visual Studio**.

---

### **7. Build Unreal Engine 5**
1. In Visual Studio, **set the build configuration**:
   - **Select "Development Editor"** from the drop-down menu.
   - **Select "Win64"** as the target platform.
2. Open the **Solution Explorer** (View → Solution Explorer).
3. Right-click the **UE5** project.
4. Select **"Build"**.
5. Wait for the build process to complete (this may take some time).
6. Once finished, you can launch Unreal Engine 5.

---

## **Troubleshooting**
- **Missing Dependencies?** Re-run `Setup.bat` and `GenerateProjectFiles.bat`.
- **Build Errors?** Ensure all Visual Studio dependencies were installed correctly via `.vsconfig`.
- **Slow Build?** Close unnecessary applications and ensure you have sufficient system resources.

---

## **Additional Resources**
- [Unreal Engine Documentation](https://docs.unrealengine.com/)
- [Visual Studio Setup Guide](https://docs.microsoft.com/en-us/visualstudio/install/)
- [Common UE5 Build Errors & Fixes](https://forums.unrealengine.com/)

---

Happy Developing! 🎮
