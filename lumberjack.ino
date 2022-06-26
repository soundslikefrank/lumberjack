#include <Audio.h>
#include <SD.h>
#include <SPI.h>
#include <SerialFlash.h>
#include <Wire.h>

// Number of samples in each delay line
#define CHORUS_DELAY_LENGTH (16 * AUDIO_BLOCK_SAMPLES)
// Allocate the delay lines for left and right channels
short c1_delayline[CHORUS_DELAY_LENGTH];
short c2_delayline[CHORUS_DELAY_LENGTH];
short c3_delayline[CHORUS_DELAY_LENGTH];

// number of "voices" in the chorus which INCLUDES the original voice
int n_chorus = 3;

// GUItool: begin automatically generated code
AudioSynthWaveform waveform4;   // xy=285.75,312.75
AudioSynthWaveform waveform3;   // xy=286.75,256.75
AudioSynthWaveform waveform2;   // xy=287.75,197.75
AudioSynthWaveform waveform5;   // xy=287.75,363.75
AudioSynthWaveform waveform1;   // xy=288.75,138.75
AudioSynthWaveform waveform7;   // xy=288.75,483.75
AudioSynthWaveform waveform18;  // xy=287,1232.75
AudioSynthWaveform waveform17;  // xy=288,1176.75
AudioSynthWaveform waveform16;  // xy=289,1117.75
AudioSynthWaveform waveform11;  // xy=290.75,784
AudioSynthWaveform waveform19;  // xy=289,1283.75
AudioSynthWaveform waveform15;  // xy=290,1058.75
AudioSynthWaveform waveform6;   // xy=292.75,420.75
AudioSynthWaveform waveform10;  // xy=291.75,728
AudioSynthWaveform waveform9;   // xy=292.75,669
AudioSynthWaveform waveform21;  // xy=290,1403.75
AudioSynthWaveform waveform12;  // xy=292.75,835
AudioSynthWaveform waveform8;   // xy=293.75,610
AudioSynthWaveform waveform14;  // xy=293.75,955
AudioSynthWaveform waveform20;  // xy=294,1340.75
AudioSynthWaveform waveform13;  // xy=297.75,892
AudioMixer4 mixer2;             // xy=571.75,404.75
AudioMixer4 mixer1;             // xy=574.75,224.75
AudioMixer4 mixer8;             // xy=573,1324.75
AudioMixer4 mixer5;             // xy=576.75,876
AudioMixer4 mixer7;             // xy=576,1144.75
AudioMixer4 mixer4;             // xy=579.75,696
AudioMixer4 mixer3;             // xy=841.75,303.75
AudioMixer4 mixer9;             // xy=843,1223.75
AudioMixer4 mixer6;             // xy=846.75,775
AudioEffectChorus chorus1;      // xy=1047.75,302.75
AudioEffectChorus chorus3;      // xy=1049,1222.75
AudioEffectChorus chorus2;      // xy=1052.75,774
AudioMixer4 mixer10;            // xy=1280.0000190734863,778.7500076293945
AudioEffectFreeverbStereo freeverbs1;  // xy=1481.2500190734863,787.2500047683716
AudioOutputMQS mqs1;                   // xy=1675,792.5
AudioConnection patchCord1(waveform4, 0, mixer1, 3);
AudioConnection patchCord2(waveform3, 0, mixer1, 2);
AudioConnection patchCord3(waveform2, 0, mixer1, 1);
AudioConnection patchCord4(waveform5, 0, mixer2, 0);
AudioConnection patchCord5(waveform1, 0, mixer1, 0);
AudioConnection patchCord6(waveform7, 0, mixer2, 2);
AudioConnection patchCord7(waveform18, 0, mixer7, 3);
AudioConnection patchCord8(waveform17, 0, mixer7, 2);
AudioConnection patchCord9(waveform16, 0, mixer7, 1);
AudioConnection patchCord10(waveform11, 0, mixer4, 3);
AudioConnection patchCord11(waveform19, 0, mixer8, 0);
AudioConnection patchCord12(waveform15, 0, mixer7, 0);
AudioConnection patchCord13(waveform6, 0, mixer2, 1);
AudioConnection patchCord14(waveform10, 0, mixer4, 2);
AudioConnection patchCord15(waveform9, 0, mixer4, 1);
AudioConnection patchCord16(waveform21, 0, mixer8, 2);
AudioConnection patchCord17(waveform12, 0, mixer5, 0);
AudioConnection patchCord18(waveform8, 0, mixer4, 0);
AudioConnection patchCord19(waveform14, 0, mixer5, 2);
AudioConnection patchCord20(waveform20, 0, mixer8, 1);
AudioConnection patchCord21(waveform13, 0, mixer5, 1);
AudioConnection patchCord22(mixer2, 0, mixer3, 1);
AudioConnection patchCord23(mixer1, 0, mixer3, 0);
AudioConnection patchCord24(mixer8, 0, mixer9, 1);
AudioConnection patchCord25(mixer5, 0, mixer6, 1);
AudioConnection patchCord26(mixer7, 0, mixer9, 0);
AudioConnection patchCord27(mixer4, 0, mixer6, 0);
AudioConnection patchCord28(mixer3, chorus1);
AudioConnection patchCord29(mixer9, chorus3);
AudioConnection patchCord30(mixer6, chorus2);
AudioConnection patchCord31(chorus1, 0, mixer10, 0);
AudioConnection patchCord32(chorus3, 0, mixer10, 2);
AudioConnection patchCord33(chorus2, 0, mixer10, 1);
AudioConnection patchCord34(mixer10, freeverbs1);
AudioConnection patchCord35(freeverbs1, 0, mqs1, 0);
AudioConnection patchCord36(freeverbs1, 1, mqs1, 1);
// GUItool: end automatically generated code

