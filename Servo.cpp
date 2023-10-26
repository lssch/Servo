//
// Created by Lars Schwarz on 20.10.2023.
//

#include "Servo.h"
#include <iostream>


Servo::Servo(TIM_HandleTypeDef *htim_, uint8_t channel_, parameter_servo_t &parameter_):
  htim(htim_),
  channel(channel_),
  parameter(parameter_) {
}


void Servo::move(float angle) {
  float scale;

  // servo limits parameter.max_steering_angle
  // offset parameter.zero_position
  // mechanical limits parameter.steering_limits

  if (std::abs(angle+parameter.zero_position) <= parameter.max_steering_angle)
    // Linear mapping based on the provided parameters
    scale = (angle+parameter.zero_position)/(parameter.max_steering_angle) + 1.5;
  else
    // Full positive/negative steering angle based on the provided parameters
    scale = (sgn(angle)*parameter.steering_limits)/(parameter.max_steering_angle) + 1.5;

  htim->Instance->CCR1 = scale * htim->Instance->ARR/20;
  HAL_TIM_PWM_Start(htim, channel);
}