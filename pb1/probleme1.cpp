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
    delay=delay/10;

    for (int i = 0; i < delay; i++){
        _delay_ms(0.01);
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
            int a = 0;
            for (int i = 0; i < 3000; i++)
            {
                a = i/3;
                PORTA = ROUGE;
                busywaitdelay(a);
                PORTA = ETEINT;
                busywaitdelay(1000 - a);

                
            }
        }
    }
    return 0;
}