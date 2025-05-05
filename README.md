```markdown
# 🎮 Breakout Game (C++ / SFML)

這是一個使用 C++ 和 [SFML](https://www.sfml-dev.org/) 開發的經典打磚塊（Breakout）小遊戲。  
本專案適合學習遊戲開發、圖形程式設計、碰撞檢測與基本物理模擬。

---

## 🚀 遊戲玩法

- 控制底部板子左右移動，反彈小球擊碎上方磚塊。
- 小球打到磚塊會破壞磚塊並得分。
- 小球落到畫面底部則 Game Over。
- 打完所有磚塊即勝利。

---

## 📁 專案結構

```
breakout/
├── include/        # 標頭檔（class 定義）
├── src/            # 程式碼實作檔案
├── assets/         # 圖片、音效等素材
├── build/          # 編譯產物（不進 git）
├── main.cpp        # 程式進入點
├── CMakeLists.txt  # CMake 編譯設定
└── README.md       # 本文件
```

---

## 🛠️ 開發環境與建置方式

### 安裝 SFML

#### Ubuntu
```bash
sudo apt install libsfml-dev
```

#### macOS (Homebrew)
```bash
brew install sfml
```

---

### 編譯與執行（使用 CMake）

```bash
mkdir build
cd build
cmake ..
make
./Breakout
```

---

## ✅ 已完成功能（更新中 5/4）

- [x] 遊戲視窗與主迴圈
- [x] 玩家板子 Paddle 控制
- [x] 小球 Ball 移動
- [x] 碰撞邏輯：磚塊、牆、板子
- [ ] UI模組: 分數、生命、文字提示
- [ ] 遊戲結束/勝利畫面
- [ ] 額外關卡
- [ ] 音效、背景音樂
- [ ] 封裝部署


---

## 🧑‍💻 作者

由我自己練習 C++ 遊戲開發時手刻打造。  
如有興趣可以 fork 研究或給我建議！

```
