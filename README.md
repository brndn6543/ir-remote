# IR Sensor and Remote
This shows an infrared sensor communicating with a remote.

**Watch on YouTube**

[![Watch on YouTube](https://i.postimg.cc/6pr5yJwj/irremoate.jpg)](https://youtu.be/Yctucltmd4Q)

## Code
Requires the **IRremote** library, this is included in the **lib** directory of the project along with many examples.

The remote sends a number of hexadecimal values representing functions on the remote. The bulk of the
code is `switch` statement mapping these hex codes to the functions on the remote:

```c++
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
```