#include <Arduino.h>

// 定义 LED 引脚，根据教程是 PB2
// 在 STM32 Arduino 核心中，直接写 PB2 即可，系统会自动映射
#define MY_LED PB2
#define MY_KEY PA0

void setup() {
    Serial.begin(115200);
    // 1. 初始化引脚模式
    // 相当于配置 MODER, OTYPER, OSPEEDR 等寄存器
    pinMode(MY_LED, OUTPUT);
}

void loop() {
    // 2. 点亮 LED (输出高电平)
    // 相当于操作 ODR 或 BSRR 寄存器
    digitalWrite(MY_LED, HIGH);
    Serial.println("Hello PlatformIO! count: " + String(millis()));
    delay(2000);
    
    // 3. 熄灭 LED (输出低电平)
    digitalWrite(MY_LED, LOW);
    
    // 延时 500 毫秒
    delay(500);
}