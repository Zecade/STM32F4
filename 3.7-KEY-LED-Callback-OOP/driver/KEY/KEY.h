#ifndef __KEY_H__
#define __KEY_H__


#include <stdbool.h>
#include <stddef.h>

struct KEY_Desc;
typedef struct KEY_Desc KEY_Desc_t;

typedef void (*KEY_Func_t)(KEY_Desc_t* KEY);

void KEY_Init(KEY_Desc_t* KEY);
void KEY_Press_Callback_Register(KEY_Desc_t* KEY, KEY_Func_t Func);


#endif /* __KEY_H__ */
