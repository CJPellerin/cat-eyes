/// @file    FirstLight.ino
/// @brief   Animate a white dot moving along a strip of LEDs
/// @example FirstLight.ino
#include <FastLED.h>

#define NUM_LEDS 186
#define DATA_PIN 5

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the ledsand tells the controller about them
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);

  FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(55);
}

#define RING_1_S 92
#define RING_1_E 93

#define RING_2_S 84
#define RING_2_E 92

#define RING_3_S 72
#define RING_3_E 84

#define RING_4_S 56
#define RING_4_E 72

#define RING_5_S 32
#define RING_5_E 56

#define RING_6_S 0
#define RING_6_E 32


#define RING2_1_S 185
#define RING2_1_E 186

#define RING2_2_S 177  // 8
#define RING2_2_E 185

#define RING2_3_S 165  // 12
#define RING2_3_E 177

#define RING2_4_S 149  // 16
#define RING2_4_E 165

#define RING2_5_S 125  // 24
#define RING2_5_E 149

#define RING2_6_S 93  // 32
#define RING2_6_E 125

// This function runs over and over, and is where you do the magic to light
// your leds.

int getLoopStart(int idx) {
  if (idx == 1) {
    return RING_1_S;
  } else if (idx == 2) {
    return RING_2_S;
  } else if (idx == 3) {
    return RING_3_S;
  } else if (idx == 4) {
    return RING_4_S;
  } else if (idx == 5) {
    return RING_5_S;
  } else if (idx == 6) {
    return RING_6_S;
  }
}
int getLoopEnd(int idx) {
  if (idx == 1) {
    return RING_1_E;
  } else if (idx == 2) {
    return RING_2_E;
  } else if (idx == 3) {
    return RING_3_E;
  } else if (idx == 4) {
    return RING_4_E;
  } else if (idx == 5) {
    return RING_5_E;
  } else if (idx == 6) {
    return RING_6_E;
  }
}


int getLoopStart2(int idx) {
  if (idx == 1) {
    return RING2_1_S;
  } else if (idx == 2) {
    return RING2_2_S;
  } else if (idx == 3) {
    return RING2_3_S;
  } else if (idx == 4) {
    return RING2_4_S;
  } else if (idx == 5) {
    return RING2_5_S;
  } else if (idx == 6) {
    return RING2_6_S;
  }
}
int getLoopEnd2(int idx) {
  if (idx == 1) {
    return RING2_1_E;
  } else if (idx == 2) {
    return RING2_2_E;
  } else if (idx == 3) {
    return RING2_3_E;
  } else if (idx == 4) {
    return RING2_4_E;
  } else if (idx == 5) {
    return RING2_5_E;
  } else if (idx == 6) {
    return RING2_6_E;
  }
}
// -------------
// MasterLoop
void loop() {
  // rotateFullColors();
  // catEyes();
  //walkRings();  // Light up the rings one led at a time
  //lightRings();  // light the rings in-out with random rainbow and delays
  //lightFullColors();
  //regularEyes();
  googlyEyes();
  //lightRings();
}

// Light the (x) ring with this color index and delay
void lightLoop(int idx, byte colIdx, int delayTime) {
  int colorIndex = 0;
  for (int whiteLed = getLoopStart(idx); whiteLed < getLoopEnd(idx); whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = ColorFromPalette(RainbowColors_p, colorIndex, 150, LINEARBLEND);
    colorIndex += colIdx;
  }
  for (int whiteLed = getLoopStart2(idx); whiteLed < getLoopEnd2(idx); whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = ColorFromPalette(RainbowColors_p, colorIndex, 150, LINEARBLEND);
    colorIndex += colIdx;
  }
  // Show the leds (only one of which is set to white, from above)
  FastLED.show();
  // Wait a little bit
  delay(delayTime);
}

// Black the (x) ring with
void blackLoop(int idx) {
  for (int whiteLed = getLoopStart(idx); whiteLed < getLoopEnd(idx); whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = CRGB::Black;
  }
  for (int whiteLed = getLoopStart2(idx); whiteLed < getLoopEnd2(idx); whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = CRGB::Black;
  }
  // Show the leds (only one of which is set to white, from above)
  FastLED.show();
  // Wait a little bit
  delay(5);
  // Turn our current led back to black for the next loop around
  //  leds[whiteLed] = CRGB::Black;
  //}
}

