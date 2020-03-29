cmake_minimum_required (VERSION 3.0)

find_package(PkgConfig)

project(test CXX)
enable_language(C)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wno-unknown-pragmas -fPIC -msse4.1 -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -march=x86-64")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3 -Og -pg")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG -march=x86-64")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_compile_options ("-fcolor-diagnostics")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	add_compile_options ("-fdiagnostics-color=always")
endif()

#set(CMAKE_BUILD_TYPE Release)

pkg_check_modules(OPENCV4 REQUIRED opencv4)
pkg_check_modules(XFT REQUIRED xft)

include_directories(
  "/usr/include"
  
  "/opt/OpenSiv3D/Siv3D/include"
  "/opt/OpenSiv3D/include/ThirdParty"
  ${XFT_INCLUDE_DIRS}
)

link_directories(
  "/usr/local/lib"
  "/usr/lib/x86_64-linux-gnu"
)


set(SOURCE_FILES
	"./Main.cpp"
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
add_executable(${PROJECT_NAME}.out ${SOURCE_FILES})

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

