//
// Created by Lars Schwarz on 20.10.2023.
//

#include "Servo.h"

Servo::Servo(TIM_HandleTypeDef &htim, const uint8_t channel, const Parameter::Servo &parameter)
  : _htim(htim),
    _channel(channel),
    _parameter(parameter) {
}

void Servo::move(const int16_t angle) {
  // servo limits _parameter.max_steering_angle
  // offset _parameter.zero_position
  // mechanical limits _parameter.steering_limits

  float scale = (static_cast<float>(angle)+static_cast<float>(_parameter.zero_position))/static_cast<float>(_parameter.max_steering_angle) + 1.5f;

  _htim.Instance->CCR1 = static_cast<uint32_t>(static_cast<float>(_htim.Instance->ARR) * scale/20);
  HAL_TIM_PWM_Start(&_htim, _channel);
}