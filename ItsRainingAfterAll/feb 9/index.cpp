// Define Buzzers
#define BUZZER_1 8
#define BUZZER_2 7
#define BUZZER_3 6
#define BUZZER_4 5

// Note durations
const int NOTE_PLAY = 300;
const int NOTE_FINISH = 200;
const int LONGER_REST = 1000;
const int SHORT_PAUSE = 60;

// Emaj7
#define NOTE_E3 165
#define NOTE_GS3 208
#define NOTE_B3 247
#define NOTE_DS4 311

// Em7
#define NOTE_G3 196
#define NOTE_D4 293

// D#m7
#define NOTE_DS3 156
#define NOTE_FS3 185
#define NOTE_AS3 233
#define NOTE_CS4 277

// Abm7
#define NOTE_AB3 208
#define NOTE_EB4 311
#define NOTE_GB4 370

// Abmaj7
#define NOTE_C4 261
#define NOTE_G4 392

// Dbm7
#define NOTE_DB3 138
#define NOTE_E3 165
#define NOTE_AB3 208
#define NOTE_B3 247

// F#
#define NOTE_FS3 185
#define NOTE_AS3 233
#define NOTE_CS4 277
#define NOTE_E4 329

// BM7
#define NOTE_B3 247
#define NOTE_DS4 311
#define NOTE_FS4 370
#define NOTE_AS4 466

// B7
#define NOTE_A4 440

// Pre-Chorus
#define NOTE_F4 349
#define NOTE_BB3 233
#define NOTE_D4 293
#define NOTE_FD4 365
#define NOTE_F2 87
#define NOTE_CS4 277
#define NOTE_GS4 415
#define NOTE_BB3 233
#define NOTE_AB4 415

// Chorus
#define NOTE_G3 196
#define NOTE_BB3 233
#define NOTE_BM3 247
#define NOTE_A3 220
#define NOTE_AM3 220
#define NOTE_E4 329

// Solo
#define NOTE_GM3 196
#define NOTE_FSM3 185
#define NOTE_DSM4 311

// Bridge
#define NOTE_BBDIM3 233
#define NOTE_E7 329

// Key Change
#define NOTE_GS3 208
#define NOTE_GSM3 208
#define NOTE_C4 261
#define NOTE_CM3 261
#define NOTE_FM3 175
#define NOTE_AS3 233
#define NOTE_DS3 155
#define NOTE_F7 175
#define NOTE_DS4 311

// Chord Definitions --

// Verse:
int Emaj7[] = {NOTE_E3, NOTE_GS3, NOTE_DS4}; //repeats the 1st note
int Em7[] = {NOTE_E3, NOTE_G3, NOTE_D4};
int Dsm7[] = {NOTE_DS3, NOTE_FS3, NOTE_CS4};
int Abm7[] = {NOTE_AB3, NOTE_B3, NOTE_GB4}; 
int Abmaj7[] = {NOTE_AB3, NOTE_C4, NOTE_G4};
int Dbm7[] = {NOTE_DB3, NOTE_E3, NOTE_B3};
int FS7[] = {NOTE_FS3, NOTE_AS3, NOTE_E4};
int Bmaj7[] = {NOTE_B3, NOTE_DS4, NOTE_FS4, NOTE_AS4};
int Bdom7[] = {NOTE_B3, NOTE_DS4, NOTE_FS4, NOTE_A4};

// Pre-chords:
int FSm7[] = {NOTE_FS3, NOTE_A3, NOTE_E4};
int Bmaj7_2[] = {NOTE_B3, NOTE_DS4, NOTE_AS4};
int FDim7[] = {NOTE_F2, NOTE_AB3, NOTE_D4};
int Bb7[] = {NOTE_BB3, NOTE_D4, NOTE_F4, NOTE_AB4};
int Amaj7[] = {NOTE_A3, NOTE_CS4, NOTE_E4, NOTE_GS4};
int FS7_long[] = {NOTE_FS3, NOTE_AS3, NOTE_CS4, NOTE_E4};

// Chord Progression
int *chords[] = {
  // Verse
  Emaj7, Em7, Dsm7, Abm7,
  Emaj7, Em7, Dsm7, Abmaj7,
  Emaj7, Em7, Dsm7, Abm7,
  Dbm7, FS7, Bmaj7, /* Rest */
  
  Emaj7, Em7, Dsm7, Abm7,
  Emaj7, Em7, Dsm7, Abmaj7,
  Emaj7, Em7, Dsm7, Abm7,
  Dbm7, FS7, Bmaj7, Bmaj7, Bdom7, Bdom7,
  
  // Pre-chorus
  Emaj7, Em7, Dsm7, Abmaj7,
  Dbm7, FS7, FSm7, Bmaj7_2,
  FDim7, Bb7, Dsm7, Bb7,
  Amaj7, Amaj7, Emaj7, FS7_long,
  
  /* Rest */
  
};

int numChords = sizeof(chords) / sizeof(chords[0]);

void setup () {
    // Initialize the buzzer pins as output
    pinMode(BUZZER_1, OUTPUT);
    pinMode(BUZZER_2, OUTPUT);
    pinMode(BUZZER_3, OUTPUT);
  	pinMode(BUZZER_4, OUTPUT);
}

void loop() {
     for (int i = 0; i < numChords; i++) {
        playChord(chords[i]);
        
        if (i == 14) { 
            delay(LONGER_REST); // Longer rest
        } else if (i == 48){
            delay(LONGER_REST); // Longer rest
        } else {
            delay(SHORT_PAUSE); // Short pause between chords
        }
    }
  
    delay(3000); // Pause before repeating the progression
}

void playChord(int *chord) {
   	// Play each note in the chord sequentially to create an arpeggio effect
   
   	tone(BUZZER_1, chord[0], NOTE_PLAY); // Play the first note (C3)
    delay(NOTE_FINISH); // Wait for the note to finish
    noTone(BUZZER_1); // Stop the first note

    tone(BUZZER_2, chord[1], NOTE_PLAY); // Play the second note (E3)
    delay(NOTE_FINISH); // Wait for the note to finish
    noTone(BUZZER_2); // Stop the second note

    tone(BUZZER_3, chord[2], NOTE_PLAY); // Play the third note (G3)
    delay(NOTE_FINISH); // Wait for the note to finish
    noTone(BUZZER_3); // Stop the third note
  
  	tone(BUZZER_4, chord[3], NOTE_PLAY); // Play the third note (G3)
    delay(NOTE_FINISH); // Wait for the note to finish
    noTone(BUZZER_4); // Stop the third note
}