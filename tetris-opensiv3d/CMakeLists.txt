cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig)

project(
    tetris
    VERSION 0.0.0
    LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wno-unknown-pragmas -fPIC -msse4.1 -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -march=x86-64")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3 -Og -pg")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG -march=x86-64")


pkg_check_modules(OPENCV4 REQUIRED opencv4)
pkg_check_modules(XFT REQUIRED xft)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*)

include_directories(
  ${PROJECT_INCLUDE_DIR}

  "/usr/include"
  
  "/opt/OpenSiv3D/Siv3D/include"
  "/opt/OpenSiv3D/include/ThirdParty"
  ${XFT_INCLUDE_DIRS}
)

link_directories(
  "/usr/local/lib"
  "/usr/lib/x86_64-linux-gnu"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}.out
  ${PROJECT_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}.out
	${OPENCV4_LIBRARIES}
	${XFT_LIBRARIES}
	-lOpenGL
	-lGLEW
	-lX11
	-langelscript
	-lpthread
	-ldl
	-ludev
	-lfreetype
	-lharfbuzz
	-lglib-2.0
	-lgobject-2.0
	-lgio-2.0
	-lpng
	-lturbojpeg
	-lgif
	-lwebp
	-lopenal
	-logg
	-lvorbis
	-lvorbisenc
	-lvorbisfile
	-lboost_filesystem
	-lavformat
	-lavcodec
	-lavutil
	-lswresample
	-lXft

	/opt/OpenSiv3D/Linux/Build/libSiv3D.a
	/opt/angelscript/2.32.0/sdk/angelscript/lib/libangelscript.a
)
