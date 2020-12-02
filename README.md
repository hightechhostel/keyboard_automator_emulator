# keyboard_automator_emulator
A text viewer app that can automatically send lines of text out through the serial port of one computer to an Arduino Teensy to another another computer via USB.  This means you don't have to type long complicated commands if someone has already typed this out for you.   

More documentation to follow (especially upon request). 

A video explanation of this project is located at https://youtu.be/B_2JoDEWHWE

## USAGE
./s2s /path/to/text/file/example.md /dev/cu.usbserial-FTGNRR7Z

cu.usbserial-FTGNRR7Z refers to the serial port that has been exposed in your devices directory when the Aruduino is plugged in.  Your port will vary from what's shown above.  
