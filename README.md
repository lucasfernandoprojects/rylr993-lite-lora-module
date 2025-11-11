# RYLR993 Lite LoRa Module with Arduino
I've recently posted a tutorial about this project on YouTube. You can watch it [here](https://www.youtube.com/).

[ADDING A PHOTO OF THE PROJECT]

### 🚀OVERVIEW
This project demonstrates how two Arduino boards can communicate wirelessly using LoRa, specifically with the [RYLR993 Lite module](https://reyax.com/products/RYLR993_Lite).

You’ll learn how to send and receive simple commands between two devices:
+**Device 1**: Sends a signal when a button is pressed and receives a command to toggle its LED.
+**Device 2**: Does the opposite - when you press its button, it sends a signal to toggle the LED on Device 1.

It’s a great beginner-friendly project to understand how LoRa communication works, how to use the Serial interface for AT commands, and how to create a simple wireless network between microcontrollers.

[ADD PHOTOS OF THE PROJECT WORKING]

### 🧠WHAT YOU'LL LEARN

+How LoRa works and what makes it ideal for long-distance, low-power communication.
+How to wire and configure RYLR993 Lite modules.
+How to send and receive data using AT commands.
+How to program Arduino boards to communicate wirelessly.
+How to debug data using the Serial Monitor.

If you’re new to LoRa, this project gives you both the theory and the hands-on practice you need to get started confidently.

### 🧰LIST OF MATERIALS

| Item            | Quantity |
|--------------------------|-------------|
| Arduino boards (UNO, NANO, etc)               | 2 |
| RYLR993 Lite                                  | 2 |
| Push button                                   | 2 |
| LED                                           | 2 |
| 220Ω resistor                                 | 2 |
| 5kΩ resistor                                  | 6 |
| Breadboard                                    | Several |
| Jumper wires                                  | Several |

### ⚙️WIRING

Follow the schematics below to assemble all components.

[ADD THE SCHEMATICS]

In the end, you'll have something like this:

[ADD PHOTOS OF THE PROJECT]

### 💡HOW THE PROJECT WORKS

Each module has its own address and shares the same network ID and frequency band.

When a button is pressed on one board, it sends a message (LED2) to the other device’s address.

The receiving module reads the incoming data via the Serial interface, checks for the keyword, and toggles its LED accordingly.

The same happens when you press the button on the second board. The module sends a message (LED1) to the first Arduino, and it responds accordingly.

This system creates a bidirectional communication channel, a small but powerful demonstration of how LoRa can be used for remote control or telemetry projects.

[ADD DRAWINGS THAT EXEMPLIFY THIS]

After uploading the sketches to your boards, you'll get this:

[ADD PHOTOS OF YOU TESTING THE PROJECT]

If you are having trouble understanding how to use the Serial Monitor or code Arduino programs, I have two tutorials on my channel that will help you with that.

The first is all about the [Serial Monitor](https://www.youtube.com/watch?v=yYrZRBsFJ3s&t=32s) and how to use it in your projects. The second is a complete tutorial about [Arduino programming](https://www.youtube.com/watch?v=SirbF6jwFdc&t=42s). Check them out to level up your skills.

### 🧩HOW THE LORA MODULE WORKS

Let’s take a closer look at the RYLR993 Lite module. It has five pins: VCC, GND, RX, TX, and RESET.
+**VCC** and **GND** are the power supply pins. The module runs on 3 to 3.6 volts, so never connect it directly to a 5V pin (you’ll fry it instantly).
+**TX** and **RX** are the serial communication pins, used to exchange data with your Arduino. The RX pin accepts only up to 3.6V, so you’ll need a voltage divider to bring the Arduino’s 5V signal down safely.
+The **RESET** pin can reset the module, but for this project, we won’t use it (you can leave it unconnected).

>[!WARNING]
>One more thing: when transmitting, the module can draw up to **140 milliamps**. That’s a bit high for the Arduino’s built-in regulator, but since our demo is simple, we’ll power it directly from the Arduino’s 3.3V pin. For bigger projects, though, use an external 3.3V power source.

### ❤️SPONSOR

I want to give a huge thank you to [Reyax](https://reyax.com/), who kindly provided the [RYLR993 Lite modules](https://reyax.com/products/RYLR993_Lite) for this tutorial.

If you haven’t heard of them yet, Reyax is a global provider of IoT communication solutions. They’ve been around for over a decade and offer a full lineup of products: LoRa, Bluetooth, Wi-Fi, Cellular, GNSS, and more.

Their modules are known for being high quality, easy to use, and affordable, which makes them perfect for DIY makers, educators, and even professionals.

With distributors in every continent, it’s really easy to get your hands on their products. So if you’re working on any kind of IoT project that requires wireless communication, definitely check out Reyax.

Thanks again to Reyax for sponsoring this project and helping make STEM education accessible to everyone.

### 🧭WHAT'S NEXT

Now that you’ve seen how to make two LoRa modules communicate, you can expand this idea to:
+Build a remote weather station
+Create a long-range sensor network
+ Make your own wireless control system

The possibilities are endless!

If you found this useful, consider starring ⭐ this repository and subscribing to my [YouTube channel](https://www.youtube.com/@lucasfernandochannel) for more practical Arduino and LoRa projects.
