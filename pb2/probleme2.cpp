#define F_CPU 8000000

#include <avr/io.h> 
#include <util/delay.h>



int main()
{
    DDRB |= (1 << DD0) | (1 << DD1);

    const int ON = 0x01;   
    const int OFF = 0x00;


    for(int i = 0; i < 600; i++)
    {
        if (i < 120)
        {
            PORTB = OFF;
            _delay_ms(16.7);
        }

        else if (i < 240)
        {
            PORTB = ON;
            _delay_ms(4.20);
            PORTB = OFF;
            _delay_ms(12.5);
        }
        
        else if (i < 360)
        {
            PORTB = ON;
            _delay_ms(8.35);
            PORTB = OFF;
            _delay_ms(8.35);
        }

        else if (i < 480)
        {
            PORTB = ON;
            _delay_ms(12.5);
            PORTB = OFF;
            _delay_ms(4.20);
        }

        else
        {
            PORTB = ON;
            _delay_ms(16.7);
        }
    }

    for(int i = 0; i < 600; i++)
    {
        if (i < 120)
        {
            PORTB = OFF;
            _delay_ms(16.7);
        }

        else if (i < 240)
        {
            PORTB = ON;
            _delay_ms(4.20);
            PORTB = OFF;
            _delay_ms(12.5);
        }
        
        else if (i < 360)
        {
            PORTB = ON;
            _delay_ms(8.35);
            PORTB = OFF;
            _delay_ms(8.35);
        }

        else if (i < 480)
        {
            PORTB = ON;
            _delay_ms(12.5);
            PORTB = OFF;
            _delay_ms(4.20);
        }

        else
        {
            PORTB = ON;
            _delay_ms(16.7);
        }
    }
    
    for(int i = 0; i < 4000; i++)
    {
        if (i < 800)
        {
            PORTB = OFF;
            _delay_ms(2.5);
        }

        else if (i < 1600)
        {
            PORTB = ON;
            _delay_ms(0.63);
            PORTB = OFF;
            _delay_ms(1.87);
        }
        
        else if (i < 2400)
        {
            PORTB = ON;
            _delay_ms(1.25);
            PORTB = OFF;
            _delay_ms(1.25);
        }

        else if (i < 3600)
        {
            PORTB = ON;
            _delay_ms(1.87);
            PORTB = OFF;
            _delay_ms(0.63);
        }

        else
        {
            PORTB = ON;
            _delay_ms(2.5);
        }
    }

    PORTB = OFF;
return 0;
}