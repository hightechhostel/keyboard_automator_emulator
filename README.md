# keyboard_automator_emulator
This project allows you to use the terminal of one computer (tested with Mac) as a keyboard for another computer. In addition, it will read text or markdown files. On the leader (keyboard) computer you can use your arrow keys to scroll down through the text and simply hit enter to send the text from that line over to the other computer.  This saves you from having to type something that has already been typed by others.  

It's particularly useful when you are reading instructions on one computer and need to execute commands on another computer.  This is particularly useful for someone like me who tends to make a lot of typos when typing complex bash commands.  See this video for an overview of the project: https://youtu.be/B_2JoDEWHWE

This project consists of two parts.  A USB to USB convertor cable that connects two computers together.  And a C program that reads a text or markdown file and sends text out the serial port through the USB to USB convertor cable to the computer you want to control.     

First, let's look at the USB to USB convertor cable.  Here's what mine looks like: 

![Completed USB to USB convertor cable](./images/USB2USB_cable.jpg)

Here's what you will need to build your cable (affiliate links):  

[USB to TTL Serial 3.3V UART Converter Cable with FTDI Chip!](https://www.amazon.com/gp/product/B06ZYPLFNB/ref=as_li_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=B06ZYPLFNB&linkCode=as2&tag=hightechhoste-20&linkId=fa771f621f446405b7e19dc82cddf165)

[Teensy LC USB Development Board Without Pins](https://www.amazon.com/gp/product/B01BMRTZGE/ref=as_li_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=B01BMRTZGE&linkCode=as2&tag=hightechhoste-20&linkId=f3c548810fa16a25ee8ba9ae16105a44)

Micro USB Cable - You probably have a few of these laying around but it needs to be able to pass data.  Some micro USB cables are only good for charging your devices.   If you can't program your Teensy, then you probably have a bad cable. 

A plastic box to put it all in.  

####Hardware
Here's the schematic to hook everything up: 

![Schematic](./images/USB2USB_cable-schematic.png)

To program the Teensy you will need Teensyduino. The normal Arduino IDE will not work.  Plug the the USB A side of the Micro USB cable into your computer and plug the micro USB side into your TeensyLC.  Load the keyboard_automator_emulator.ino in this repository into Teensyduino, go to Tools > Board: Arduino Yun > Teensyduino > Teensyduino LC

![Teensyduino Menu Option](./images/Teensyduino-menu.png)

Go to Sketch > Include Library > Keyboard

![Teensyduino Include Library](./images/Include-Keyboard.png)

Click verify, then Upload.  Teensyduino should prompt you to push the button on the TeensyLC.  

If everything worked your hardware is ready to go.  

####Software

Open your terminal and compile your source code with this command: 

`gcc s2s.c -o s2s`

Then run `ls /dev` to see the ports you have active on your computer.  Make note of what you see.  

Plug in the USB to TTL Serial side of your USB to USB convertor cable to your Mac.  

run `ls /dev` again.  You should see a new port.  Make note of this port.

For example, after connect the ftd232 device to my mac a new tty device appears in the /dev/.
On my machine it's `/dev/cu.usbserial-FTGNRR7Z` Your's will be different. This is the serial port than you will use use to communicate with the TeensyLC.

Usage
./s2s text_file serial_port

Example:
  ./s2s /Users/darrenoverby/MySoftwareBuildInstructions/build.md /dev/cu.usbserial-FTGNRR7Z 

The Text Viewer app will load.  Use the arrow keys to scroll up and down through the lines of text.  If you want to send a command, move your cursor to that row and just hit enter.  

If you want to type something else, just start typing.  Your typed text will be sent to the other machine.  

Here's a cheatsheet of commands: 
Up / Down keys : Move the cursor Up / Down
Enter : Sends the current line
CTRL + j : Sends the JUST the current line without new line character
CTRL + s : Sends a Super Key press (useful for Linux)
CTRL + c : Sends a CTRL+c press
ALT + Arrows : Sends an Arrow key press (useful for navigating the Bash history on the other machine)
Any other "normal key" : Sends text just like a keyboard
CTRL + q : Exit 

More documentation available upon request. 

Thanks to my friend Akos Kristo for helping with the programming.   
