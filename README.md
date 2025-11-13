# STM32F407 Demo Project

基于 PlatformIO 和 Arduino 框架的 STM32F407VET6 开发板演示项目。

## 📋 项目简介

这是一个简单的 STM32F407 演示程序，实现以下功能：

- LED 闪烁（每秒切换一次）
- ADC 模拟量读取（PA0 引脚）
- 串口输出调试信息
- 串口接收命令

## 🔧 硬件要求

- **开发板**: STM32F407VET6（Black F407 或类似开发板）
- **LED**: PC13（板载 LED）
- **ADC 输入**: PA0
- **串口**: USB CDC（通过 USB 连接）

## 🛠️ 开发环境

- **IDE**: Visual Studio Code + PlatformIO
- **框架**: Arduino Framework
- **上传方式**: DFU (USB)

## 📦 安装步骤

### 1. 安装依赖工具

```bash
# 在 VS Code 中安装 PlatformIO IDE 扩展
```

### 2. 安装 DFU 工具

项目使用 DFU (Device Firmware Update) 通过 USB 上传固件。

**Windows 用户（使用 Scoop）：**

```powershell
scoop install dfu-util
```

**或手动下载：**

- 从 [dfu-util 官网](http://dfu-util.sourceforge.net/) 下载
- 修改 `platformio.ini` 中的 `dfu-util.exe` 路径

### 3. 安装 DFU 驱动（Windows 必需）

**重要：Windows 系统必须使用 Zadig 安装 USB 驱动，否则无法识别 DFU 设备！**

1. 下载 [Zadig](https://zadig.akeo.ie/)
2. 将 STM32 进入 DFU 模式（按住 BOOT0 + 按 RESET）
3. 运行 Zadig，在菜单中选择 `Options` -> `List All Devices`
4. 在设备列表中选择 `STM32 BOOTLOADER` 或 `DFU in FS Mode`（设备 ID: 0483:DF11）
5. 在驱动类型下拉框中选择 `WinUSB` 或 `libusbK`
6. 点击 `Install Driver` 或 `Replace Driver` 按钮
7. 等待安装完成

**验证驱动安装：**

```bash
dfu-util -l
```

应该能看到类似输出：

```text
Found DFU: [0483:df11] ver=2200, devnum=X, cfg=1, intf=0, path="X-X", alt=0, name="@Internal Flash  /0x08000000/04*016Kg,01*064Kg,07*128Kg", serial="XXXXXXXXXXXX"
```

### 4. 克隆项目

```bash
git clone <repository-url>
cd stm32f407
```

## 🚀 使用方法

### 编译项目

```bash
pio run
```

### 上传固件（DFU 模式）

**重要：上传前需要进入 DFU 模式**

1. **进入 DFU 模式**：
   - 按住 BOOT0 按钮
   - 按一下 RESET 按钮
   - 松开 BOOT0 按钮
   - 此时开发板进入 DFU 模式

2. **验证 DFU 设备**：
   ```bash
   dfu-util -l
   ```
   应该能看到 `0483:df11` 设备

3. **上传固件**：
   ```bash
   pio run --target upload
   ```

4. **退出 DFU 模式**：
   - 按一下 RESET 按钮
   - 程序开始运行

### 监视串口输出

使用 PlatformIO 内置串口监视器：
```bash
pio device monitor
```

或使用项目提供的 Python 脚本：
```bash
python monitor.py
```

## 📝 配置说明

### platformio.ini 配置

```ini
[env:genericSTM32F407VET6]
platform = ststm32
board = genericSTM32F407VET6
framework = arduino
upload_protocol = dfu              ; 使用 DFU 上传
monitor_speed = 115200             ; 串口波特率
build_flags = 
    -D PIO_FRAMEWORK_ARDUINO_ENABLE_CDC   ; 启用 USB CDC
    -D USBCON
```

### 引脚定义

| 功能 | 引脚 | 说明 |
|------|------|------|
| LED | PC13 | 板载 LED，低电平点亮 |
| ADC | PA0 | 模拟输入，0-3.3V |
| USB | PA11/PA12 | USB CDC 串口 |

## 📊 串口输出示例

```
STM32F407 Ready
Setup OK
LED: ON  | ADC: 2048
LED: OFF | ADC: 2051
LED: ON  | ADC: 2045
```

## 🔍 故障排除

### 问题 1: 无法进入 DFU 模式

**解决方案**：
- 确认 BOOT0 跳线帽设置正确
- 尝试多次按 BOOT0 + RESET 组合
- 检查 USB 线缆质量（建议使用数据线而非充电线）


### 问题 2: 同样的固件无法烧录第二次

**原因**：`dfu-suffix` 会从文件中删除后缀，导致第二次上传失败。

**解决方案**：
- 每次上传前重新编译：`pio run`
- 或者修改 `upload_command` 先复制文件


## 📚 参考资料

- [PlatformIO 文档](https://docs.platformio.org/)
- [STM32duino Wiki](https://github.com/stm32duino/wiki/wiki)
- [DFU-Util 使用指南](http://dfu-util.sourceforge.net/)
- [STM32F407 数据手册](https://www.st.com/resource/en/datasheet/stm32f407vg.pdf)

## 📄 许可证

MIT License

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

## 📧 联系方式

如有问题，请提交 Issue。
