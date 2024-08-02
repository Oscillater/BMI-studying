cmake_minimum_required(VERSION 3.5)

project(change_to_customplot VERSION 0.1 LANGUAGES CXX)

# 设置C++标准和要求
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加编译器标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wa,-mbig-obj -O2")

# 查找Qt6组件
find_package(Qt6 COMPONENTS Widgets Core Gui Charts PrintSupport REQUIRED)

# 启用Qt的自动处理
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置项目源文件
set(PROJECT_SOURCES main.cpp mainwindow.cpp mainwindow.ui)

# 添加QCustomPlot库
add_subdirectory(QCustomPlot-library)

# 添加可执行文件
add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    work.h
    work.cpp
    data.txt
)

# 链接Qt6库和QCustomPlot库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core Qt6::Charts Qt6::PrintSupport qcustomplot)

# 设置目标属性
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# 设置目标包含目录
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 安装目标
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION .
)

# 为QCustomPlot设置编译定义
target_compile_definitions(${PROJECT_NAME} PRIVATE QCUSTOMPLOT_USE_LIBRARY)
