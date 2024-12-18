#include <Adafruit_NeoPixel.h>

#define LED_PIN 21 // Pin to use to send signals to WS2812B
#define LED_COUNT 256 // Number of WS2812B LEDs attached to the Arduino
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); // Setting up the NeoPixel library

// Initialise RGB image array of size 16 * 16 * 3 (paste array from `img_to_bitmap.py` script print)
int img_array[768] = {0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 255, 255, 255, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 126, 0, 255, 255, 255, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 255, 255, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 255, 255, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 126, 0, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 255, 126, 0, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 183, 239, 0, 0, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 126, 0, 255, 126, 0, 255, 126, 0, 255, 126, 0, 0, 0, 0, 0, 183, 239, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239, 0, 183, 239};
int r, g, b;
int count;

void setup() {
  strip.begin();           // Initialize NeoPixel object
  strip.setBrightness(5);  // Brightness (max = 255)
  strip.show();            // Initialize all pixels to 'off'
}

void loop() {
  draw_bitmap();
}

// Function to iterate over image array and set RGB pixel colour
void draw_bitmap() {
  count = 0;
  for(int pixel_index = 0; pixel_index < 256; pixel_index++) {
    r = img_array[count];
    count ++;
    g = img_array[count];
    count ++;
    b = img_array[count];
    count ++;
    strip.setPixelColor(pixel_index, r, g, b);
  }
  strip.show(); // Update strip with new contents
  delay(100000);
}