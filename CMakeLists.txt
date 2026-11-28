cmake_minimum_required(VERSION 4.4.3)

# https://github.com/Kitware/CMake/blob/v4.4.3/Help/dev/experimental.rst
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
set(CMAKE_CXX_MODULE_STD ON)
function(_add_executable target)
    add_executable(${target})
endfunction()

<<<<<<< HEAD
project(hw-modules VERSION 0.1 LANGUAGES CXX)

_add_executable(hw-modules)

target_compile_features(hw-modules PRIVATE cxx_std_23)

# C++ Modules support
target_sources(hw-modules
    PRIVATE
        main.cpp


    PRIVATE FILE_SET modules TYPE CXX_MODULES BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        cg.data.cppm
        cg.input.cppm




=======
project(module VERSION 0.1 LANGUAGES CXX)

_add_executable(module)

target_compile_features(module PRIVATE cxx_std_23)

# C++ Modules support
target_sources(module
    PRIVATE
        main.cpp
        input.cpp
    PRIVATE FILE_SET modules TYPE CXX_MODULES BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
        coursegrade.cppm
        input.cppm
>>>>>>> origin/ours

)

# Deployment settings
include(GNUInstallDirs)
<<<<<<< HEAD
set(CMAKE_INSTALL_PREFIX "/opt/hw-modules" CACHE PATH "Install path prefix" FORCE)
install(TARGETS hw-modules
=======
set(CMAKE_INSTALL_PREFIX "/opt/module" CACHE PATH "Install path prefix" FORCE)
install(TARGETS module
>>>>>>> origin/ours
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)























































#https://github.com/Kitware/CMake/blob/v4.2.3/Help/dev/experimental.rst
<<<<<<< HEAD
#####  下面的配置，让hw-modules链接部署到/opt/lib下面的libutils  #####
#target_include_directories(hw-modules PRIVATE /opt/include)  # -I /opt/utils/include 自定义头文件搜索路径
# target_link_directories(hw-modules PRIVATE /opt/utils/lib)  # -L /opt/utils/lib 设置链接路径
# target_link_libraries(hw-modules PRIVATE utils)             # -lutils           设置链接库名

# set_target_properties(hw-modules PROPERTIES
#     INSTALL_RPATH_USE_LINK_PATH  True                           # 使用链接路径作为安装文件的RPath，等价于"-Wl,-rpath=/opt/utils/lib"
# )

#add_library(hw-modules SHARED
#  utils.cpp
#)

#set_target_properties( hw-modules PROPERTIES
=======
#####  下面的配置，让module链接部署到/opt/lib下面的libutils  #####
#target_include_directories(module PRIVATE /opt/include)  # -I /opt/utils/include 自定义头文件搜索路径
# target_link_directories(module PRIVATE /opt/utils/lib)  # -L /opt/utils/lib 设置链接路径
# target_link_libraries(module PRIVATE utils)             # -lutils           设置链接库名

# set_target_properties(module PROPERTIES
#     INSTALL_RPATH_USE_LINK_PATH  True                           # 使用链接路径作为安装文件的RPath，等价于"-Wl,-rpath=/opt/utils/lib"
# )

#add_library(module SHARED
#  utils.cpp
#)

#set_target_properties( module PROPERTIES
>>>>>>> origin/ours
#    PUBLIC_HEADER utils.cppm
#    VERSION   2.5.1
#    SOVERSION 2
#    LIBRARY_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/lib"
#)

<<<<<<< HEAD
#install(TARGETS hw-modules
=======
#install(TARGETS module
>>>>>>> origin/ours
#    LIBRARY DESTINATION /opt/utils/lib
#    PUBLIC_HEADER DESTINATION  /opt/utils/modules
#)

<<<<<<< HEAD
#add_custom_command(TARGET hw-modules
=======
#add_custom_command(TARGET module
>>>>>>> origin/ours
#    POST_BUILD
#    COMMAND cmake --install "${CMAKE_CURRENT_BINARY_DIR}"
#)

# set(MODULE_LIB_DIR /opt/utils/)  # 模块库目录的设置
<<<<<<< HEAD
# set(HW-MODULES_MODULE_FILES
#     ${MODULE_LIB_DIR}/utils.cppm          # 模块库的模块文件
#     math.cppm                             # 模块文件
# )
# source_group("hw-modules" FILES ${HW-MODULES_MODULE_FILES})
#
# target_sources(hw-modules
=======
# set(MODULE_MODULE_FILES
#     ${MODULE_LIB_DIR}/utils.cppm          # 模块库的模块文件
#     math.cppm                             # 模块文件
# )
# source_group("module" FILES ${MODULE_MODULE_FILES})
#
# target_sources(module
>>>>>>> origin/ours
#     PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
#         BASE_DIRS   # 配置BASE_DIRS，用于组织构建输出目录，以便构建不同目录中(同名的)模块文件.
#             ${MODULE_LIB_DIR}
#             ${CMAKE_CURRENT_SOURCE_DIR}
#         FILES
<<<<<<< HEAD
#             ${HW-MODULES_MODULE_FILES}
=======
#             ${MODULE_MODULE_FILES}
>>>>>>> origin/ours
# )
