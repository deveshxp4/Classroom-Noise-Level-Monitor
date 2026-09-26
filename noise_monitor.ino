const int SOUND_SENSOR = A0;

const int GREEN_LED = 8;
const int YELLOW_LED = 9;
const int RED_LED = 10;

const int LOW_THRESHOLD = 200;
const int HIGH_THRESHOLD = 500;
const int LOW_HYSTERESIS = 20;
const int HIGH_HYSTERESIS = 20;

const unsigned long SAMPLE_INTERVAL = 200;
unsigned long previousMillis = 0;

enum NoiseLevel {
    LOW,
    MODERATE,
    HIGH
};

NoiseLevel currentLevel = LOW;

void updateNoiseLevel(int soundLevel) {
    switch (currentLevel) {
        case LOW:
            if (soundLevel >= HIGH_THRESHOLD) {
                currentLevel = HIGH;
            } else if (soundLevel >= LOW_THRESHOLD) {
                currentLevel = MODERATE;
            }
            break;

        case MODERATE:
            if (soundLevel >= HIGH_THRESHOLD) {
                currentLevel = HIGH;
            } else if (soundLevel < LOW_THRESHOLD - LOW_HYSTERESIS) {
                currentLevel = LOW;
            }
            break;

        case HIGH:
            if (soundLevel < LOW_THRESHOLD - LOW_HYSTERESIS) {
                currentLevel = LOW;
            } else if (soundLevel < HIGH_THRESHOLD - HIGH_HYSTERESIS) {
                currentLevel = MODERATE;
            }
            break;
    }
}

void updateLEDs() {
    digitalWrite(GREEN_LED, currentLevel == LOW ? HIGH : LOW);
    digitalWrite(YELLOW_LED, currentLevel == MODERATE ? HIGH : LOW);
    digitalWrite(RED_LED, currentLevel == HIGH ? HIGH : LOW);
}

void setup() {
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    Serial.begin(9600);

    updateLEDs();
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= SAMPLE_INTERVAL) {
        previousMillis = currentMillis;

        int soundLevel = analogRead(SOUND_SENSOR);

        updateNoiseLevel(soundLevel);
        updateLEDs();

        Serial.print("Sensor Value: ");
        Serial.print(soundLevel);
        Serial.print(" | Noise Level: ");

        if (currentLevel == LOW) {
            Serial.println("LOW");
        } else if (currentLevel == MODERATE) {
            Serial.println("MODERATE");
        } else {
            Serial.println("HIGH");
        }
    }
}