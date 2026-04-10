# 🎯 OpenCV Face Detection (C++)

A real-time face detection application built using **C++** and **OpenCV**, supporting both image and webcam input. This project demonstrates computer vision fundamentals such as image preprocessing, object detection, and real-time video processing.

---

## 🚀 Features

* Detect faces in static images
* Real-time face detection using webcam
* Draw bounding boxes around detected faces
* Display face count on screen
* Save webcam snapshots with a key press (`s`)
* Built using **CMake + MSVC + VS Code**

---

## 🖥️ Demo

### 📸 Image Detection

* Loads an image and detects faces

### 🎥 Webcam Detection

* Live camera feed with real-time face detection

**Controls:**

* `s` → Save snapshot
* `q` or `ESC` → Quit

---

## 📂 Project Structure

```
opencv-face-detection/
├── CMakeLists.txt
├── README.md
├── data/
│   └── haarcascade_frontalface_default.xml
├── images/
│   └── test.jpg
├── src/
│   └── main.cpp
├── snapshots/
└── .vscode/
```

---

## 🛠️ Requirements

* Windows 10/11
* Visual Studio Build Tools (MSVC)
* CMake (>= 3.15)
* OpenCV (prebuilt for Windows)
* VS Code with extensions:

  * C/C++
  * CMake Tools

---

## ⚙️ Setup Instructions

### 1️⃣ Install OpenCV

Download OpenCV from:
https://opencv.org/releases/

Extract to:

```
C:\opencv
```

Ensure the following exists:

```
C:\opencv\build
```

---

### 2️⃣ Update OpenCV path

Edit `CMakeLists.txt`:

```cmake
set(OpenCV_DIR "C:/opencv/build")
```

---

### 3️⃣ Build the project

Open terminal in VS Code:

```bash
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

---

### 4️⃣ Run the application

```bash
build\Release\face_detection.exe
```

---

## ⚠️ Important (Windows DLL issue)

If you see this error:

```
opencv_worldXXX.dll not found
```

Fix by adding OpenCV to PATH:

```
C:\opencv\build\x64\vc17\bin
```

---

## 🎮 Controls

| Key         | Action           |
| ----------- | ---------------- |
| `1`         | Image detection  |
| `2`         | Webcam detection |
| `s`         | Save snapshot    |
| `q` / `ESC` | Quit             |

---

## 🧠 How It Works

1. Capture image or webcam frame
2. Convert to grayscale
3. Apply histogram equalization
4. Run Haar Cascade classifier
5. Detect faces using multi-scale detection
6. Draw bounding boxes and display results

---

## 📈 Future Improvements

* Eye detection
* Face blurring (privacy filter)
* FPS (performance) counter
* DNN-based face detection (more accurate)
* Face recognition system

---

## 🧑‍💻 Author

* Trung Le

---

## 💼 Resume Description

**Real-Time Face Detection System Using C++ and OpenCV**

* Developed a real-time face detection application using C++ and OpenCV.
* Implemented grayscale preprocessing and Haar Cascade-based detection.
* Built webcam streaming pipeline with face counting and snapshot capture.
* Structured project using CMake for scalable and maintainable builds.

---

## 📜 License

MIT License

---

## ⭐ Optional Enhancements

### Add screenshots

Create folder:

```
assets/
```

Add images:

```
assets/demo1.png
assets/demo2.png
```

Update README:

```md
## 🖼️ Screenshots

![Image Mode](assets/demo1.png)
![Webcam Mode](assets/demo2.png)
```

---

### Add badges

```md
![C++](https://img.shields.io/badge/C++-17-blue)
![OpenCV](https://img.shields.io/badge/OpenCV-4.x-green)
```

---

## 🚀 Summary

This project demonstrates:

* C++ proficiency
* OpenCV usage
* Real-time video processing
* Clean project structure with CMake

It is a strong portfolio project for roles involving:

* Computer Vision
* Embedded Systems
* Camera Software Engineering
* Robotics / AI

---
