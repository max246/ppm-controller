#include "PPMEncoder.h"

#define OUTPUT_PIN 10

int ppm[] = {1500, 1500, 1500, 1500};
int buffer_index = 0;
byte buffer[10] = {0x00, 0x00, 0x00, 0x00};

int max_ppm = 2000;
int idle_ppm = 1500;
int min_ppm = 1000;
boolean do_parse = false;

void setup() {
  ppmEncoder.begin(OUTPUT_PIN, 8);
  Serial.begin(9600);  
}

void loop() {
  send_ppm();
}

void parse_buffer() {
  if (buffer_index >= 4) {
    int x = buffer_index - 4;
    for (int i = 0; i < 4; i++) {
     if (i == 0) { //speed
           max_ppm = 1600;
           min_ppm = 1300;
      } else {
            max_ppm = 2000;
            min_ppm = 1000;
      }
      
      if (buffer[x] == 0x00) ppm[i] = max_ppm;
      else if (buffer[x] == 0x01) ppm[i] = idle_ppm;
      else ppm[i] = min_ppm;
      x++;
    }
  }
}

void send_ppm() {
  for (int i = 0; i < 4; i++) {
    // Serial.println(ppm[i]);
    ppmEncoder.setChannel(i, ppm[i]);
    delay(1);
    ppmEncoder.setChannel(i, ppm[i]);
    delay(1);
  }
}

void serialEvent() {
  byte c = Serial.read();
  if (c == 0x0c) {
    parse_buffer();
    buffer_index = 0;
  }
  else {
    if (buffer_index < 10) {
      buffer[buffer_index] = c;
      buffer_index++;
    } else {
      buffer_index = 0;
    }
  }
}
