# led-screen
Mini project using Arduino Nano Every and a 16 x 16 LED pixel screen.

## Setting Up
Install the requirements in  conda environment:

> conda create --name led
> conda activate led
> pip install requirements.txt

Install additionally the Arduino IDE from https://www.arduino.cc/en/software.

## Displaying Custom Image
1. Design your custom image using https://www.pixilart.com/draw and export as PNG.
2. Run `img_to_bitmap.py` script to generate image bitmap array, and copy the printed result from terminal.
> python scripts/img_to_bitmap.py --img=<path-to-image>
3. Paste image array into file `src/draw_bitmap/draw_bitmap.ino` variable `img_array`.
4. Upload `src/draw_bitmap/draw_bitmap.ino` to Arduino Nano Every using Arduino IDE.

## Rainbow
Simply upload `src/rainbow/rainbow.ino` to Arduino Nano Every using Arduino IDE.