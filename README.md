# keyboard_automator_emulator
This project allows you to use the terminal of one computer (tested with Mac) as a keyboard for another computer. In addition, it will read text or markdown files. On the leader (keyboard) computer you can use your arrow keys to scroll down through the text and simply hit enter to send the text from that line over to the other computer.  This saves you from having to type something that has already been typed by others.  

It's particularly useful when you are reading instructions on one computer and need to execute commands on another computer.  This is particularly useful for someone like me who tends to make a lot of typos when typing complex bash commands.  See this video for an overview of the project: https://youtu.be/B_2JoDEWHWE

This project consists of two parts.  A USB to USB convertor cable that connects two computers together.  And a C program that reads a text or markdown file and sends text out the serial port through the USB to USB convertor cable to the computer you want to control.     

First, let's look at the USB to USB convertor cable.  Here's what mine looks like: 

![Completed USB to USB convertor cable](./USB2USB_cable.png)
itext viewer app that can automatically send lines of text out through the serial port of one computer to an Arduino Teensy to another another computer via USB.  This means you don't have to type long complicated commands if someone has already typed this out for you.   

More documentation to follow (especially upon request). 

A video explanation of this project is located at https://youtu.be/B_2JoDEWHWE

## USAGE
./s2s /path/to/text/file/example.md /dev/cu.usbserial-FTGNRR7Z

cu.usbserial-FTGNRR7Z refers to the serial port that has been exposed in your devices directory when the Aruduino is plugged in.  Your port will vary from what's shown above.  

Thanks to my friend Akos for helping with the programming.   
