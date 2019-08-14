/**The MIT License (MIT)
Copyright (c) 2015 by Daniel Eichhorn
Permission is hereby granted, free of uint8_tge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
See more at http://blog.squix.ch
*/

// Weather Icons are from http://www.alessioatzeni.com/meteocons/

#define active_width 8
#define active_height 8
const uint8_t  active_bits[] PROGMEM = {
   0x00, 0x18, 0x3c, 0x7e, 0x7e, 0x3c, 0x18, 0x00 };

#define inactive_width 8
#define inactive_height 8
const uint8_t  inactive_bits[] PROGMEM = {
   0x00, 0x18, 0x24, 0x42, 0x42, 0x24, 0x18, 0x00 };
   
const uint8_t  xbmtemp[] PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x9e, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
   0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x66, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x66, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66,
   0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x0e, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x67, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf3,
   0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfb, 0x1d, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xf9, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf9,
   0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xfb, 0x1d, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xf3, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
   0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9f, 0x0f, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#define WiFi_Logo_width 60
#define WiFi_Logo_height 36
const uint8_t WiFi_Logo_bits[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xE0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 
  0xFF, 0x03, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 
  0x00, 0xFF, 0xFF, 0xFF, 0x07, 0xC0, 0x83, 0x01, 0x80, 0xFF, 0xFF, 0xFF, 
  0x01, 0x00, 0x07, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0C, 0x00, 
  0xC0, 0xFF, 0xFF, 0x7C, 0x00, 0x60, 0x0C, 0x00, 0xC0, 0x31, 0x46, 0x7C, 
  0xFC, 0x77, 0x08, 0x00, 0xE0, 0x23, 0xC6, 0x3C, 0xFC, 0x67, 0x18, 0x00, 
  0xE0, 0x23, 0xE4, 0x3F, 0x1C, 0x00, 0x18, 0x00, 0xE0, 0x23, 0x60, 0x3C, 
  0x1C, 0x70, 0x18, 0x00, 0xE0, 0x03, 0x60, 0x3C, 0x1C, 0x70, 0x18, 0x00, 
  0xE0, 0x07, 0x60, 0x3C, 0xFC, 0x73, 0x18, 0x00, 0xE0, 0x87, 0x70, 0x3C, 
  0xFC, 0x73, 0x18, 0x00, 0xE0, 0x87, 0x70, 0x3C, 0x1C, 0x70, 0x18, 0x00, 
  0xE0, 0x87, 0x70, 0x3C, 0x1C, 0x70, 0x18, 0x00, 0xE0, 0x8F, 0x71, 0x3C, 
  0x1C, 0x70, 0x18, 0x00, 0xC0, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x08, 0x00, 
  0xC0, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x0C, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 
  0x00, 0x00, 0x06, 0x00, 0x80, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x07, 0x00, 
  0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 
  0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x1F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  };   
#define clear_day_width 50
#define clear_day_height 50
const uint8_t clear_day_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x18, 
  0x00, 0x03, 0x60, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x00, 
  0x00, 0x7C, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x78, 
  0x00, 0x00, 0x00, 0xF0, 0xC0, 0x0F, 0x38, 0x00, 0x00, 0x00, 0x60, 0xF0, 
  0x7F, 0x18, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7E, 0xF8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 0x03, 0x00, 
  0x00, 0x00, 0x00, 0x0F, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x80, 0x07, 0x80, 
  0x07, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x07, 0x00, 0x00, 0x00, 0xC0, 
  0x03, 0x00, 0x0F, 0x00, 0x00, 0xC0, 0xC3, 0x01, 0x00, 0x0E, 0x0F, 0x00, 
  0xE0, 0xC7, 0x01, 0x00, 0x8E, 0x1F, 0x00, 0xE0, 0xC7, 0x01, 0x00, 0x8E, 
  0x1F, 0x00, 0xC0, 0xC3, 0x01, 0x00, 0x0E, 0x0F, 0x00, 0x00, 0xC0, 0x03, 
  0x00, 0x0F, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x0F, 0x00, 0x00, 0x00, 
  0x80, 0x07, 0x80, 0x07, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x80, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x1F, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x7E, 0xF8, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xC0, 0x1F, 0x38, 0x00, 0x00, 
  0x00, 0xF8, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0xF8, 
  0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x03, 0x60, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, };
