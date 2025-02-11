 * @file README.md
 * @author xm (xmain90@163.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-11
 * @copyright Copyright (c) 2025


# 👁️ PostureGuard - 坐姿守护者

🚀 笔记本智能坐姿监测系统(Intelligent posture monitoring system based on Laptop) 



## 🌟 核心功能

🖥️ **实时面部检测**  
- 使用300x300 SSD人脸检测模型
- 支持动态校准基准距离

📏 **智能距离计算**  
- 基于面部宽度的比例判断
- 自适应阈值检测（默认1.1倍基准值）

🔔 **健康提醒系统**  
- 自动弹出警告窗口（2秒后消失）
- 非阻塞式消息提示



## 📦 环境依赖（系统： ubnutu20.04）

✅ **必需组件**  
- OpenCV 4.x+ 
- C++17编译器
- CMake 3.10+
- Zenity弹窗工具

✅ **预训练模型**  
- Caffe人脸检测模型（自动下载脚本见编译步骤）

---

## 📂 项目结构
```
PostureGuard/
├── models/               # 模型配置文件
├── resources/            # 预训练模型权重
├── include/              # 头文件集合
├── src/                 # 源代码实现
└── build/               # 编译输出目录
```



## 🔧 编译指南

### 1：准备环境
```bash
# 安装核心依赖
sudo apt-get update && sudo apt-get install -y \
    build-essential cmake libopencv-dev zenity
```

### 2：编译项目
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./PostureGuard
```


---

## 🕹️ 使用方法

🖱️ **操作指引**  
1. 按 `C` 键：校准标准坐姿（需正对摄像头）
2. 按 `Q` 键：安全退出程序
3. 自动检测：当面部距离过近时触发提醒

🔧 **参数调整**  
- 修改 `FaceDetector.cpp` 中的 `confidenceThreshold` 调整检测灵敏度
- 修改 `AlertSystem.cpp` 中的 `--timeout` 值改变弹窗持续时间

---


### ⚠️ 注意事项
- 确保摄像头权限正确：`sudo chmod 777 /dev/video0`
- 模型文件路径需保持原始目录结构
- 本项目会调用笔记本摄像头来检测面部距离，但是并不会侵犯使用者的任何隐私，因为这完全是本地运行的，不会上传任何数据。

 
