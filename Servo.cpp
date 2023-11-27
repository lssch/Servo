//
// Created by Lars Schwarz on 20.10.2023.
//

#include "Servo.h"

Servo::Servo(TIM_HandleTypeDef *htim_, uint8_t channel_, Parameter::Servo *parameter_):
  htim(htim_),
  channel(channel_),
  parameter(parameter_) {
}

void Servo::move(float angle) {
  float scale;

  // servo limits parameter.max_steering_angle
  // offset parameter.zero_position
  // mechanical limits parameter.steering_limits

  // TODO: Needs to be tested
  // Linear mapping between [0.5, 2.5] based on the provided parameters and steering angle
  scale = static_cast<float>((angle+static_cast<float>(parameter->zero_position))/static_cast<float>(parameter->max_steering_angle) + 1.5f);

  htim->Instance->CCR1 = static_cast<uint32_t>(static_cast<float>(htim->Instance->ARR) * scale/20);
  HAL_TIM_PWM_Start(htim, channel);
}