void lightFullColors() {
  int delayRand = random(10, 100);
  int colorIndex = 0;
  for (int colIdx = 0; colIdx < 255; colIdx++) {
    for (int i = 0; i < 94; i++) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
      //colorIndex += 3;
      // Show the leds (only one of which is set to white, from above)
    }
    FastLED.show();
    // Wait a little bit
    delay(delayRand);
    // Turn our current led back to black for the next loop around
    // leds[whiteLed] = CRGB::Black;
  }
}

void loopDyn(int idx) {
  int colorIndex = 0;
  for (int whiteLed = getLoopStart(idx); whiteLed < getLoopEnd(idx); whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = ColorFromPalette(RainbowColors_p, colorIndex, 55, LINEARBLEND);
    colorIndex += 3;
    // Show the leds (only one of which is set to white, from above)
    FastLED.show();
    // Wait a little bit
    delay(1000);
    // Turn our current led back to black for the next loop around
    leds[whiteLed] = CRGB::Black;
  }
}

void runLightLoops() {
  for (int i = 6; i > 0; i--) {
    loopDyn(i);
  }

  for (int i = 1; i < 7; i++) {
    loopDyn(i);
  }
}
// Light the rings in solid color
void lightRings() {
  int delayTime = random(10, 300);
  byte colIdx = random(3, 10);
  for (int i = 6; i > 0; i--) {
    lightLoop(i, colIdx, delayTime);
    blackLoop(i);
  }

  for (int i = 1; i < 7; i++) {
    lightLoop(i, colIdx, delayTime);
    blackLoop(i);
  }
}
// Light one ring at a time alternating eyes
void theaterLoop(int idx) {
  int colorIndex = 0;
  CRGBPalette16 currentPalette = RainbowColors_p;
  TBlendType currentBlending = LINEARBLEND;  //NOBLEND;

  for (int i = getLoopStart(idx); i < getLoopEnd(idx); i = i + 1) {
    // Turn our current led on to white, then show the leds
    leds[i] = ColorFromPalette(currentPalette, colorIndex, 88, currentBlending);
    colorIndex += 2;
    leds[i + 1] = CRGB::Black;
    leds[i + 2] = CRGB::Black;
    FastLED.show();
    // Wait a little bit
    delay(75);
  }

  for (int i = getLoopStart2(idx); i < getLoopEnd2(idx); i = i + 1) {
    // Turn our current led on to white, then show the leds
    leds[i] = ColorFromPalette(currentPalette, colorIndex, 88, currentBlending);
    colorIndex += 2;
    leds[i + 1] = CRGB::Black;
    leds[i + 2] = CRGB::Black;
    FastLED.show();
    // Wait a little bit
    delay(75);
  }

  // Show the leds (only one of which is set to white, from above)
  //FastLED.show();
  // Wait a little bit
  // delay(175);
  // Turn our current led back to black for the next loop around
  //  leds[whiteLed] = CRGB::Black;
  //}
}



// Light one ring at a time alternating eyes
void theaterLoopSim(int idx, byte colIdx, int delayTime) {
  int colorIndex = 0;
  CRGBPalette16 currentPalette = RainbowColors_p;
  TBlendType currentBlending = LINEARBLEND;  //NOBLEND;

  for (int i = getLoopStart(idx); i < getLoopEnd(idx); i = i + 1) {
    // Turn our current led on to white, then show the leds
    leds[i] = ColorFromPalette(currentPalette, colorIndex, 88, currentBlending);
    leds[i + 93] = ColorFromPalette(currentPalette, colorIndex, 88, currentBlending);
    colorIndex += colIdx;
    //leds[i - 1] = CRGB::Black;
    //leds[i + 2] = CRGB::Black;
    FastLED.show();
    // Wait a little bit
    delay(delayTime);
  }
}

