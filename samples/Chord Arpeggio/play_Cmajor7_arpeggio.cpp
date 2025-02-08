#define BUZZER_1 8
#define BUZZER_2 7
#define BUZZER_3 6
#define BUZZER_4 5

// Note Frequencies
#define NOTE_C3 130
#define NOTE_E3 165
#define NOTE_G3 196
#define NOTE_B3 246

// Chord Definitions
int CM7[] = {NOTE_C3, NOTE_E3, NOTE_G3, NOTE_B3};  // Define CM7 as an array of integers

// Chord Progression
int *chords[] = {CM7};

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
        delay(500); // Pause between chords
    }
    delay(2000); // Longer pause before repeating
}

void playChord(int *chord) {
    // Play each note in the chord sequentially to create an arpeggio effect
    tone(BUZZER_1, chord[0], 300); // Play the first note (C3)
    delay(300); // Wait for the note to finish
    noTone(BUZZER_1); // Stop the first note

    tone(BUZZER_2, chord[1], 300); // Play the second note (E3)
    delay(300); // Wait for the note to finish
    noTone(BUZZER_2); // Stop the second note

    tone(BUZZER_3, chord[2], 300); // Play the third note (G3)
    delay(300); // Wait for the note to finish
    noTone(BUZZER_3); // Stop the third note
  
  	tone(BUZZER_4, chord[3], 300); // Play the third note (G3)
    delay(300); // Wait for the note to finish
    noTone(BUZZER_4); // Stop the third note
}