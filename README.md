# wireless-LED-ESP32

These files for demonstrating a wireless LED On and Off example, with an ESP32 and your computer. 

1: Open the ligh_example_esp32.ino file in the Arduino IDE and upload it to your esp32 or microcontroller of your choice. (Keep in mind you might have to switch what pin you are using for your LED. With this example, we are using GPIO pin 2, which is has a built in LED attached to it on my ESP32. If this is the same for yours, then you don't have to worry about changing it.)

2: Power the ESP32. (You can either do this with a battery or you can just leave it plugged into your computer.)

3: Connect to the ESP32s WiFi. (With this setup, we are using the ESP32 in Acess Point mode, or AP mode, which is why we have to connect to it, in order for us to communicate with it.)

4: Run the light_example.py file either in the VS code terminal or your computers terminal. (This is how we are going to interact with the ESP32, and turn On and Off the LED wirelessly.

5: Enter On or Off. (As you can assume, by entering On in the terminal, the LED on the ESP32 should turn on, and you should receive a message saying, "Light was turned On!". This is the same as if you enter Off, however, the LED should turn OFF and and you should receive a message saying, "Light was turned OFF!".

6: To quit the program, just enter q and the python program should quit running.

** Libraries to Install ** 

- For the python file, you will need to install the requests library: pip3 install requests
- For the Arduino IDE file, you will need to install WiFi.h and WebServer.h (Which I think already come installed with the ESP32 Arduino Core)

