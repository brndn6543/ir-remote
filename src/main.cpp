#include <Arduino.h>
#include <IRremote.h>

// Signal PIN of IR receiver.
int receiver = 11;

IRrecv irrecv(receiver);
uint32_t last_decodedRawData = 0;

// Separate Function for dispatching codes.
void opcode_dispatch() {
    switch (irrecv.decodedIRData.decodedRawData) {
        case 0xBA45FF00:
            Serial.println("POWER");
            break;
        case 0xB847FF00:
            Serial.println("FUNC/STOP");
            break;
        case 0xB946FF00:
            Serial.println("VOL+");
            break;
        case 0xBB44FF00:
            Serial.println("FAST BACK");
            break;
        case 0xBF40FF00:
            Serial.println("PAUSE");
            break;
        case 0xBC43FF00:
            Serial.println("FAST FORWARD");
            break;
        case 0xF807FF00:
            Serial.println("DOWN");
            break;
        case 0xEA15FF00:
            Serial.println("VOL-");
            break;
        case 0xF609FF00:
            Serial.println("UP");
            break;
        case 0xE619FF00:
            Serial.println("EQ");
            break;
        case 0xF20DFF00:
            Serial.println("ST/REPT");
            break;
        case 0xE916FF00:
            Serial.println("0");
            break;
        case 0xF30CFF00:
            Serial.println("1");
            break;
        case 0xE718FF00:
            Serial.println("2");
            break;
        case 0xA15EFF00:
            Serial.println("3");
            break;
        case 0xF708FF00:
            Serial.println("4");
            break;
        case 0xE31CFF00:
            Serial.println("5");
            break;
        case 0xA55AFF00:
            Serial.println("6");
            break;
        case 0xBD42FF00:
            Serial.println("7");
            break;
        case 0xAD52FF00:
            Serial.println("8");
            break;
        case 0xB54AFF00:
            Serial.println("9");
            break;
        default:
            Serial.println(" other button   ");
    }
}

// Function to take action based on IR code received.
void translateIR() {
    if (irrecv.decodedIRData.flags) {   // Check if IR code is a repeat.
        // Set the current raw data to the last, repeat.
        irrecv.decodedIRData.decodedRawData = last_decodedRawData;
        Serial.print("[!] REPEAT");
    } else {
        // Output the IR code on the serial monitor.
        Serial.print("IR Code: 0x");
        Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    }

    // Decode IR data.
    opcode_dispatch();

    // Store the last raw data.
    last_decodedRawData = irrecv.decodedIRData.decodedRawData;
    delay(500);
}

void setup() {
    Serial.begin(9600);
    Serial.println("IR Receiver Button Decode");
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode()) {  // Received signal?
        translateIR();
        irrecv.resume();    // Receive next value.
    }
}