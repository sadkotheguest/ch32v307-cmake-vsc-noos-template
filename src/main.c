/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : sadkotheguest
 * Version            : V0.0.1
 * Date               : 2023/03/14
 * Description        : Main program body.
 * Copyright (c) sadkotheguest
 * SPDX-License-Identifier: Apache-2.0
 *******************************************************************************/
#include "ch32v30x.h"
#include "debug.h"

/* Global typedef */

/* Global define */

/* Global Variable */

void LED1_BLINK_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = { 0 };
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int main(void)
{
    u8 i = 0;
    Delay_Init();
    LED1_BLINK_INIT();

    GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    while(1)
    {
        Delay_Ms(250);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
    }

}
