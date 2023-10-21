//
// Created by Lars Schwarz on 20.10.2023.
//

#include "Servo.h"
#include "limits.h"
#include <iostream>


Servo::Servo(TIM_HandleTypeDef *htim_, uint8_t channel_, uint8_t min_angle, uint8_t max_angle) {
  htim = htim_;
  channel = channel_;
  steering_limits.min_angle = min_angle;
  steering_limits.max_angle = max_angle;
}

void Servo::angle(float steering_angle) {
  htim->Instance->CCR1 = (steering_angle/1000 + 1) * htim->Instance->ARR/20;
  std::cout << "CCR1: " << htim->Instance->CCR1 << std::endl;
  HAL_TIM_PWM_Start(htim, channel);
}