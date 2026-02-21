/**
 * @file main.h
 * @brief Main application header for the FT2232HL 245-Sync-FIFO bridge
 *        on STM32H750 DevEBox.
 */

#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"

/* ---- Error handler ----------------------------------------------------- */
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */
