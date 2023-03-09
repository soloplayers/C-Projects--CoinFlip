cmake_minimum_required(VERSION 3.5)

project(CoinFlip LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "D:/SDK_all_Items/Qt/Qt_5.14.2/5.14.2/mingw73_64")


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

find_package(Qt5 COMPONENTS
        Widgets
        Gui
        Core
        Sql
        Multimedia
        REQUIRED)
qt5_add_resources(SOURCES res.qrc) # *.qrc文件

if (ANDROID)
    add_library(CoinFlip SHARED
            main.cpp
            mainscene.cpp
            Mainwindow.h
            mainscene.ui
            ${SOURCES}
            xx.rc
            myWidgets/myPushButton/mypushbutton.cpp myWidgets/myPushButton/mypushbutton.h myWidgets/myPushButton/mypushbutton.ui myWidgets/ChooseLevelScene/chooselevelscene.cpp myWidgets/ChooseLevelScene/chooselevelscene.h myWidgets/ChooseLevelScene/chooselevelscene.ui myWidgets/playScene/playScene.cpp myWidgets/playScene/playScene.h myWidgets/playScene/playScene.ui myWidgets/myCoin/mycoin.cpp myWidgets/myCoin/mycoin.h myWidgets/myCoin/mycoin.ui myWidgets/dataConfig/dataconfig.cpp myWidgets/dataConfig/dataconfig.h
            )
else ()
    add_executable(CoinFlip
            WIN32
            main.cpp
            mainscene.cpp
            Mainwindow.h
            mainscene.ui
            ${SOURCES}
            xx.rc
            myWidgets/myPushButton/mypushbutton.cpp myWidgets/myPushButton/mypushbutton.h myWidgets/myPushButton/mypushbutton.ui myWidgets/ChooseLevelScene/chooselevelscene.cpp myWidgets/ChooseLevelScene/chooselevelscene.h myWidgets/ChooseLevelScene/chooselevelscene.ui myWidgets/playScene/playScene.cpp myWidgets/playScene/playScene.h myWidgets/playScene/playScene.ui myWidgets/myCoin/mycoin.cpp myWidgets/myCoin/mycoin.h myWidgets/myCoin/mycoin.ui myWidgets/dataConfig/dataconfig.cpp myWidgets/dataConfig/dataconfig.h
            )
endif ()

target_link_libraries(CoinFlip PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Multimedia
        )