// Light one ring at a time alternating eyes
void theaterLoopSimBlack(int idx, int delayTime) {
  int colorIndex = 0;
  CRGBPalette16 currentPalette = RainbowColors_p;
  TBlendType currentBlending = LINEARBLEND;  //NOBLEND;

  for (int i = getLoopStart(idx); i < getLoopEnd(idx); i = i + 1) {
    // Turn our current led on to white, then show the leds
    leds[i] = CRGB::Black;
    leds[i + 93] = CRGB::Black;
    colorIndex += 2;
    FastLED.show();
    // Wait a little bit
    delay(delayTime);
  }
}
void walkRings() {
  int delayTime = random(10, 300);
  byte colIdx = random(3, 10);
  for (int i = 6; i > 0; i--) {
    //lightLoop(i, colIdx, delayTime);
    theaterLoopSim(i, colIdx, delayTime);
  }

  for (int i = 1; i < 7; i++) {
    //lightLoop(i,colIdx, delayTime);
    theaterLoopSimBlack(i, delayTime);
  }
}

void theaterLoopX(int idx) {
  int colorIndex = 0;
  CRGBPalette16 currentPalette = RainbowColors_p;
  TBlendType currentBlending = NOBLEND;
  //for (int clrIdx = 0; clrIdx < 255; clrIdx = clrIdx + 1) {
  for (int i = getLoopStart(idx); i < getLoopEnd(idx); i = i + 1) {
    // Turn our current led on to white, then show the leds
    leds[i] = ColorFromPalette(currentPalette, random(2, 8), 88, currentBlending);
    colorIndex += 2;
    //leds[i + 1] = CRGB::Black;
    //leds[i + 2] = CRGB::Black;
    FastLED.show();
    // Wait a little bit
    delay(10);
  }
  for (int i = getLoopStart2(idx); i < getLoopEnd2(idx); i = i + 1) {
    // Turn our current led on to white, then show the leds
    leds[i] = ColorFromPalette(currentPalette, random(2, 8), 88, currentBlending);
    colorIndex += 2;
    //leds[i + 1] = CRGB::Black;
    //leds[i + 2] = CRGB::Black;
    FastLED.show();
    // Wait a little bit
    delay(10);
  }
  //}
}
// Light up this loop a color, if show then show and delay
void lightLoopSolid(byte idx, CRGB color, boolean show, int dtme) {

  for (byte i = getLoopStart(idx); i < getLoopEnd(idx); i = i + 1) {
    leds[i] = color;
    leds[i + 93] = color;
  }
  if (show) {
    FastLED.show();
    // Wait a little bit
    delay(dtme);
  }
}

void googlyEyes() {
  FastLED.setBrightness(25);
  lightAllLoops();
  // Now black out a few for the pupils
  leds[1] = CRGB::Black;
  leds[2] = CRGB::Black;
  leds[32] = CRGB::Black;
  leds[33] = CRGB::Black;
  leds[34] = CRGB::Black;
  leds[56] = CRGB::Black;
  leds[57] = CRGB::Black;
  FastLED.show();
  // Wait a little bit
  delay(random(200, 400));

  lightAllLoops();
  // Now black out a few for the pupils
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[33] = CRGB::Black;
  leds[34] = CRGB::Black;
  leds[35] = CRGB::Black;
  leds[57] = CRGB::Black;
  leds[58] = CRGB::Black;
  FastLED.show();
  // Wait a little bit
  delay(random(200, 400));

  lightAllLoops();
  // Now black out a few for the pupils
  leds[3] = CRGB::Black;
  leds[4] = CRGB::Black;
  leds[34] = CRGB::Black;
  leds[35] = CRGB::Black;
  leds[36] = CRGB::Black;
  leds[58] = CRGB::Black;
  leds[59] = CRGB::Black;
  FastLED.show();
  // Wait a little bit
  delay(random(200, 400));

  lightAllLoops();
  // Now black out a few for the pupils
  leds[2] = CRGB::Black;
  leds[3] = CRGB::Black;
  leds[33] = CRGB::Black;
  leds[34] = CRGB::Black;
  leds[35] = CRGB::Black;
  leds[57] = CRGB::Black;
  leds[58] = CRGB::Black;
  FastLED.show();
  // Wait a little bit
  delay(random(200, 400));
}
void lightAllLoops() {
  // Light all of the loops white but don't show yet
  for (byte i = 6; i > 0; i--) {
    lightLoopSolid(i, CRGB::AntiqueWhite, false, 10);
  }
}

