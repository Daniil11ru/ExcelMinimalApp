cmake_minimum_required(VERSION 3.16)

project(ExcelMinimalApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

# start QXlsx
include(FetchContent)
FetchContent_Declare(
    QXlsx
    GIT_REPOSITORY https://github.com/QtExcel/QXlsx.git
    GIT_TAG fbf2c37e640ddaf86845dd610c5d5f86aa9ed52d
    SOURCE_SUBDIR QXlsx
)
FetchContent_MakeAvailable(QXlsx)
# end QXlsx

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appExcelMinimalApp
    main.cpp
)

qt_add_qml_module(appExcelMinimalApp
    URI ExcelMinimalApp
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES appcore.h appcore.cpp
    SOURCES excelhelper.cpp excelhelper.h
    SOURCES xlcell.cpp xlcell.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appExcelMinimalApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appExcelMinimalApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appExcelMinimalApp
    PRIVATE Qt6::Quick
    PRIVATE QXlsx::QXlsx
)

include(GNUInstallDirs)
install(TARGETS appExcelMinimalApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
