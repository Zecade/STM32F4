#ifndef __KEY_H__
#define __KEY_H__

#include "KEY_dec.h"
#include "stdbool.h"
#include "Delay.h"

void KEY_Init(KEY_t* KEY);
bool KEY_Scan(KEY_t* KEY);




#endif /* __KEY_H__ */