#define clear_night_width 50
#define clear_night_height 50
const uint8_t clear_night_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7B, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x71, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 
  0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xE0, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xC0, 0x03, 0x00, 
  0x00, 0x00, 0x00, 0xE0, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 
  0xFF, 0x1F, 0x00, 0x00, 0x00, 0xE0, 0x01, 0xFE, 0x1F, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0xC0, 0x03, 0xC0, 0x0F, 0x00, 
  0x00, 0x00, 0x80, 0x07, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x80, 
  0x07, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0xFC, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, };
#define cloudy_width 50
#define cloudy_height 50
const uint8_t cloudy_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xF8, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x80, 0x0F, 0xC0, 0x0F, 
  0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xE0, 0x01, 
  0x00, 0x3E, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x00, 0xFC, 0x07, 0x00, 0xE0, 
  0x7F, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0xF0, 0x7F, 0x00, 0x00, 0xF0, 0x7F, 
  0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x3C, 0x00, 0x00, 0x00, 
  0x00, 0xF0, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x0E, 0x00, 
  0x00, 0x00, 0x00, 0xC0, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x0F, 
  0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xC0, 
  0x01, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x3C, 0x00, 0x00, 0x00, 
  0x00, 0xF0, 0x00, 0x7C, 0x80, 0x00, 0x00, 0x0C, 0xF8, 0x00, 0xF8, 0xFF, 
  0x01, 0x00, 0xFE, 0x7F, 0x00, 0xE0, 0xFF, 0x03, 0x00, 0xFF, 0x3F, 0x00, 
  0xC0, 0xFF, 0x0F, 0xC0, 0xFF, 0x0F, 0x00, 0x00, 0x1E, 0xFF, 0xFF, 0xE7, 
  0x01, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xF8, 
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, };
#define fog_width 50
#define fog_height 50
const uint8_t fog_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF8, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 
  0x01, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xFC, 0xFF, 
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 
  0xFF, 0x01, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 
  0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xFC, 0xFF, 
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 
  0xFF, 0x01, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xF8, 
  0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, };
#define partly_cloudy_day_width 50
#define partly_cloudy_day_height 50
const uint8_t partly_cloudy_day_bits[] PROGMEM= {
  0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x07, 0x00, 
  0x00, 0xC0, 0x03, 0x00, 0x80, 0x07, 0x00, 0x00, 0xC0, 0x07, 0x00, 0xC0, 
  0x03, 0x00, 0x00, 0x80, 0x07, 0x3C, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x03, 
  0xFF, 0xC1, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x07, 0x00, 0x00, 0x00, 
  0x00, 0xE0, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x1F, 0x00, 
  0x00, 0x00, 0x00, 0x78, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 
  0x3C, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 
  0x1C, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x70, 0x00, 0x00, 
  0x00, 0x3F, 0x1E, 0xF0, 0x7F, 0xF8, 0x00, 0x00, 0x3F, 0x1E, 0xFC, 0xFF, 
  0xFC, 0x01, 0x00, 0x3F, 0x1E, 0xFF, 0xFF, 0xFB, 0x00, 0x00, 0x00, 0x9C, 
  0x3F, 0xF0, 0x07, 0x00, 0x00, 0x00, 0xDC, 0x07, 0x80, 0x0F, 0x00, 0x00, 
  0x00, 0xFC, 0x03, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFC, 
  0x03, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0xF0, 0x7F, 0x00, 
  0x00, 0xF8, 0x3F, 0x00, 0xF8, 0x21, 0x00, 0x00, 0x10, 0x7E, 0x00, 0x7C, 
  0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0xE0, 
  0x01, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x0E, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 
  0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x0E, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0x03, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x3E, 
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xF8, 
  0x00, 0xF8, 0xE1, 0x01, 0x00, 0x1E, 0x7E, 0x00, 0xF0, 0xFF, 0x03, 0x00, 
  0xFF, 0x3F, 0x00, 0xC0, 0xFF, 0x07, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xBF, 
  0x3F, 0xF0, 0xF7, 0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 
  0x00, 0x00, };
