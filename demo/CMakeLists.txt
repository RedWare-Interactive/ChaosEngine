add_executable(demo demo.cpp)

target_link_libraries(demo PRIVATE ChCore)
target_include_directories(demo PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(demo PROPERTIES
	BUILD_WITH_INSTALL_RPATH TRUE
	INSTALL_RPATH "$ORIGIN/lib:$ORIGIN/.."
)
