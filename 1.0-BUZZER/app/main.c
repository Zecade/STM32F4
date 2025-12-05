#include "main.h"

uint16_t melody[] = {
    NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4,
    NOTE_A4, NOTE_A4, NOTE_G4,
    NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4,
    NOTE_D4, NOTE_D4, NOTE_C4
};

uint16_t note_duration[] = {
    400, 400, 400, 400,
    400, 400, 800,
    400, 400, 400, 400,
    400, 400, 800
};

int main(void)
{

    BUZZER_Init();
    while (1)
    {
        uint32_t len = sizeof(melody) / sizeof(uint16_t);

        for (uint32_t i = 0; i < len; i++)
        {
            if (melody[i] == NOTE_REST)
            {
                BUZZER_Set(0);            // 静音
            }
            else
            {
                BUZZER_SetFreq(melody[i]);
            }

            Delay_ms(note_duration[i]); // 保持音符的时间

            // 稍微空一下，让音符分得更清楚
            BUZZER_Set(0);
            Delay_ms(50);
        }

        Delay_ms(800);
    }
}
