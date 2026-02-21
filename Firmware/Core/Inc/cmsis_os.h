/**
 * @file cmsis_os.h
 * @brief CMSIS-RTOS2 API header for FreeRTOS (minimal declarations used by
 *        this project).
 *
 * This header provides the CMSIS-RTOS2 type definitions and function
 * declarations required by main.c and fifo_bridge.c.  It follows the
 * ARM CMSIS-RTOS2 API specification and is intended to be complemented by
 * the FreeRTOS CMSIS-RTOS2 wrapper implementation
 * (Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c).
 */

#ifndef CMSIS_OS_H
#define CMSIS_OS_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ---- Status codes ------------------------------------------------------ */

typedef enum {
    osOK                =  0, /**< Operation completed successfully */
    osError             = -1, /**< Unspecified RTOS error */
    osErrorTimeout      = -2, /**< Operation not completed within the timeout */
    osErrorResource     = -3, /**< Resource not available */
    osErrorParameter    = -4, /**< Parameter error */
    osErrorNoMemory     = -5, /**< System is out of memory */
    osErrorISR          = -6, /**< Not allowed in ISR context */
    osStatusReserved    = 0x7FFFFFFF /**< Prevents enum down-size compiler optimisation */
} osStatus_t;

/* ---- Thread priority --------------------------------------------------- */

typedef enum {
    osPriorityNone          =  0,
    osPriorityIdle          =  1,
    osPriorityLow           =  8,
    osPriorityLow1          =  9,
    osPriorityLow2          = 10,
    osPriorityLow3          = 11,
    osPriorityLow4          = 12,
    osPriorityLow5          = 13,
    osPriorityLow6          = 14,
    osPriorityLow7          = 15,
    osPriorityBelowNormal   = 16,
    osPriorityBelowNormal1  = 17,
    osPriorityBelowNormal2  = 18,
    osPriorityBelowNormal3  = 19,
    osPriorityBelowNormal4  = 20,
    osPriorityBelowNormal5  = 21,
    osPriorityBelowNormal6  = 22,
    osPriorityBelowNormal7  = 23,
    osPriorityNormal        = 24,
    osPriorityNormal1       = 25,
    osPriorityNormal2       = 26,
    osPriorityNormal3       = 27,
    osPriorityNormal4       = 28,
    osPriorityNormal5       = 29,
    osPriorityNormal6       = 30,
    osPriorityNormal7       = 31,
    osPriorityAboveNormal   = 32,
    osPriorityAboveNormal1  = 33,
    osPriorityAboveNormal2  = 34,
    osPriorityAboveNormal3  = 35,
    osPriorityAboveNormal4  = 36,
    osPriorityAboveNormal5  = 37,
    osPriorityAboveNormal6  = 38,
    osPriorityAboveNormal7  = 39,
    osPriorityHigh          = 40,
    osPriorityHigh1         = 41,
    osPriorityHigh2         = 42,
    osPriorityHigh3         = 43,
    osPriorityHigh4         = 44,
    osPriorityHigh5         = 45,
    osPriorityHigh6         = 46,
    osPriorityHigh7         = 47,
    osPriorityRealtime      = 48,
    osPriorityRealtime1     = 49,
    osPriorityRealtime2     = 50,
    osPriorityRealtime3     = 51,
    osPriorityRealtime4     = 52,
    osPriorityRealtime5     = 53,
    osPriorityRealtime6     = 54,
    osPriorityRealtime7     = 55,
    osPriorityISR           = 56,
    osPriorityError         = -1,
    osPriorityReserved      = 0x7FFFFFFF
} osPriority_t;

/* ---- Opaque handle types ----------------------------------------------- */

typedef void *osThreadId_t;

/* ---- Thread attributes ------------------------------------------------- */

typedef struct {
    const char   *name;        /**< Name of the thread */
    uint32_t      attr_bits;   /**< Attribute bits (reserved, set to 0) */
    void         *cb_mem;      /**< Memory for control block (NULL = dynamic) */
    uint32_t      cb_size;     /**< Size of cb_mem in bytes */
    void         *stack_mem;   /**< Memory for stack (NULL = dynamic) */
    uint32_t      stack_size;  /**< Stack size in bytes */
    osPriority_t  priority;    /**< Initial thread priority */
    uint32_t      tz_module;   /**< TrustZone module identifier */
    uint32_t      reserved;    /**< Reserved (must be 0) */
} osThreadAttr_t;

/* ---- Thread function type ---------------------------------------------- */

typedef void (*osThreadFunc_t)(void *argument);

/* ---- Kernel management ------------------------------------------------- */

/**
 * @brief  Initialize the RTOS kernel.
 * @return osOK on success, error code otherwise.
 */
osStatus_t osKernelInitialize(void);

/**
 * @brief  Start the RTOS kernel scheduler.
 * @return osError if the scheduler could not be started (should not return on success).
 */
osStatus_t osKernelStart(void);

/* ---- Thread management ------------------------------------------------- */

/**
 * @brief  Create a thread and add it to active threads.
 * @param  func      Thread function.
 * @param  argument  Argument passed to the thread function.
 * @param  attr      Thread attributes, or NULL for defaults.
 * @return Thread ID on success, NULL on failure.
 */
osThreadId_t osThreadNew(osThreadFunc_t func, void *argument,
                         const osThreadAttr_t *attr);

/**
 * @brief  Yield control to the next ready thread of the same or higher priority.
 * @return osOK on success, error code otherwise.
 */
osStatus_t osThreadYield(void);

#ifdef __cplusplus
}
#endif

#endif /* CMSIS_OS_H */
