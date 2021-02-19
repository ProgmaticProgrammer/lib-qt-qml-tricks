cmake_minimum_required(VERSION 3.5)

project(NiceModels LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick Svg REQUIRED)

file(GLOB HEADERS
    ../../src/*.h
)
file(GLOB SOURCES
    ../../src/*.cpp
)

if(ANDROID)
    add_library(NiceModels SHARED
      defs_nicemodels.h
      main_nicemodels.cpp
      data_nicemodels.qrc
    )
else()
    add_executable(NiceModels
      ${HEADERS}
      ${SOURCES}
      defs_nicemodels.h
      main_nicemodels.cpp
      data_nicemodels.qrc
    )
endif()

list(APPEND QML_DIRS ${CMAKE_SOURCE_DIR}/../../import)
set(QML_IMPORT_PATH ${QML_DIRS} CACHE STRING "Qt Creator 4.1 extra qml import paths")

target_include_directories(NiceModels PUBLIC "../../include")

target_compile_definitions(NiceModels
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(NiceModels
  PRIVATE Qt5::Core Qt5::Quick Qt5::Svg)
