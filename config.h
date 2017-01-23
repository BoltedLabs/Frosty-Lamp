#ifndef __CONFIG_H__
#define __CONFIG_H__
#define FADE_ON_DIR         1
#define FADE_OFF_DIR        -1
#define TURN_ON             3
#define TURN_OFF            4

/*******************************************
Editable Config Below
********************************************/

#define LED_DDR         DDRB
#define LED_PORT        PORTB
#define LED_1           PB0
#define LED_2           PB1
#define LED_3           PB2
#define LED_4           PB3
#define LED_5           PB4

#define TOTAL_LEDS          5
#define FADE_DELAY          2

int16_t patterns[][3] = {
    /* LED(s), OP, DELAY */

    /* Pattern 1 */
    { (1<<LED_2 | 1<<LED_5), FADE_ON_DIR, 200 },
    { (1<<LED_1 | 1<<LED_3 | 1<<LED_4), FADE_ON_DIR, 500 },
    { (1<<LED_1), FADE_OFF_DIR, 100 },
    { (1<<LED_2), FADE_OFF_DIR, 100 },
    { (1<<LED_3), FADE_OFF_DIR, 100 },
    { (1<<LED_4), FADE_OFF_DIR, 100 },
    { (1<<LED_5), FADE_OFF_DIR, 200 },

    /* Pattern 2 */
    { (1<<LED_2 | 1<<LED_5), FADE_ON_DIR, 100 },

    { (1<<LED_1), TURN_ON, 50 },
    { (1<<LED_3), TURN_ON, 50 },
    { (1<<LED_4), TURN_ON, 50 },

    { (1<<LED_4), TURN_OFF, 50 },
    { (1<<LED_3), TURN_OFF, 50 },
    { (1<<LED_1), TURN_OFF, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_ON, 100 },
    { (1<<LED_4), TURN_ON, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_OFF, 100 },
    { (1<<LED_4), TURN_OFF, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_ON, 100 },
    { (1<<LED_4), TURN_ON, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_OFF, 100 },
    { (1<<LED_4), TURN_OFF, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_ON, 100 },
    { (1<<LED_4), TURN_ON, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_OFF, 100 },
    { (1<<LED_4), TURN_OFF, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_ON, 100 },
    { (1<<LED_4), TURN_ON, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_OFF, 100 },
    { (1<<LED_4), TURN_OFF, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_ON, 100 },
    { (1<<LED_4), TURN_ON, 50 },

    { (1<<LED_1 | 1<<LED_3), TURN_OFF, 100 },
    { (1<<LED_4), TURN_OFF, 50 },

    { (1<<LED_2 | 1<<LED_5), FADE_OFF_DIR, 500 },
};

#endif
