//
// Created by Lars Schwarz on 20.10.2023.
//

#ifndef STM32_SERVO_SERVO_H
#define STM32_SERVO_SERVO_H

#include "stm32f4xx_hal.h"

class Servo {
public:
  Servo(TIM_HandleTypeDef *htim_, uint8_t channel_, uint8_t min_angle, uint8_t max_angle);
  void angle(float steering_angle);
private:
  TIM_HandleTypeDef *htim;
  uint8_t channel;
  struct {
    uint8_t min_angle;
    uint8_t max_angle;
  } steering_limits;
};

#endif //STM32_SERVO_SERVO_H
