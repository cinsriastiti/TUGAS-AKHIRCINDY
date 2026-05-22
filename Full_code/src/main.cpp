#include <Arduino.h>
#include "NPKSensor.h"
#include "recModel.h"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID "f740711c-cf44-416a-bce0-b1104ce9b8ce"
#define CHARACTERISTIC_UUID_TX "83620794-4bad-4366-a73f-2ecc00d857dd"
#define CHARACTERISTIC_UUID_RX "bb178305-facf-4742-89b7-b592fb5c37ee"
#define CHARACTERISTIC_UUID_recommend "0ffb39d1-7187-46f4-be5a-cd824c8e4e1d"

BLECharacteristic *pCharacteristic = nullptr;
BLECharacteristic *pCharacteristic2 = nullptr;
BLECharacteristic *recommendCharacteristic = nullptr;

const byte RE = 16;
const byte DE = 15;

// const int sensor = 5;

HardwareSerial mod(2);

int nit, pho, pot;
float elc, pha, temp, humid;
bool deviceConnected = false;
int mode = 0;
bool done = false, zero_npk = false, sensor_nopower = false;

int i = 0;

extern void score(double *input, double *output);

double input_data[7];
double output[7];
void predict_proba(float *x, float *proba);


class ServerCallbacks : public BLEServerCallbacks
{
    void onConnect(BLEServer *pServer)
    {
        deviceConnected = true;
        Serial.println("Device connected !");
    }

    void onDisconnect(BLEServer *pServer)
    {
        deviceConnected = false;
        mode = 0;
        Serial.println("Device disconnected !");
        pServer->startAdvertising();
    }
};

class RecieveCallback : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic)
    {
        String receivedData;
        std::string rxValue = pCharacteristic->getValue();

        if (rxValue.length() > 0)
        {
            receivedData = rxValue.c_str();
            Serial.println("mode : " + receivedData);
        }

        if (receivedData == "recommend")
            mode = 1;
        else if (receivedData == "monitor")
            mode = 2;
        else
            mode = 0;
    }
};

void BT_init()
{
    Serial.println("Starting BLE");

    BLEDevice::init("ITQ-2a TDR-3000");
    BLEServer *pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_TX,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_NOTIFY);

    pCharacteristic2 = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE);

    pCharacteristic2->setCallbacks(new RecieveCallback());

    pService->start();
    // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    Serial.println("BLE Ready to connect !");
}

void sensor_init()
{
    mod.begin(9600, SERIAL_8N1, 18, 17);
    pinMode(RE, OUTPUT);
    pinMode(DE, OUTPUT);
    // pinMode(sensor, OUTPUT);
    delay(1000);

    digitalWrite(DE, HIGH);
    digitalWrite(RE, HIGH);
    delay(10);
    mod.flush();
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    // delay (500);

    // digitalWrite(sensor, LOW);

    nit = nitrogen();
    pho = phosphorus();
    pot = potassium();
    elc = electricalConductivity();
    pha = potentialHydrogen() / float(100);
    temp = temperature() / float(10);
    humid = humidity() / float(10);

    // digitalWrite(sensor, HIGH);
    Serial.println("Sensor initialized !");
}

void get_value()
{
    nit = nitrogen();
    pho = phosphorus();
    pot = potassium();
    elc = electricalConductivity();
    pha = potentialHydrogen();
    temp = temperature();
    humid = humidity();
}

// ini untuk tes si sensornya bisa atau engga dia
void testSensorManual()
{
    Serial.println("=== TEST SENSOR MANUAL ===");

    // Baca nilai langsung
    get_value();

    Serial.println("Current Sensor Values:");
    Serial.println("N: " + String(nit));
    Serial.println("P: " + String(pho));
    Serial.println("K: " + String(pot));
    Serial.println("EC: " + String(elc));
    Serial.println("pH: " + String(pha));
    Serial.println("Temp: " + String(temp));
    Serial.println("Humid: " + String(humid));
    Serial.println("======================");
}

void setup()
{
    Serial.begin(115200);

    sensor_init();
    testSensorManual();
    BT_init();
}

float nit_mean, pho_mean, pot_mean, elc_mean, temp_mean, humid_mean, pha_mean;

