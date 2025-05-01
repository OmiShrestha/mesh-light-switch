# Bluetooth Mesh: Light Switch

## Overview
This project demonstrates how to use Bluetooth Mesh to control light sources in a network. It uses the Generic OnOff Client model to send commands to other devices in the same mesh network. The light switch acts as a client, while the light sources act as servers.

You can pair this project with the Bluetooth Mesh Light sample to see how it works in a real mesh network.

### Key Features:
- Control light sources using buttons on a development kit.
- Support for Low Power Node (LPN) mode to save energy.
- Works with Nordic Semiconductor's nRF Mesh mobile app for provisioning and configuration.

---

## Requirements

### Hardware:
- At least two development kits:
  - One for this light switch sample (client).
  - One or more for the Bluetooth Mesh Light sample (server).

### Software:
- Nordic Semiconductor's nRF Mesh mobile app:
  - Available for Android and iOS.

---

## How It Works

### What is Bluetooth Mesh?
Bluetooth Mesh is a network where devices (nodes) communicate with each other. Each node can send and receive messages, making it ideal for smart lighting, home automation, and more.

### What Does This Project Do?
This project sets up a Bluetooth Mesh client that:
- Sends On/Off commands to light sources (servers) in the network.
- Uses buttons on the development kit to control the lights.
- Reflects the light status using LEDs on the development kit.

### How Does It Work?
1. **Provisioning**: The device is added to the mesh network using the nRF Mesh mobile app.
2. **Configuration**: The app sets up how the client (light switch) communicates with the servers (light sources).
3. **Control**: Pressing a button sends a command to turn a light on or off.

---

## Low Power Node (LPN) Mode

### What is LPN Mode?
LPN mode reduces power consumption by:
- Sleeping most of the time.
- Waking up only to send or receive messages.

### How to Enable LPN Mode:
1. Use the `overlay-lpn.conf` file during the build process.
2. Example build command:
   ```
   west build -b <board_target> -p -- -DEXTRA_CONF_FILE="overlay-lpn.conf"
   ```

### LPN Mode Features:
- Button 4 (or Button 3 on some boards) enables Node ID advertisement for 30 seconds.
- After 30 seconds, the device returns to low-power mode.

---

## Buttons and LEDs

### Buttons:
- Used for provisioning and controlling lights.
- Each button is linked to a specific light source.

### LEDs:
- Show the status of the lights.
- Blink during provisioning to indicate activity.

---

## Building and Running

### Steps:
1. Make sure Bluetooth Mesh is enabled in your environment.
2. Build the project using the appropriate configuration.
3. Flash the firmware to your development kit.

### Example Build Command:
```bash
west build -b <board_target>
```

---

## Testing

### What You Need:
- A smartphone with the nRF Mesh mobile app.
- At least one server device running the Bluetooth Mesh Light sample.

### Steps:
1. Provision the light switch using the app.
2. Configure the client and server models.
3. Press buttons on the client to control the lights on the server.

---

## Power Consumption

### Standard vs. LPN Mode:
- Standard mode: Higher power consumption.
- LPN mode: Significantly lower power consumption.

### Example Measurements:
| Board                | Standard Mode | LPN Mode |
|----------------------|---------------|----------|
| nrf52dk/nrf52832     | 7.14 mA       | 13.69 µA |
| nrf52840dk/nrf52840  | 6.71 mA       | 14.63 µA |
| nrf52833dk/nrf52833  | 6.10 mA       | 14.43 µA |

---

## Dependencies

### Nordic Libraries:
- Generic OnOff Client model.
- Device provisioning library.
- Buttons and LEDs library.

### Zephyr Libraries:
- Bluetooth Mesh API.
- Kernel API.

---

## Source Files

### `main.c`:
Handles initialization and Bluetooth setup.

### `model_handler.c`:
Manages the mesh models and button actions.

---

## Additional Notes
- This project cannot demonstrate functionality on its own. It needs a server device running the Bluetooth Mesh Light sample.
- For detailed configuration options, refer to the `overlay-lpn.conf` file.

