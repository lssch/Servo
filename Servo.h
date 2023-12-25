//
// Created by Lars Schwarz on 20.10.2023.
//

#ifndef STM32_SERVO_SERVO_H
#define STM32_SERVO_SERVO_H

#include "types/parameter.h"
#include "stm32f4xx_hal.h"

class Servo {
public:
  /// @brief Servo object
  /// @param htim Timer witch is connected to the output.
  /// @param channel Channel witch is connected to to the output.
  /// @param parameter Parameters witch contains the information about the hardware implementation of the Servo
  Servo(TIM_HandleTypeDef &htim, const uint8_t channel, const Parameter::Servo &parameter);

  /// @brief Move the servo based on an angle in centi degrees for better resolution.
  /// @param angle Steering angle in centi degrees
  void move(const int16_t angle);
private:
  TIM_HandleTypeDef &_htim;
  const uint8_t _channel;
  const Parameter::Servo &_parameter;
};

#endif //STM32_SERVO_SERVO_H
