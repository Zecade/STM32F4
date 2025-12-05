#ifndef __LED_H__
#define __LED_H__

#include <stdbool.h>

struct LED_Desc;
typedef struct LED_Desc LED_Desc_t;

void LED_Init(LED_Desc_t* LED);
void LED_SetState(LED_Desc_t* LED, bool State);
void LED_ON(LED_Desc_t* LED);
void LED_OFF(LED_Desc_t* LED);
void LED_Toggle(LED_Desc_t* LED);


#endif /* __LED_H__ */
