cmake_minimum_required(VERSION 3.15)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project( LightNodeEditor )

find_package(Qt5 COMPONENTS Quick  REQUIRED)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++-17")

set(SOURCES
	main.cpp
	nge/controller/nodegraphcontroller.cpp
	nge/controller/nodegraphcontroller.h
	nge/model/uinode.cpp
	nge/model/uinode.h
	nge/model/uinodemodel.cpp
	nge/model/uinodemodel.h
)

FILE(GLOB_RECURSE QML_SRC "*.qml")


add_executable(LightNodeEditor ${SOURCES} qml.qrc NodeGraphEditor.qrc ${QML_SRC})
target_include_directories(LightNodeEditor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(LightNodeEditor Qt5::Quick)


