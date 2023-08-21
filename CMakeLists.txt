# 指定 cmake 最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT (VNCTP)

# 添加源文件列表
FILE(GLOB TD_SRC_LIST "${PROJECT_SOURCE_DIR}/src/vnctptd/*.cpp")
FILE(GLOB MD_SRC_LIST "${PROJECT_SOURCE_DIR}/src/vnctpmd/*.cpp")

# 指定头文件目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
# 附加python头文件, 请根据自己的miniconda安装路径修改
INCLUDE_DIRECTORIES(/usr/local/miniconda3/include/python3.11)

# 添加共享库搜索路径
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)
# 附加python共享库，请根据自己的miniconda安装路径修改
LINK_DIRECTORIES(/usr/local/miniconda3/libs)

# 指定输出动态库的目录位置
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/target)

# 指定生成动态库vnctpmd
ADD_LIBRARY(vnctpmd SHARED ${MD_SRC_LIST})
# 指定输出动态库扩展名，linux下是.so，windows下是.pyd
SET_TARGET_PROPERTIES(vnctpmd PROPERTIES SUFFIX ".so")
# 指定链接库
TARGET_LINK_LIBRARIES(vnctpmd thostmduserapi_se)

# 指定生成动态库vnctptd
ADD_LIBRARY(vnctptd SHARED ${TD_SRC_LIST})
# 指定输出动态库扩展名，linux下是.so，windows下是.pyd
SET_TARGET_PROPERTIES(vnctptd PROPERTIES SUFFIX ".so")
# 指定链接库
TARGET_LINK_LIBRARIES(vnctptd thosttraderapi_se)
