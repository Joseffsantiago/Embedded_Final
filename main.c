#include <msp430.h>

void gpioInit();

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    gpioInit();                 // Initialize all GPIO Pins for the project


    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    int room=0;                     //initially set occupancy to 0

    while(1)
    {
        P1OUT |=  BIT7;
        if(~P2IN & BIT3){           //these can detect the occupancy of my finger on the button
            room++;}
        if(~P4IN & BIT1){
            room=room-1;}
        if(P1IN & BIT2){            //This and the one below are the IR recievers. they just suck at recieving ir i guess?
            room++;}
        if(P1IN & BIT3){
            room=room-1;}

        __delay_cycles(500000);     //half a second i think?

        if(room==0){                //setting up the leds
           P1OUT &= ~BIT4;
           P1OUT &= ~BIT5;
           P1OUT &= ~BIT6;
        }
        if(room==1){                //WHEN ROOM =1, 1 led IS ACTIVE.
            P1OUT |=  BIT4;
            P1OUT &= ~BIT5;
            P1OUT &= ~BIT6;
        }
        if(room==2){
            P1OUT |=  BIT4;
            P1OUT |=  BIT5;
            P1OUT &= ~BIT6;
        }
        if(room==3){
            P1OUT |=  BIT4;
            P1OUT |=  BIT5;
            P1OUT |=  BIT6;
        }
    }
}

void gpioInit()
{
   // Setting Directions of Pins

       P1DIR |= BIT0;              // Configure P1.0 to an Output
       P6DIR |= BIT6;              // Configure P6.6 to an Output
       P1DIR |= BIT4;
       P1DIR |= BIT5;
       P1DIR |= BIT6;
       P1DIR |= BIT7;
       P2DIR &= ~BIT3;             // Configure P2.3 to an Input
       P4DIR &= ~BIT1;             // Configure P4.1 to an Input
       P1DIR &= ~BIT2;
       P1DIR &= ~BIT3;


       P2REN |= BIT3;               // Enable Resistor on P2.3
       P2OUT |= BIT3;               // Configure Resistor on P2.3 to be Pullup

       P4REN |= BIT1;               // Enable Resistor on P4.1
       P4OUT |= BIT1;               // Configure Resistor on P4.1 to be Pullup
}
