//read PPM signals from 2 channels of an RC reciever
//http://arduino.cc/forum/index.php/topic,42286.0.html

//接收机两个通道分别接arduino的数字口2、3脚
//Most Arduino boards have two external interrupts: numbers 0 (on digital pin 2) and 1 (on digital pin 3).
//The Arduino Mega has an additional four: numbers 2 (pin 21), 3 (pin 20), 4 (pin 19), and 5 (pin 18).
int ppm1 = 2;  //channel 1 connect to T14SG Reciever channel No.1 PITCH (interrupts: numbers 0)
int ppm2 = 3;  //channel 2 connect to T14SG Reciever channel No.2 YAW (interrupts: numbers 1)
int ppm3 = 20;  //channel 3 connect to T14SG Reciever channel No.3 THROTTLE (interrupts: numbers 3)
int ppm4 = 21;  //channel 4 connect to T14SG Reciever channel No.4 ROLL (interrupts: numbers 2)

unsigned long rc1_PulseStartTicks,rc2_PulseStartTicks,rc3_PulseStartTicks,rc4_PulseStartTicks;        
volatile int rc1_val, rc2_val, rc3_val, rc4_val;  

void setup() {

        Serial.begin(9600);  

        //PPM inputs from RC receiver
        pinMode(ppm1, INPUT); 
        pinMode(ppm2, INPUT); 
        pinMode(ppm3, INPUT); 
        pinMode(ppm4, INPUT); 

        // 电平变化即触发中断
        attachInterrupt(0, rc1, CHANGE);    
        attachInterrupt(1 , rc2, CHANGE);    
        attachInterrupt(3, rc3, CHANGE);    
        attachInterrupt(2, rc4, CHANGE);    
}

void rc1()
{
        // did the pin change to high or low?
        if (digitalRead( ppm1 ) == HIGH)
                rc1_PulseStartTicks = micros();    // store the current micros() value
        else
                rc1_val = micros() - rc1_PulseStartTicks; 
}

void rc2()
{
        // did the pin change to high or low?
        if (digitalRead( ppm2 ) == HIGH)
                rc2_PulseStartTicks = micros();    
        else
                rc2_val = micros() - rc2_PulseStartTicks; 
}

void rc3()
{
        // did the pin change to high or low?
        if (digitalRead( ppm3 ) == HIGH)
                rc3_PulseStartTicks = micros();    // store the current micros() value
        else
                rc3_val = micros() - rc3_PulseStartTicks; 
}
void rc4()
{
        // did the pin change to high or low?
        if (digitalRead( ppm4 ) == HIGH)
                rc4_PulseStartTicks = micros();    // store the current micros() value
        else
                rc4_val = micros() - rc4_PulseStartTicks; 
}

void loop() {

        //print values
        Serial.print("channel 1:  ");
        Serial.print(rc1_val);  
        Serial.print("        ");
        Serial.print("channel 2:  ");   
        Serial.println(rc2_val);
        Serial.print("        ");  
        Serial.print("channel 3:  ");
        Serial.print(rc3_val);  
        Serial.print("        ");        
        Serial.print("channel 4:  ");
        Serial.print(rc4_val);  
        Serial.print("        "); 
}

