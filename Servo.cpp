//
// Created by Lars Schwarz on 20.10.2023.
//

#include "Servo.h"
#include <iostream>

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

  // TODO: Needs to be tested
  // Linear mapping between [0.5, 2.5] based on the provided parameters and steering angle
  scale = static_cast<float>((angle+static_cast<float>(parameter.zero_position))/static_cast<float>(parameter.max_steering_angle) + 1.5f);

  htim->Instance->CCR1 = static_cast<uint32_t>(static_cast<float>(htim->Instance->ARR) * scale/20);
  HAL_TIM_PWM_Start(htim, channel);
}