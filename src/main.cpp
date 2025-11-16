#include <Arduino.h>
#include "stm32f4xx_hal.h"

void setup() {
  Serial.begin(115200);        // 打开 USB CDC
  delay(50);                   // 给枚举一点时间

  __HAL_RCC_GPIOB_CLK_ENABLE();
  GPIO_InitTypeDef i = {0};
  i.Pin = GPIO_PIN_2;
  i.Mode = GPIO_MODE_OUTPUT_PP;
  i.Pull = GPIO_NOPULL;
  i.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &i);
}

void loop() {
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);   // 亮（PB2→LED→2k→GND）
  Serial.println("LED=ON");
  delay(500);

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET); // 灭
  Serial.println("LED=OFF");
  delay(500);
}
