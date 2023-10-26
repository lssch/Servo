//
// Created by Lars Schwarz on 20.10.2023.
//

#ifndef STM32_SERVO_SERVO_H
#define STM32_SERVO_SERVO_H

#include "stm32f4xx_hal.h"
#include "types/parameter.h"

template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}

class Servo {
public:
  Servo(TIM_HandleTypeDef *htim_, uint8_t channel_, parameter_servo_t &parameter_);

  void move(float angle);
private:
  TIM_HandleTypeDef *htim;
  uint8_t channel;
  parameter_servo_t &parameter;
};

#endif //STM32_SERVO_SERVO_H
