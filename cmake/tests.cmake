include(CMakeParseArguments)

function(create_test target_name)
    set(options)
    set(single_value_args FILE OUTPUT_DIR NAME)
    set(multi_value_args LINK_LIBS)
    
    cmake_parse_arguments(
        create_test
        "${options}"
        "${single_value_args}"
        "${multi_value_args}"
        ${ARGN}
    )
    
    if (DEFINED create_test_OUTPUT_DIR)
        set(
            output_dir
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests/${create_test_OUTPUT_DIR}
        )
    else()
        set(output_dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tests)
    endif()
    
    if (DEFINED create_test_NAME)
        set(test_name ${create_test_NAME})
    else()
        set(test_name ${target_name})
    endif()
    
    add_executable(${target_name} ${create_test_FILE})
    target_link_libraries(${target_name} ${create_test_LINK_LIBS})
    add_test(NAME ${test_name} COMMAND ${target_name})
    set_target_properties(
        ${target_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${output_dir}
    )
endfunction()
