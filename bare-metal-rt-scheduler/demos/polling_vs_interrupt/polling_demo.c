/*
    TASK:  
    1. Blink by polling method
    2. Measure time period with logic analyzer
    Questions:
    1. Is blink stable? 
    2. Does it change if I add more code lines in the loop?
    3. What is the CPU load?

    Timer? 
    T = (N * K * p)/ fclk_cpu --> for timer 1 s --> 16000000 = N * p (prescaler) * k
    -> I want to have the lowest  prescaler for better control
    -> N = 16000000/ (8*k);  p = 8 
    -> N = 256;  k = 7812 TIMER0 - 8bits
    -> Reverse calc: 256 * 8 * 7812 = 15.998.976 Hz, 0.01% error range
    -> 128 us * 7812 = 999.936 us  ( T = 1/f --> for this case T = 0,0000005s)
 */
#include <avr/io.h>
#define CPU_CORE 16000000UL
#define LED PD2
#define timer_1s 7812

volatile uint16_t k_counter;
void init()
{
    TCCR0A = 0;         // Normal mode; TOV Flag set on MAX - 0xFF
    TCCR0B |= (1<<CS01); // prescaler 8

    DDRD |= (1<<LED);   // LED pin - output pin(1)
    PORTD = 0;          // LED off

    k_counter = 0;
}

int main()
{
    init();
    while(1)
    {
        if(TIFR0 & (1<<TOV0))
        {
            TIFR0 |= (1<<TOV0);
            k_counter++;
        }
        if(k_counter == timer_1s)
        {
            k_counter = 0;
            PORTD  ^= (1<<LED);
        }
    }
    return 0;
}