#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>

bool verifierEtatBouton()
{
    const int REBOND = 5;

    if (PIND & 0x04)
    {
        _delay_ms(REBOND);
        if (PIND & 0x04)
        {
            _delay_ms(REBOND);
            return true;
        }
    }
    return false;
}

void busywaitdelay(int delay)
{   
    delay=delay/100;
    for (int i = 0; i < delay; i++){
        _delay_ms(0.1);
    }
}


int main()
{
    DDRA |= (1 << DD0) | (1 << DD1);
    DDRD &= ~(1 << DD2);



    //const int VERT = 0x01;
    const int ROUGE = 0x02;
    const int ETEINT = 0x00;



    while (true)
    {
        if (verifierEtatBouton())
        {

            for (int i = 0; i < 1000; i++)
            {

                PORTA = ROUGE;
                busywaitdelay(i);
                PORTA = ETEINT;
                busywaitdelay(1000 - i);

                
            }
        }
    }
    return 0;
}