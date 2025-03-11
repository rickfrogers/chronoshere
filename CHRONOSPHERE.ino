/*
 * CHRONOSPHERE Digital/Analog Hybrid Effects Pedal
 * Version: 1.0.0
 * Created: 2025-03-10
 * Author: rickfrogers
 * 
 * Digital signal processing effects pedal with rotary speaker simulation,
 * delay, and reverb effects.
 */

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <EEPROM.h>
#include <Encoder.h>

// Pin Definitions
const int BYPASS_SWITCH = 2;
const int MODE_LEDS[] = {11, 12, 13, 14};
const int NUM_MODES = 4;
const int SPEED_POT = A1;
const int DEPTH_POT = A2;
const int TONE_POT = A3;
const int MIX_POT = A4;
const int ENC_CLK = 4;
const int ENC_DT = 5;

// Constants
const unsigned long DEBOUNCE_DELAY = 50;
const unsigned long EEPROM_SAVE_DELAY = 5000;

// Global Variables
bool bypassed = false;
int currentMode = 0;
long oldEncoderPosition = 0;
unsigned long lastEEPROMSave = 0;

// Create encoder object
Encoder modeEncoder(ENC_CLK, ENC_DT);

// Audio System Objects
AudioInputI2S            audioInput;
AudioOutputI2S           audioOutput;
AudioFilterBiquad        filter1;
AudioFilterBiquad        hornFilter;
AudioFilterBiquad        drumFilter;
AudioEffectDelay        delay1;
AudioEffectFreeverb     reverb1;
AudioSynthWaveformSine  modulator1;
AudioSynthWaveformSine  modulator2;
AudioAnalyzeFFT1024     fft;
AudioMixer4             mixer1;
AudioMixer4             crossoverMixer;
AudioFilterBiquad       noiseFilter;

// Audio Connections
AudioConnection          patchCord1(audioInput, 0, filter1, 0);
AudioConnection          patchCord2(filter1, 0, mixer1, 0);
AudioConnection          patchCord3(filter1, delay1);
AudioConnection          patchCord4(delay1, 0, mixer1, 1);
AudioConnection          patchCord5(filter1, reverb1);
AudioConnection          patchCord6(reverb1, 0, mixer1, 2);
AudioConnection          patchCord7(mixer1, 0, crossoverMixer, 0);
AudioConnection          patchCord8(crossoverMixer, 0, hornFilter, 0);
AudioConnection          patchCord9(crossoverMixer, 1, drumFilter, 0);
AudioConnection          patchCord10(hornFilter, 0, audioOutput, 0);
AudioConnection          patchCord11(drumFilter, 0, audioOutput, 1);

// Effect Parameters Structure
struct EffectParams {
  float speed;
  float depth;
  float tone;
  float mix;
  float delayTime;
  float feedback;
  float reverbSize;
};

// Rotary Parameters Structure
struct RotaryParams {
  float hornSpeed;
  float drumSpeed;
  float hornDepth;
  float drumDepth;
  float hornResonance;
  float drumResonance;
} rotaryParams = {
  .hornSpeed = 6.0f,
  .drumSpeed = 5.5f,
  .hornDepth = 0.7f,
  .drumDepth = 0.5f,
  .hornResonance = 2.0f,
  .drumResonance = 1.5f
};

// Effect parameters for each mode
EffectParams effectParams[NUM_MODES] = {
  {1.0f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f},  // Mode 0: Classic Rotary
  {1.0f, 0.5f, 0.5f, 0.5f, 300.0f, 0.4f, 0.0f}, // Mode 1: Rotary + Delay
  {1.0f, 0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.6f},  // Mode 2: Rotary + Reverb
  {1.0f, 0.5f, 0.5f, 0.5f, 250.0f, 0.3f, 0.4f}  // Mode 3: Full Process
};

// Function implementations as provided in the original code...
[Previous function implementations here]

void setup() {
  Serial.begin(115200);
  
  // Initialize audio system
  AudioMemory(20);
  
  // Initialize pins
  for (int i = 0; i < NUM_MODES; i++) {
    pinMode(MODE_LEDS[i], OUTPUT);
  }
  pinMode(BYPASS_SWITCH, INPUT_PULLUP);
  
  // Setup Rotary Encoder
  pinMode(ENC_CLK, INPUT_PULLUP);
  pinMode(ENC_DT, INPUT_PULLUP);

  // Initialize audio processing
  initializeAudio();
  
  // Load saved settings
  loadSettings();
  
  // Update LEDs
  updateModeLEDs();
  
  Serial.println("CHRONOSPHERE Initialized");
}

void loop() {
  // Process controls and audio
  readControls();
  updateRotaryParameters();
  handleBypass();
  handleModeSwitch();
  updateEffectParameters();
  monitorSystem();
}