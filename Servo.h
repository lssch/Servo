//
// Created by Lars Schwarz on 20.10.2023.
//

#ifndef STM32_SERVO_SERVO_H
#define STM32_SERVO_SERVO_H

#include "types/parameter/parameter.h"
#include "stm32f4xx_hal.h"

class Servo {
public:
  Servo(TIM_HandleTypeDef *htim_, uint8_t channel_, Parameter::Servo *parameter_);

  void move(int16_t angle);
private:
  TIM_HandleTypeDef *htim;
  uint8_t channel;
  Parameter::Servo *parameter;
};

#endif //STM32_SERVO_SERVO_H
