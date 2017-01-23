#include <avr/io.h>
#include <util/delay.h>
#include "config.h"


void fade_pin(int8_t led, int8_t dir)
{
    uint8_t brightness, final;
    uint8_t i;

    if (dir == FADE_ON_DIR) {
        brightness = 0;
        final = 255;
    } else {
        brightness = 255;
        final = 0;
    }

    do {
        for (i = 0; i < 255; i++)
        {
            if (i < brightness) {
                LED_PORT |= (led);
            } else {
                LED_PORT &= ~(led);
            }

            _delay_us(FADE_DELAY);
        }

        brightness += dir;
    } while (brightness != final);

    if (dir == FADE_ON_DIR) {
        LED_PORT |= (led);
    } else {
        LED_PORT &= ~(led);
    }
}

int main(void)
{
    LED_DDR = 0XFF;

    uint8_t i, d;
    uint8_t num_patterns = sizeof(patterns) / sizeof(patterns[0]);
    int8_t led, delay, op;

    while (1)
    {
        for (i = 0; i < num_patterns; i++)
        {
            led = patterns[i][0];
            op = patterns[i][1];
            delay = patterns[i][2];

            switch (op) {
                case TURN_ON:
                    LED_PORT |= led;
                    break;
                case TURN_OFF:
                    LED_PORT &= ~(led);
                    break;
                case FADE_ON_DIR:
                case FADE_OFF_DIR:
                    fade_pin(led, op);
                    break;
                default:
                    break;
            }

            for (d = 0; d < delay; d++)
            {
                _delay_ms(1);
            }
        }
    }

    return 0;
}
