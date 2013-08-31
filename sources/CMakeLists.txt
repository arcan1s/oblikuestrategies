# Project Needs a name ofcourse
project (plasma-oblikue-strategies)
 
# Find the required Libaries
find_package (KDE4 REQUIRED)
include (KDE4Defaults)
 
add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories (${CMAKE_SOURCE_DIR}
                     ${CMAKE_BINARY_DIR}
                     ${KDE4_INCLUDES})
 
# We add our source code here
set (PROJECT_SRCS oblikue-strategies.cpp)
set (PROJECT_UI configwindow.ui)
set (PROJECT_DESKTOP plasma-applet-oblikue-strategies.desktop)
set (PROJECT_ICON oblikue-strategies.png)
set (PLUGIN_NAME plasma_applet_oblikue-strategies)
 
# Now make sure all files get to the right place
kde4_add_ui_files (PROJECT_SRCS ${PROJECT_UI})
kde4_add_plugin (${PLUGIN_NAME} ${PROJECT_SRCS})
target_link_libraries (${PLUGIN_NAME} ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS})
 
install (TARGETS ${PLUGIN_NAME} DESTINATION ${PLUGIN_INSTALL_DIR})
 
install (FILES ${PROJECT_DESKTOP} DESTINATION ${SERVICES_INSTALL_DIR})

install(FILES ${PROJECT_ICON} DESTINATION share/pixmaps/)