#define partly_cloudy_night_width 50
#define partly_cloudy_night_height 50
const uint8_t partly_cloudy_night_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x01, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFC, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xE7, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE7, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0xC3, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC3, 0x03, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0xC3, 0x03, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0x83, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x03, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0xFE, 0x7F, 
  0x00, 0x00, 0x00, 0xF0, 0x3F, 0xF8, 0x7F, 0x00, 0x00, 0x00, 0xFC, 0xFF, 
  0xE0, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x3F, 0x00, 0x00, 0x80, 
  0x3F, 0xE0, 0x07, 0x3E, 0x00, 0x00, 0xC0, 0x07, 0x80, 0x0F, 0x1F, 0x00, 
  0x00, 0xE0, 0x03, 0x00, 0xDF, 0x0F, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFC, 
  0x07, 0x00, 0xE0, 0xFF, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0xF0, 0x7F, 0x00, 
  0x00, 0xF8, 0x3F, 0x00, 0xF8, 0x21, 0x00, 0x00, 0x10, 0x7E, 0x00, 0x7C, 
  0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0xE0, 
  0x01, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x0E, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 
  0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x0E, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0x03, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x3E, 
  0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xF8, 
  0x00, 0xF8, 0xE1, 0x01, 0x00, 0x1E, 0x7E, 0x00, 0xF0, 0xFF, 0x03, 0x00, 
  0xFF, 0x3F, 0x00, 0xC0, 0xFF, 0x07, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xBF, 
  0x3F, 0xF0, 0xF7, 0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 
  0x00, 0x00, };
#define rain_width 50
#define rain_height 50
const uint8_t rain_bits[] PROGMEM= {
  0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x80, 0x3F, 
  0xF0, 0x07, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0xC0, 0x0F, 0x00, 0x00, 0x00, 
  0xE0, 0x03, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0xFE, 0x03, 
  0x00, 0xC0, 0xFF, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0xF0, 0x7F, 0x00, 0x00, 
  0xF8, 0x3F, 0x00, 0xF8, 0x3B, 0x00, 0x00, 0x70, 0x7F, 0x00, 0x7C, 0x00, 
  0x00, 0x00, 0x00, 0xF8, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x0E, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x03, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x1E, 0x00, 
  0x00, 0x00, 0x00, 0xE0, 0x01, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0xF8, 0xC0, 0x00, 0x00, 0x0C, 0x7C, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xFE, 
  0x3F, 0x00, 0xE0, 0xFF, 0x07, 0x80, 0xFF, 0x1F, 0x00, 0x80, 0xFF, 0x1F, 
  0xE0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x7C, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x02, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF8, 0x00, 
  0x00, 0x00, 0x00, 0x80, 0x07, 0xFC, 0x01, 0x00, 0x00, 0x00, 0x80, 0x07, 
  0xFC, 0x01, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x0F, 0x70, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 
  0x00, 0x00, };
#define sleet_width 50
#define sleet_height 50
const uint8_t sleet_bits[] PROGMEM= {
  0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x80, 0x3F, 
  0xF0, 0x07, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x80, 0x0F, 0x00, 0x00, 0x00, 
  0xE0, 0x03, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0xFE, 0x03, 
  0x00, 0xC0, 0xFF, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0xF0, 0x7F, 0x00, 0x00, 
  0xF8, 0x3F, 0x00, 0xF8, 0x3B, 0x00, 0x00, 0x70, 0x7F, 0x00, 0x7C, 0x00, 
  0x00, 0x00, 0x00, 0xF8, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x0E, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x03, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x1E, 0x00, 
  0x00, 0x00, 0x00, 0xE0, 0x01, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0xF8, 0xC0, 0x00, 0x00, 0x0C, 0x7C, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xFE, 
  0x3F, 0x00, 0xE0, 0xFF, 0x07, 0x80, 0xFF, 0x1F, 0x00, 0x80, 0xFF, 0x1F, 
  0xE0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x80, 0x03, 0x00, 0x80, 0x0F, 0x00, 0x00, 
  0xC0, 0x07, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0xC0, 0x1F, 
  0x00, 0x03, 0xE0, 0x0F, 0x00, 0xC0, 0x0F, 0x80, 0x07, 0xC0, 0x0F, 0x00, 
  0x80, 0x0F, 0xC0, 0x0F, 0xC0, 0x07, 0x00, 0x00, 0x02, 0xC0, 0x0F, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 
  0x0F, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xE0, 
  0x07, 0x80, 0x3F, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x80, 0x3F, 0x00, 0x00, 
  0x00, 0xE0, 0x03, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x0E, 
  0x00, 0x00, };
