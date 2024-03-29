cmake_minimum_required(VERSION 3.14)

project(homescreen VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Location DBus REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Location DBus REQUIRED)

set(DBUS_ADAPTER_UICONTROL_XML_FILES
    iappuicontrol.xml
    )

qt5_add_dbus_adaptor(ADAPTER_UICONTROL_SOURCES
    ${DBUS_ADAPTER_UICONTROL_XML_FILES}
    iappuicontrol.h
    IAppUIControl
    )

set(DBUS_INTERFACE_UICONTROL_XML_FILES
    iappmanageruicontrol.xml
    )

qt5_add_dbus_interface(INTERFACE_UICONTROL_SOURCES ${DBUS_INTERFACE_UICONTROL_XML_FILES} IAppManagerUIControl)

set(DBUS_INTERFACE_APPMODEL_XML_FILES
    iappmanagerappmodel.xml
    )

qt5_add_dbus_interface(INTERFACE_APPMODEL_SOURCES ${DBUS_INTERFACE_APPMODEL_XML_FILES} IAppManagerAppModel)

set(DBUS_INTERFACE_MEDIACONTROL_XML_FILES
    imediaplayercontrol.xml
    )

qt5_add_dbus_interface(INTERFACE_MEDIACONTROL_SOURCES ${DBUS_INTERFACE_MEDIACONTROL_XML_FILES} IMediaPlayerControl)

set(PROJECT_SOURCES
    main.cpp
    application.cpp
    application.h
    applicationmodel.cpp
    applicationmodel.h
    appuicontrol.cpp
    appuicontrol.h
    applicationbar.h
    applicationbar.cpp
    widgetbar.cpp
    widgetbar.h
    iwidget.h
    mediawidget.cpp
    mediawidget.h
    iappuicontrol.h
    iappuicontrolreceiver.h
    iappuicontrolreceiver.cpp
    appmanageruicontrol.cpp
    appmanageruicontrol.h
    appmanagerappmodel.cpp
    appmanagerappmodel.h
    mediaplayercontrol.cpp
    mediaplayercontrol.h
    qml.qrc
    ${ADAPTER_UICONTROL_SOURCES}
    ${INTERFACE_UICONTROL_SOURCES}
    ${INTERFACE_APPMODEL_SOURCES}
    ${INTERFACE_MEDIACONTROL_SOURCES}
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(homescreen
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        )
else()
    if(ANDROID)
        add_library(homescreen SHARED
            ${PROJECT_SOURCES}
            )
    else()
        add_executable(homescreen
            ${PROJECT_SOURCES}
            )
    endif()
endif()

target_compile_definitions(homescreen
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(homescreen
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Location Qt${QT_VERSION_MAJOR}::DBus)

set_target_properties(homescreen PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(homescreen)
    qt_finalize_executable(homescreen)
endif()