void regularEyes() {

  lightAllLoops();
  // Now black out a few for the pupils
  for (byte i = 84; i < 93; i++) {
    leds[i] = CRGB::Black;
    leds[i + 93] = CRGB::Black;
  }
  FastLED.show();
  // Wait a little bit
  delay(200);
}

void catEyes() {
  FastLED.setBrightness(25);
  lightAllLoops();
  // Now black out a few for the pupils
  const int eyeOne[] = { 0, 32, 56, 72, 84, 85, 86, 87, 88, 89, 90, 91, 73, 83, 77, 79, 88, 78, 64, 44, 16 };
  const int eyeTwo[] = { 93, 125, 149, 165, 177, 178, 179, 180, 181, 182, 183, 184, 166, 176, 170, 172, 181, 171, 157, 137, 109 };
  for (int element : eyeOne) {  // for each element in the array
    leds[element] = CRGB::Black;
  }
  for (int element : eyeTwo) {  // for each element in the array
    leds[element] = CRGB::Black;
  }

  const int ring3[] = { 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83 };
  for (int element : ring3) {  // for each element in the array
    leds[element] = CRGB::Aquamarine;
    leds[element + 93] = CRGB::Aquamarine;
  }


  /*
 // bottome up
  leds[0] = CRGB::Black;
  leds[32] = CRGB::Black;
  leds[56] = CRGB::Black;
  leds[72] = CRGB::Black;
  leds[84] = CRGB::Black;
  leds[85] = CRGB::Black;

  leds[86] = CRGB::Black;
  leds[87] = CRGB::Black;
  leds[88] = CRGB::Black;
  leds[89] = CRGB::Black;
  leds[90] = CRGB::Black;
  leds[91] = CRGB::Black;
  leds[92] = CRGB::Black;
  // middle out
  leds[73] = CRGB::Black;
  leds[83] = CRGB::Black;
  leds[77] = CRGB::Black;
  leds[79] = CRGB::Black;
  
  
  leds[88] = CRGB::Black;
  leds[78] = CRGB::Black;
  leds[64] = CRGB::Black;
  leds[44] = CRGB::Black;
  leds[16] = CRGB::Black;
*/
  FastLED.show();
  // Wait a little bit
  delay(200);
}

// spin colors on the even rings
void rotateEvenColors() {
  int delayRand = random(10, 100);
  int colorIndex = 0;
  for (int colIdx = 0; colIdx < 255; colIdx++) {
    for (byte i = getLoopStart(6); i < getLoopEnd(6); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
    }
    for (byte i = getLoopStart(4); i < getLoopEnd(4); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
    }
    for (byte i = getLoopStart(2); i < getLoopEnd(2); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
    }
    FastLED.show();
    // Wait a little bit
    delay(5);
  }
}


// Full color bland over all of the loops
void rotateFullColors() {
  int delayRand = random(10, 150);
  int colorIndex = 0;
  for (int colIdx = 0; colIdx < 255; colIdx++) {
    for (byte i = getLoopStart(6); i < getLoopEnd(6); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
    }
    for (byte i = getLoopStart(5); i < getLoopEnd(5); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 20, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
    }
    for (byte i = getLoopStart(4); i < getLoopEnd(4); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 15, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
    }
    for (byte i = getLoopStart(3); i < getLoopEnd(3); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 10, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
    }
    for (byte i = getLoopStart(2); i < getLoopEnd(2); i = i + 1) {
      // Turn our current led on to white, then show the leds
      leds[i] = ColorFromPalette(RainbowColors_p, colIdx - 5, 55, LINEARBLEND);
      leds[i + 93] = ColorFromPalette(RainbowColors_p, colIdx - 25, 55, LINEARBLEND);
    }
    // center dot
    leds[92] = ColorFromPalette(RainbowColors_p, colIdx, 55, LINEARBLEND);
    FastLED.show();
    // Wait a little bit
    delay(delayRand);
  }
}
