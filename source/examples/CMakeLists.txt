function(MakeExample TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER examples)
	target_link_libraries(${TARGETNAME} PRIVATE grafica)
	target_include_directories(${TARGETNAME} PRIVATE ${GRAFICA_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})

endfunction(MakeExample)

MakeExample(test_input_1 test_input_1.cpp)
MakeExample(test_input_2 test_input_2.cpp)
MakeExample(test_time_1 test_time_1.cpp)
MakeExample(test_time_2 test_time_2.cpp)