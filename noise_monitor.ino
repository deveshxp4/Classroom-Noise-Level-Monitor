const int SOUND_SENSOR = A0;

const int GREEN_LED = 8;
const int YELLOW_LED = 9;
const int RED_LED = 10;

const int LOW_THRESHOLD = 200;
const int HIGH_THRESHOLD = 500;

void setup() {
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int soundLevel = analogRead(SOUND_SENSOR);

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);

    if (soundLevel < LOW_THRESHOLD) {
        digitalWrite(GREEN_LED, HIGH);
        Serial.println("Noise Level: LOW");
    }
    else if (soundLevel < HIGH_THRESHOLD) {
        digitalWrite(YELLOW_LED, HIGH);
        Serial.println("Noise Level: MODERATE");
    }
    else {
        digitalWrite(RED_LED, HIGH);
        Serial.println("Noise Level: HIGH");
    }

    Serial.print("Sensor Value: ");
    Serial.println(soundLevel);

    delay(200);
}