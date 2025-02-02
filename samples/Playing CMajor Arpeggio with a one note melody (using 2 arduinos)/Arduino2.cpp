// Note definitions
#define NOTE_C5 532   // C5

// Notes in the melody
int melody[] = {
  NOTE_C5
};

int noteDurations[] = {
    2
};

void setup() {
    // ---
}

void loop() {
    PlayMusic();
    delay(100); 
}

void PlayMusic() {
    for (int thisNote = 0; thisNote < 1; thisNote++) {
        // Calculate note duration
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(9, melody[thisNote], noteDuration);
        
        // Add pause between notes (note duration + 50%)
        int pauseBetweenNotes = noteDuration * 1;
        delay(pauseBetweenNotes);
        
        // Stop the tone
        noTone(9);
    }
}