void setup() {
  AudioMemory(30);

  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(1.0);
  waveform2.begin(WAVEFORM_SAWTOOTH);
  waveform2.amplitude(1.0);
  waveform3.begin(WAVEFORM_SAWTOOTH);
  waveform3.amplitude(1.0);
  waveform4.begin(WAVEFORM_SAWTOOTH);
  waveform4.amplitude(1.0);
  waveform5.begin(WAVEFORM_SAWTOOTH);
  waveform5.amplitude(1.0);
  waveform6.begin(WAVEFORM_SAWTOOTH);
  waveform6.amplitude(1.0);
  waveform7.begin(WAVEFORM_SAWTOOTH);
  waveform7.amplitude(1.0);

  waveform8.begin(WAVEFORM_SAWTOOTH);
  waveform8.amplitude(1.0);
  waveform9.begin(WAVEFORM_SAWTOOTH);
  waveform9.amplitude(1.0);
  waveform10.begin(WAVEFORM_SAWTOOTH);
  waveform10.amplitude(1.0);
  waveform11.begin(WAVEFORM_SAWTOOTH);
  waveform11.amplitude(1.0);
  waveform12.begin(WAVEFORM_SAWTOOTH);
  waveform12.amplitude(1.0);
  waveform13.begin(WAVEFORM_SAWTOOTH);
  waveform13.amplitude(1.0);
  waveform14.begin(WAVEFORM_SAWTOOTH);
  waveform14.amplitude(1.0);

  waveform15.begin(WAVEFORM_SAWTOOTH);
  waveform15.amplitude(1.0);
  waveform16.begin(WAVEFORM_SAWTOOTH);
  waveform16.amplitude(1.0);
  waveform17.begin(WAVEFORM_SAWTOOTH);
  waveform17.amplitude(1.0);
  waveform18.begin(WAVEFORM_SAWTOOTH);
  waveform18.amplitude(1.0);
  waveform19.begin(WAVEFORM_SAWTOOTH);
  waveform19.amplitude(1.0);
  waveform20.begin(WAVEFORM_SAWTOOTH);
  waveform20.amplitude(1.0);
  waveform21.begin(WAVEFORM_SAWTOOTH);
  waveform21.amplitude(1.0);

  chorus1.begin(c1_delayline, CHORUS_DELAY_LENGTH, n_chorus);
  chorus2.begin(c2_delayline, CHORUS_DELAY_LENGTH, n_chorus);
  chorus3.begin(c3_delayline, CHORUS_DELAY_LENGTH, n_chorus);

  mixer1.gain(0, 0.25);
  mixer1.gain(1, 0.25);
  mixer1.gain(2, 0.25);
  mixer1.gain(3, 0.25);
  mixer2.gain(0, 0.33);
  mixer2.gain(1, 0.33);
  mixer2.gain(2, 0.33);
  mixer3.gain(0, 0.5);
  mixer3.gain(1, 0.5);

  mixer4.gain(0, 0.25);
  mixer4.gain(1, 0.25);
  mixer4.gain(2, 0.25);
  mixer4.gain(3, 0.25);
  mixer5.gain(0, 0.33);
  mixer5.gain(1, 0.33);
  mixer5.gain(2, 0.33);
  mixer6.gain(0, 0.5);
  mixer6.gain(1, 0.5);

  mixer7.gain(0, 0.25);
  mixer7.gain(1, 0.25);
  mixer7.gain(2, 0.25);
  mixer7.gain(3, 0.25);
  mixer8.gain(0, 0.333);
  mixer8.gain(1, 0.333);
  mixer8.gain(2, 0.333);
  mixer9.gain(0, 0.5);
  mixer9.gain(1, 0.5);

  mixer10.gain(0, 0.333);
  mixer10.gain(1, 0.333);
  mixer10.gain(2, 0.333);

  freeverbs1.roomsize(0.8);
  freeverbs1.damping(0.5);

  // A minor chord
  set_osc1_note(45);
  set_osc2_note(48);
  set_osc3_note(52);
}

