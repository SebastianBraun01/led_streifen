# Netzwerk LED-Beleuchtung
Ich dokumentiere hier mein Projekt für eine voll steuerbare Beleuchtung für einen Party-Raum. Ich möchte mehrere LED-Streifen im Raum verteilen und alle sollten synchron verschiedene Lichtmuster abspielen können. Die Steuerungen der LED-Streifen sollten über WLAN kommunizieren und sich zentral steuern lassen.

## Hardware
Als Beleuchtung verwende ich die Adafruit Neopixel (WS2812B). Mit diesen lassen sich durch den Datenpin komplexe Farbmuster anzeigen und sind auch in der Stromversorgung sehr simpel.

Für die Steuerung werden mehrere Arduinio Nano 33 IOT installiert. Diese sind sehr kompakt und sind mit WLAN und Bluetooth ausgestattet. 

## Software
Neben den üblichen Bibliotheken für die Neopixel, verwende ich die Blynk Bibliothek, damit ich mehrere Arduinos gleichzeitig steuern kann und dies über eine passende App.