#define snow_width 50
#define snow_height 50
const uint8_t snow_bits[] PROGMEM= {
  0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x80, 0x3F, 
  0xF0, 0x07, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0xC0, 0x0F, 0x00, 0x00, 0x00, 
  0xE0, 0x03, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0xFE, 0x03, 
  0x00, 0xC0, 0xFF, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0xF0, 0x7F, 0x00, 0x00, 
  0xF8, 0x3F, 0x00, 0xF8, 0x3F, 0x00, 0x00, 0x70, 0x7F, 0x00, 0x7C, 0x00, 
  0x00, 0x00, 0x00, 0xF8, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0x1E, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x0E, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x07, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 
  0x03, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x0F, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x03, 0x1E, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x1E, 0x00, 
  0x00, 0x00, 0x00, 0xE0, 0x01, 0x3C, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 
  0xF8, 0xC0, 0x00, 0x00, 0x0C, 0x7C, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xFE, 
  0x3F, 0x00, 0xE0, 0xFF, 0x07, 0x80, 0xFF, 0x1F, 0x00, 0x80, 0xFF, 0x1F, 
  0xE0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xF0, 0x0B, 0x00, 0x03, 0x00, 0x00, 0x00, 0xE0, 0x1F, 
  0x80, 0x07, 0x00, 0x03, 0x00, 0x70, 0x0E, 0x80, 0x07, 0x00, 0x37, 0x00, 
  0xF8, 0x07, 0x8C, 0xC7, 0x00, 0x3F, 0x00, 0xF8, 0x07, 0xFE, 0xFF, 0xE1, 
  0x1F, 0x00, 0xC0, 0x0F, 0xFE, 0xFF, 0xC1, 0x39, 0x00, 0xC0, 0x00, 0xFC, 
  0xFF, 0x80, 0x7B, 0x00, 0x00, 0x00, 0xF0, 0x3C, 0x80, 0x7F, 0x00, 0x00, 
  0x00, 0x70, 0x38, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0xF0, 0x7C, 0x80, 0x0C, 
  0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFE, 0xFF, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 
  0x8C, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 
  0x00, 0x00, };
#define sunset_width 50
#define sunset_height 50
const uint8_t sunset_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x03, 0xE0, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 
  0x78, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x7C, 0x00, 
  0x00, 0x00, 0x60, 0xE0, 0x1F, 0x38, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x3E, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xC0, 0x03, 0x00, 0x00, 
  0x00, 0x80, 0x07, 0x80, 0x07, 0x00, 0x00, 0x00, 0x80, 0x07, 0x80, 0x07, 
  0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x0F, 0x00, 0x00, 0x00, 0xC0, 0x03, 
  0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x80, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 
  0x0F, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 
  0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFE, 
  0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, };
#define wind_width 50
#define wind_height 50
const uint8_t wind_bits[] PROGMEM= {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 
  0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 
  0x00, 0xC0, 0xFF, 0xFF, 0x7F, 0x00, 0x1F, 0x00, 0xC0, 0xFF, 0xFF, 0x3F, 
  0x80, 0x3F, 0x00, 0x80, 0xFF, 0xFF, 0x1F, 0xC0, 0x3F, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 
  0x3F, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0xC0, 0xFF, 0xFF, 
  0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 
  0x0F, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, };
