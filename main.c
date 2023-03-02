#include <msp430.h> 


int main(void)
{

    gpio_init();
    timer_init();
    i2c_init();
    adc_init();

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
while(1){
	if(sensor0==1){
	    //print detection to serial and iot
	}
	if(door_opens){
	    total_occupants++;
	    room0_occupants++;
	}
	if(sensor1==1){
	    room0_occupants=room0_occupants-1;
	    room1++;
	}
	if(sensor2==1){
	    room1=room1=1;
	    room2++;
	}
	if(exit_sensor==1){
	    room2=room2-1;
	    total_occupants=total_occupants-1;
	}
	//print all of that stuff to serial and iot updated on interrupt of sensor
	return 0;
    }
}

void gpio_init(){
    //pins
}

void timer_init(){
    //timer here
    //i dont think this really matters that much, does not depend on clk
}

void i2c_init(){
    //iot broker or whatever
    //initialize variables that i want to use for thingy
}

void adc_init(){
    //interpret analog sensor data ig?
    //maybe need to send "door" signal as this?
}

