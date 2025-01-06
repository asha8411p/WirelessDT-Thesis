# Pixel Streaming Implementation for WirelessDT

This document provides instructions for implementing Pixel Streaming in the **WirelessDT** project.

## Table of Contents
1. [Prerequisites](#prerequisites)  
   - [Check Your OS and Hardware](#check-your-os-and-hardware)  
   - [Install Node.js](#install-nodejs)  
   - [Open Network Ports](#open-network-ports)  
   - [Stop Other Web Servers](#stop-other-web-servers)  
   - [IP Addresses](#ip-addresses)  
2. [Prepare WirelessDT Application](#prepare-wirelessdt-application)  
3. [Run WirelessDT Locally (localhost)](#run-wirelessdt-locally-localhost)  
4. [Run WirelessDT Publicly](#run-wirelessdt-publicly)  
5. [Additional Information](#additional-information)

---

## Prerequisites

### Check Your OS and Hardware
The Pixel Streaming Plugin can encode video only on computers running **Windows** or **Linux** operating systems with specific GPU hardware.  
For detailed hardware requirements, see the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0).

### Install Node.js
If Node.js is not already installed, download and install it from the [official website](https://nodejs.org).

### Open Network Ports
Ensure the following network ports are open for local communication:
- **Port 80**
- **Port 8888**

If you need to modify these default settings, refer to the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0).

### Stop Other Web Servers
Stop any other web servers running on your computer to avoid conflicts.

### IP Addresses
To test Pixel Streaming over the internet:
- Determine the IP address of your computer.
- Start by testing on a **LAN** or **VPN**, using `localhost` or `127.0.0.1` as the IP address.

If connecting from a different network:
- Configure the signaling server to use a **STUN/TURN** server.
- For configuration details, see the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0).

---

## Prepare WirelessDT Application

1. **Open `WiTracingSim` in the Unreal Editor**.
2. **Enable Pixel Streaming Plugin**:  
   - Go to **Edit > Plugins**.  
   - Under the **Graphics** category, find **Pixel Streaming Plugin** and check **Enabled**.  
   - Click **Restart Now** when prompted.
3. **Enable Always Show Touch Interface**:  
   - Go to **Edit > Project Settings**.  
   - Under **Engine > Input**, find **Always Show Touch Interface** and enable it.
4. **Set Additional Launch Parameters**:  
   - Go to **Edit > Editor Preferences**.  
   - Under **Level Editor > Play**, find **Additional Launch Parameters**.  
   - Set its value to:  
     ```shell
     -AudioMixer -PixelStreamingURL=ws://127.0.0.1:8888
     ```
5. **Package Project for Windows**:  
   - From the main menu, choose **Platform > Windows (64-bit) > Package Project**.  
   - Select a destination folder.  
   - Wait for the packaging process to complete.  
   - Upon completion, locate the **Windows** folder in your chosen directory.

---

## Run WirelessDT Locally (localhost)

To run Pixel Streaming on your local machine (`localhost` or `127.0.0.1`), follow the steps below.

### Step 1: Start the Signaling Server

1. **Open PowerShell with admin privileges**.
2. **Navigate to the Unreal Engine installation folder** to find the Signaling Server under:  
   ```
   Samples/PixelStreaming/WebServers/SignallingWebServer
   ```
3. **Bypass the execution policy**:
   ```powershell
   Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Bypass
   ```
4. **Run the setup script**:
   ```powershell
   .\platform_scripts\cmd\setup.ps1
   ```
5. **Start the Signaling Server**:
   ```powershell
   .\platform_scripts\cmd\Start_SignallingServer.ps1
   ```

### Step 2: Create a Shortcut for WirelessDT

1. **Locate your WirelessDT `.exe` file** (the one that was generated when you packaged the project).  
2. **Press Alt and drag your `.exe` file** to create a shortcut in the same folder (or anywhere on your computer).
3. **Right-click the shortcut**, then choose **Properties**.
4. On the **Shortcut** tab, **append** the following text to the **Target** field:  
   ```
   -AudioMixer -PixelStreamingURL=ws://127.0.0.1:8888
   ```
   > *Note*: Ensure there is a space before the dash (`-AudioMixer`).

### Step 3: Launch & Connect

1. **Double-click the new shortcut** to open the WirelessDT application with Pixel Streaming enabled.
2. **Open a web browser** and go to [http://127.0.0.1:80](http://127.0.0.1:80) to connect to the Pixel Streaming session.

---

## Run WirelessDT Publicly

To access Pixel Streaming from outside the local network:

### Step 1: Download and Install ngrok

Go to the [ngrok official website](https://ngrok.com/) and download the tool.

After installing, authenticate ngrok with your account using the following command:
```shell
ngrok authtoken <your-auth-token>
```
You can find your auth token in your ngrok dashboard after logging in.

### Step 2: Expose Multiple Ports Simultaneously (Using ngrok Config File)

If you want to expose multiple ports at the same time, follow these steps:

1. Create or edit the ngrok config file.
   - **Windows**: `C:\Users\<your-username>\.ngrok2\ngrok.yml`
   - **macOS/Linux**: `~/.ngrok2/ngrok.yml`

2. Add the following content to the `ngrok.yml` file:
```yaml
authtoken: <your-auth-token>
tunnels:
  web80:
    proto: http
    addr: 80
  web8888:
    proto: http
    addr: 8888
```

3. Save the file and start both tunnels with this command:
```shell
ngrok start --all
```

### Step 3: Check the Public URLs
After starting ngrok, you'll see an output like this:
```
Forwarding    http://1234abcd.ngrok.io -> http://localhost:80
Forwarding    http://5678efgh.ngrok.io -> http://localhost:8888
```
**Note:** All the ngrok links shown in the output are unique to your session. Replace the placeholder links in the instructions with your own ngrok URLs.

### Step 4: Configure Unreal Engine

1. Open `WiTracingSim` in the Unreal Editor.

2. **Set Additional Launch Parameters**:  
   - Go to **Edit > Editor Preferences**.  
   - Under **Level Editor > Play**, find **Additional Launch Parameters**.  
   - Replace the IP with your ngrok URL, e.g., `ws://5678efgh.ngrok.io`.  
   - Set its value to:
     ```shell
     -AudioMixer -PixelStreamingURL=ws://5678efgh.ngrok.io
     ```

3. Package the project again (follow **Step 5** in the **Prepare WirelessDT Application** section).

### Step 5: Start the Signaling Server

1. **Open PowerShell with admin privileges**.
2. **Navigate to the Unreal Engine installation folder** to find the Signaling Server under:
   ```
   Samples/PixelStreaming/WebServers/SignallingWebServer
   ```
3. **Bypass the execution policy**:
   ```powershell
   Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Bypass
   ```
4. **Run the setup script**:
   ```powershell
   .\platform_scripts\cmd\setup.ps1
   ```
5. **Start the Signaling Server**:
   ```powershell
   .\platform_scripts\cmd\Start_SignallingServer.ps1
   ```

### Step 6: Create a Shortcut for the WirelessDT `.exe`

1. **Press Alt and drag your `.exe` file** to create a new shortcut in the same folder (or anywhere else on your computer).
2. **Modify the shortcut properties**:
   - Right-click the shortcut and choose **Properties** from the context menu.
   - On the **Shortcut** tab, append the following text to the **Target** field:
     ```
     -AudioMixer -PixelStreamingURL=ws://5678efgh.ngrok.io
     ```

### Step 7: Launch WirelessDT

1. Click the new shortcut to open the WirelessDT application.
2. **Connect in your browser**:
   - Open a web browser and go to your unique ngrok URL, e.g., [http://1234abcd.ngrok.io](http://1234abcd.ngrok.io).

---

## Additional Information

- Refer to the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0) for advanced configuration, troubleshooting tips, or integration details.
- For best performance, ensure your system meets **Unreal Engine 5** hardware recommendations and that your GPU drivers are up to date.

---

**© 2025 WirelessDT. All rights reserved.**

