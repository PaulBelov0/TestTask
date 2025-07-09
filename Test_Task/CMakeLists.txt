cmake_minimum_required(VERSION 3.19)
project(Test_Task LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Test_Task
    WIN32 MACOSX_BUNDLE
    main.cpp
    main_window.cpp
    main_window.h
    ui/models/tree_item_model.h ui/models/tree_item_model.cpp
)

target_link_libraries(Test_Task
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Test_Task
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Test_Task
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
