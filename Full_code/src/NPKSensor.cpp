#include "NPKSensor.h"

extern HardwareSerial mod;

const byte nitro[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xE4, 0x0C};
const byte phos[]  = {0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xB5, 0xCC};
const byte pota[]  = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};
const byte ec[]    = {0x01, 0x03, 0x00, 0x15, 0x00, 0x01, 0x95, 0xCE};
const byte ph[]    = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};
const byte hum[]   = {0x01, 0x03, 0x00, 0x12, 0x00, 0x01, 0x24, 0x0F};
const byte temp[]  = {0x01, 0x03, 0x00, 0x13, 0x00, 0x01, 0x75, 0xCF};

struct Calibration {
    const float* coeffs;
    int degree;
};

const float coeffsN[]  = {0.67, 1.10, -0.002};
const float coeffsP[]  = {17.85, -0.55, 0.019};
const float coeffsK[]  = {-10.98, 0.71, 0.0036};
const float coeffsPH[] = {-54.04, 14.32, -0.81};                     // Degree 1
const float coeffsT[]  = {0, 1};                    // Degree 1
const float coeffsH[]  = {-41.84, 7.70, 0.03};                 // Degree 1

// const float coeffsPH[] = {-3.0908, 1.7652};                     // Degree 1
// const float coeffsT[]  = {-10.6541, 1.4390};                    // Degree 1
// const float coeffsH[]  = {-15.4545,  2.5441};                     // Degree 1


Calibration calN  = {coeffsN, 2};
Calibration calP  = {coeffsP, 2};
Calibration calK  = {coeffsK, 2};
Calibration calPH = {coeffsPH, 2};
Calibration calT  = {coeffsT, 1};
Calibration calH  = {coeffsH, 2};

float calibrate(float raw, Calibration cal) {
    float result = cal.coeffs[0];
    for (int i = 1; i <= cal.degree; i++) {
        result += (cal.coeffs[i] * pow(raw, i));
    }
    return result;
}

uint16_t readSensor(const byte* command, byte len) {
    byte values[8];

    digitalWrite(DE, HIGH);
    digitalWrite(RE, HIGH);
    delay(10);
    mod.write(command, len);
    mod.flush();

    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    delay(100);

    for (byte i = 0; i < 8; i++) {
        if (mod.available()) {
        values[i] = mod.read();
        }
    }

    return (values[3] << 8) | values[4];
}

float nitrogen() {
    return max(0.0f, calibrate(readSensor(nitro, sizeof(nitro)), calN));
}

float phosphorus() {
    return max(0.0f, calibrate(readSensor(phos, sizeof(phos)), calP));
}

float potassium() {
    return max(0.0f, calibrate(readSensor(pota, sizeof(pota)), calK));
}

uint16_t electricalConductivity() {
    return readSensor(ec, sizeof(ec));
}

float potentialHydrogen() {
    return max(0.0f, calibrate(readSensor(ph, sizeof(ph))/100.0, calPH));
}

float humidity() {
    return max(0.0f, calibrate(readSensor(hum, sizeof(hum))/10.0, calH));
}

float temperature() {
    return calibrate(readSensor(temp, sizeof(temp))/10.0, calT);
}