void loop() {}

void set_osc1_note(uint8_t note_number) {
  float osc1_freq = midi_note_to_hertz(note_number);

  waveform1.frequency(offset_by_cent(osc1_freq, 5));
  waveform2.frequency(offset_by_cent(osc1_freq, 10));
  waveform3.frequency(offset_by_cent(osc1_freq, -10));
  waveform4.frequency(offset_by_cent(osc1_freq, -5));
  waveform5.frequency(offset_by_cent(osc1_freq, -2));
  waveform6.frequency(osc1_freq);
  waveform7.frequency(offset_by_cent(osc1_freq, 2));
}

void set_osc2_note(uint8_t note_number) {
  float osc2_freq = midi_note_to_hertz(note_number);

  waveform8.frequency(offset_by_cent(osc2_freq, 5));
  waveform9.frequency(offset_by_cent(osc2_freq, 10));
  waveform10.frequency(offset_by_cent(osc2_freq, -10));
  waveform11.frequency(offset_by_cent(osc2_freq, -5));
  waveform12.frequency(offset_by_cent(osc2_freq, -2));
  waveform13.frequency(osc2_freq);
  waveform14.frequency(offset_by_cent(osc2_freq, 2));
}

void set_osc3_note(uint8_t note_number) {
  float osc3_freq = midi_note_to_hertz(note_number);

  waveform15.frequency(offset_by_cent(osc3_freq, 5));
  waveform16.frequency(offset_by_cent(osc3_freq, 10));
  waveform17.frequency(offset_by_cent(osc3_freq, -10));
  waveform18.frequency(offset_by_cent(osc3_freq, -5));
  waveform19.frequency(offset_by_cent(osc3_freq, -2));
  waveform20.frequency(osc3_freq);
  waveform21.frequency(offset_by_cent(osc3_freq, 2));
}

float offset_by_cent(float base, int8_t cents) {
  return base * pow(2, (float)cents / 1200);
}

float midi_note_to_hertz(uint8_t note_number) {
  return 440 * pow(2, ((float)note_number - 69) / 12);
}
