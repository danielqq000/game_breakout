cmake_minimum_required(VERSION 3.10)

# 專案名稱
project(Game_Breakout)

# C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 搜尋 SFML 套件（找 graphics、window、system 三個模組）
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# 包含頭檔資料夾
include_directories(include)

# 自動抓取所有 cpp 檔案

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "main.cpp")

message(STATUS "All cpp sources found:")
foreach(source_file IN LISTS SOURCES)
    message(STATUS "  ${source_file}")
endforeach()

# 建立可執行檔
add_executable(Breakout ${SOURCES})

# 連結 SFML 函式庫
target_link_libraries(Breakout sfml-graphics sfml-window sfml-system)
