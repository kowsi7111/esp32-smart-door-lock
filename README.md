🔐 ESP32 Smart Door Lock with Keypad and Blynk App

    This project implements a Smart Door Lock System using the ESP32, a 4x4 matrix keypad, a servo motor, and the Blynk IoT platform. It allows users to unlock the door either by entering a passcode on the keypad or by using a button on the Blynk mobile app. This hybrid system ensures secure and flexible access control for modern smart homes.

🔧 Features
      🔓 Unlock door via passcode (e.g., 1234) using the 4x4 matrix keypad
      
      📲 Remote unlock through Blynk app with a virtual button
      
      🔁 Auto-lock the door after a preset duration (5 seconds)
      
      🔒 Stores and compares entered codes securely
      
      📡 Wi-Fi connected using ESP32 and Blynk Cloud
      
      📘 Real-time status updates in Blynk app (success/failure messages)

📱 Blynk Setup
        Download the Blynk IoT app from:
        
        Android - Play Store
        
        iOS - App Store
        
        Create a new template and get the following credentials:
        
        BLYNK_TEMPLATE_ID
        
        BLYNK_TEMPLATE_NAME
        
        BLYNK_AUTH_TOKEN
        
        Add a Button widget to the Blynk app:
        
        Set to Virtual Pin V0
        
        Mode: Switch
        
        Add a Label widget on Virtual Pin V1 to display door status

        📘 Reference: Blynk Documentation https://docs.blynk.io/en
        

🧠 Hardware Components
          Component	Quantity
          ESP32 Dev Board	1
          4x4 Matrix Keypad	1
          SG90/Servo Motor	1
          Breadboard & Wires	Several
          Power Source (5V)	1

          
🧪 How It Works
      The system constantly monitors for:
      
      Keypad input
      
      Blynk app commands
      
      If the correct code is entered via the keypad, the door unlocks.
      
      If the Blynk app button (V0) is pressed, the door also unlocks.
      
      The servo motor rotates to 90° to open the lock and returns to 0° after 5 seconds to re-lock.
      
      A feedback message is sent to the Blynk app (V1) after each attempt.
