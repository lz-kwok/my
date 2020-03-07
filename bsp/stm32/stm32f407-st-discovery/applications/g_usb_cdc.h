/*
 * Copyright (c) 2019-present, Guolz
 *
 * Date           Author       Notes
 * 2019-9-11      guolz     first version
 */

#ifndef __GUI_H__
#define __GUI_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MajorVer            1
#define MiddleVer           0
#define MinnorVer           0


#define RT_USB_CDC_THREAD_STACK_SZ      2048
#define RT_USB_CDC_THREAD_PRIO          7

#define SetBit(data, offset)            data |= 1 << offset      
#define ResetBit(data, offset)          data &= ~(1 << offset)   
#define GetBit(data, offset)            ((data >> offset) &0x01) 

#define MCU_KOUT1                       GET_PIN(E, 13)
#define MCU_KOUT2                       GET_PIN(D, 10)
#define MCU_KOUT3                       GET_PIN(E, 14)
#define MCU_KOUT4                       GET_PIN(E, 1)
#define MCU_KOUT5                       GET_PIN(E, 0)
#define MCU_KOUT6                       GET_PIN(G, 10)
#define MCU_KOUT7                       GET_PIN(G, 12)
#define MCU_KOUT8                       GET_PIN(G, 15)
#define MCU_KOUT9                       GET_PIN(G, 7)
#define MCU_KOUT10                      GET_PIN(G, 6)
#define MCU_KOUT11                      GET_PIN(G, 5)
#define MCU_KOUT12                      GET_PIN(G, 4)
#define MCU_KOUT13                      GET_PIN(G, 3)
#define MCU_KOUT14                      GET_PIN(D, 13)
#define MCU_KOUT15                      GET_PIN(G, 2)
#define MCU_KOUT16                      GET_PIN(E, 12)




#define FAULT1                          GET_PIN(B, 0)
#define FAULT2                          GET_PIN(B, 1)
#define FAULT3                          GET_PIN(F, 12)

typedef enum  {
  Load_1_5kW_ON         = 1,
  Load_1_5kW_OFF,
  Load_3kW_ON,
  Load_3kW_OFF,
  Load_Reverse_ON,
  Load_Reverse_OFF,
  Load_Over_ON,
  Load_Over_OFF,
  Load_Short_Circuit_ON,
  Load_Short_Circuit_OFF,
  Load_Precharge_ON,
  Load_Precharge_OFF,
  Load_Main_ON,
  Load_Main_OFF,

  DC_Power_OFF,
  DC_Power_ON,

  Load_None_ON = 0x20,
  Load_None_OFF = 0x21,
  Undervoltage_ON = 0x22,
  Undervoltage_OFF = 0x23,
  Overvoltage_ON = 0x24,
  Overvoltage_OFF = 0x25,
  StartSig_ON = 0x26,
  StartSig_OFF = 0x27,
  Efficiency_ON = 0x28,
  Efficiency_OFF = 0x29,
  OverCurrent_ON = 0x30,
  OverCurrent_OFF = 0x31,
  StartTime_ON = 0x32,
  StartTime_OFF = 0x33,
  AllContactor_OFF = 0x34
} relaycmd;

extern rt_uint8_t sendBuf[10];
extern rt_uint8_t MesureType;

rt_uint8_t g_usb_cdc_sendData(rt_uint8_t* data,rt_uint8_t len);
rt_err_t g_usb_cdc_init(void);
void g_usb_IO_status_scan(void);
void g_usb_pin_control(relaycmd cmd);
void g_usb_control_softstart(rt_bool_t start);
void g_usb_set_timer(rt_bool_t sta);
void g_set_dpsp_vol(float volt);

#ifdef __cplusplus
}
#endif

#endif /* __AT_H__ */