void loop()
{
    // delay(2000);

    while (!deviceConnected)
    {
        Serial.println("Waiting for connection...");
        delay(1000);
    }

    if (mode == 0)
    {
        zero_npk = false;
        sensor_nopower = false;
        done = false;
        i = 0;
        nit_mean = 0;
        pho_mean = 0;
        pot_mean = 0;
        temp_mean = 0;
        humid_mean = 0;
        pha_mean = 0;
        elc_mean = 0;
    }

    if (mode == 1)
    {
        delay(1000);
        get_value();
        zero_npk = false;
        sensor_nopower = false;
        if (!done)
        {
            if (i < 10)
            {
                nit_mean += nit;
                pho_mean += pho;
                pot_mean += pot;
                temp_mean += temp;
                humid_mean += humid;
                pha_mean += pha;
                elc_mean += elc;
                i++;

                Serial.printf("Data buffer %d \n", i);
                Serial.println(nit_mean);
                Serial.println(pho_mean);
                Serial.println(pot_mean);
                Serial.println(temp_mean);
                Serial.println(humid_mean);
                Serial.println(pha_mean);
                Serial.println(elc_mean);
            }
            else
            {
                nit_mean /= 10;
                pho_mean /= 10;
                pot_mean /= 10;
                temp_mean /= 10;
                humid_mean /= 10;
                pha_mean /= 10;
                elc_mean /= 10;

                Serial.println("Data Mean :");
                Serial.println(nit_mean);
                Serial.println(pho_mean);
                Serial.println(pot_mean);
                Serial.println(temp_mean);
                Serial.println(humid_mean);
                Serial.println(pha_mean);
                Serial.println(elc_mean);

                float input_data[] = {nit_mean, pho_mean, pot_mean, elc_mean,
                                      pha_mean, temp_mean, humid_mean};
                Serial.println(input_data[0]);
                Serial.println(input_data[1]);
                Serial.println(input_data[2]);
                String data = String(input_data[0]) + "," + String(input_data[1]) + "," + String(input_data[2]) + "," +
                              String(input_data[3]) + "," + String(input_data[4]) + "," + String(input_data[5]) + "," +
                              String(input_data[6]) + ",";

                if (nit_mean != 0 || pho_mean != 0 || pot_mean != 0)
                {
                    int class_index = predict(input_data);
                    for (int i = 1; i < 7; i++)
                    {
                        if (output[i] > output[class_index])
                        {
                            class_index = i;
                        }
                    }
                    String predicted_class[] = {
                        "Bawang Daun",
                        "Bawang Merah",
                        "Cabai",
                        "Parsley",
                        "Selada",
                        "Tomat",
                        "Zucchini"};
                    float proba[7];
                    predict_proba(input_data, proba);
                    data = data + predicted_class[class_index] + ",";
                    for (int j = 0; j < 7; j++)
                    {
                        data += String(proba[j] * 100.0, 1); // dalam persen, 1 desimal
                        if (j < 6)
                            data += ",";
                    }
                    Serial.printf("Class : %s\n", predicted_class[class_index].c_str());
                    // data = data + predicted_class[class_index];
                }
                else
                {
                    data = data + "0";
                }
                done = true;
                pCharacteristic->setValue(data.c_str());
                pCharacteristic->notify();
                Serial.println(data);
            }
        }
    }

    if (mode == 2)
    {
        get_value();
        if (nit == 0 && pho == 0 && pot == 0)
        {
            if (!zero_npk)
            {
                String data = "0,0,0,0,0,0,0";
                pCharacteristic->setValue(data.c_str());
                pCharacteristic->notify();
                Serial.println(data);
                Serial.println("0 sent");
                zero_npk = true;
                sensor_nopower = false;
            }
        }
        else if ((nit > 2000) || (pho > 2000) || (pot > 2000) || (pha > 2000) || (temp > 2000) || (humid > 2000))
        {
            if (!sensor_nopower)
            {
                String data = "-,-,-,-,-,-,-";
                pCharacteristic->setValue(data.c_str());
                pCharacteristic->notify();
                Serial.println(data);
                Serial.println("Sensor disconnected");
                zero_npk = false;
                sensor_nopower = true;
            }
        }
        else
        {
            zero_npk = false;
            sensor_nopower = false;

            String data = String(nit) + "," + String(pho) + "," + String(pot) + "," +
                          String(elc) + "," + String(pha) + "," + String(temp) + "," +
                          String(humid);
            pCharacteristic->setValue(data.c_str());
            pCharacteristic->notify();
            Serial.println(data);
        }
        delay(230);
    }
}