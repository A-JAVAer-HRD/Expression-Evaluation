cmake_minimum_required(VERSION 3.16)

# 注意这里要改为自己的项目名
project(DataStructDesigon)

set(CMAKE_CXX_STANDARD 14)

# 遍历项目目录下所有的 .cpp 文件 两层
#一层
# file (GLOB files test/*.cpp)
#两层
# file (GLOB files *.cpp */*.cpp)
# 同理，三层的话
# file (GLOB files *.cpp */*.cpp */*/*.cpp)

file (GLOB files *.cpp */*.cpp) # 这一行是遍历的
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} text2.cpp test3.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

