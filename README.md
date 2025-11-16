# STM32F407 开发板项目

基于 PlatformIO 和 Arduino 框架的 STM32F407VET6 开发板项目，使用 CMSIS-DAP 调试器进行开发和调试。

## 项目简介

简单的 LED 闪烁演示程序，展示如何使用 Arduino 框架结合 HAL 库开发 STM32F407：

- LED 闪烁（PB2 引脚，每 500ms 切换一次）
- 串口调试输出（115200 波特率）
- CMSIS-DAP 在线调试支持

## 硬件要求

- **开发板**: STM32F407VET6 Black F407VG
- **调试器**: CMSIS-DAP 调试器（DAPLink）
- **LED**: PB2 引脚（通过 2kΩ 电阻连接到 LED 再接地）
- **串口**: tx rx

## 开发环境

- **IDE**: Visual Studio Code + PlatformIO
- **框架**: Arduino Framework
- **调试/上传**: CMSIS-DAP (DAPLink)
- **平台**: STM32 (ststm32)

## 快速开始

### 1. 安装 PlatformIO

在 VS Code 中安装 PlatformIO IDE 扩展。

### 2. 克隆项目

```bash
git clone <repository-url>
cd stm32f407
```

### 3. 连接调试器

将 CMSIS-DAP 调试器连接到 STM32F407：

| CMSIS-DAP | STM32F407 |
|-----------|-----------|
| SWDIO     | SWDIO     |
| SWCLK     | SWCLK     |
| GND       | GND       |
| 3V3       | 3V3 (可选) |

### 4. 编译和上传

```bash
# 编译项目
pio run

# 上传固件
pio run --target upload

# 串口监视
pio device monitor
```

### 5. 调试

在 VS Code 中按 `F5` 即可开始调试，支持断点、单步执行等功能。

## 项目配置

### platformio.ini

```ini
[env:f407vg]
platform = ststm32
board = black_f407vg
framework = arduino
upload_protocol = cmsis-dap
debug_tool = cmsis-dap
build_type = debug
monitor_speed = 115200
```

### 引脚定义

| 功能 | 引脚 | 说明 |
|------|------|------|
| LED | PB2 | 高电平点亮（PB2 → LED → 2kΩ → GND） |
| 串口 | USB | USB CDC 串口，115200 波特率 |
| 调试 | SWDIO/SWCLK | SWD 调试接口 |

