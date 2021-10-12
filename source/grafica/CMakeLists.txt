set(GRAFICA_HEADERS 
		App.h
		CoreLayer/Input.h
		CoreLayer/Keycodes.h
		CoreLayer/Scene.h
		CoreLayer/Window.h
		)
set(GRAFICA_SOURCES
		App.cpp
		CoreLayer/Input.cpp
		CoreLayer/Scene.cpp
		CoreLayer/Window.cpp
		)

add_library(grafica STATIC ${GRAFICA_SOURCES} ${GRAFICA_HEADERS} grafica.h ${Shaders})
if (MSVC)
    target_compile_options(grafica PUBLIC /wd5033)
endif(MSVC)
target_include_directories(grafica PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} GRAFICA_INCLUDE_DIRECTORY)
target_link_libraries(grafica PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET grafica PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GRAFICA_SOURCES} ${GRAFICA_HEADERS})

