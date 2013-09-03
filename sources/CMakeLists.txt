# set project name
project (plasma_applet_oblikue-strategies)

# find required Libaries
find_package (KDE4 REQUIRED)
include (KDE4Defaults)

add_definitions (${QT_DEFINITIONS} 
                 ${KDE4_DEFINITIONS})
include_directories (${CMAKE_SOURCE_DIR} 
                     ${CMAKE_BINARY_DIR} 
                     ${KDE4_INCLUDES})

# set sources
set (PLUGIN_NAME ${PROJECT_NAME})
file (GLOB PROJECT_DESKTOP *.desktop)
file (GLOB PROJECT_ICON *.png)
file (GLOB PROJECT_SRCS *.cpp)
file (GLOB PROJECT_UI *.ui)

# make
kde4_add_ui_files (PROJECT_SRCS ${PROJECT_UI})
kde4_add_plugin (${PLUGIN_NAME} ${PROJECT_SRCS})
target_link_libraries (${PLUGIN_NAME} ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS})

# install
install (TARGETS ${PLUGIN_NAME} DESTINATION ${PLUGIN_INSTALL_DIR})
install (FILES ${PROJECT_DESKTOP} DESTINATION ${SERVICES_INSTALL_DIR})
install (FILES ${PROJECT_ICON} DESTINATION ${ICON_INSTALL_DIR})
