//
// Created by Lars Schwarz on 20.10.2023.
//

#include "Servo.h"


Servo::Servo(TIM_HandleTypeDef *htim_, uint8_t channel_) {
  htim = htim_;
  channel = channel_;
}

