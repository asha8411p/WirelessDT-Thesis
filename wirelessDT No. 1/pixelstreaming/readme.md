# Pixel Streaming Implementation for WirelessDT

This README provides instructions for implementing Pixel Streaming in the WirelessDT project.

---

## Prerequisites

Before building and running the project, ensure the following prerequisites are met:

### 1. Check Your OS and Hardware
The Pixel Streaming Plugin can encode video only on computers running **Windows** or **Linux** operating systems with specific GPU hardware.  
- For detailed hardware requirements, see the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0).

### 2. Install Node.js
If Node.js is not already installed, download and install it from the [official website](https://nodejs.org).

### 3. Open Network Ports
Ensure the following network ports are open for local communication:
- **Port 80**
- **Port 8888**

If you need to modify these default settings, refer to the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0).

### 4. Stop Other Web Servers
Stop any other Web servers running on your computer to avoid conflicts.

### 5. IP Addresses
To test Pixel Streaming over the internet:
- Determine the IP address of your computer.
- Begin with testing on a **LAN** or **VPN** using `localhost` or `127.0.0.1` as the IP address.

If connecting from a different network:
- Configure the signaling server to use a **STUN/TURN server**.
- For configuration details, see the [Pixel Streaming Reference](https://dev.epicgames.com/documentation/en-us/unreal-engine/unreal-engine-pixel-streaming-reference?application_version=5.0).

---

## Step 1: Prepare WirelessDT Application

Follow the steps below to prepare your application for Pixel Streaming:

---

This documentation will guide you through additional steps for setting up Pixel Streaming after building the project.
