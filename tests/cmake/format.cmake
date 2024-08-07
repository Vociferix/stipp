set(_FMT_TAGS)
set(_FMT_TAGS_DIR "${PROJECT_BINARY_DIR}/_fmt")

find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    foreach(_CXX_FILE "${PROJECT_SOURCE_DIR}/../stipp.hpp" "${PROJECT_SOURCE_DIR}/tests.cpp")
        get_filename_component(_FMT_TAG_NAME "${_CXX_FILE}" NAME)
        set(_FMT_TAG "${_FMT_TAGS_DIR}/${_FMT_TAG_NAME}.tag")
        add_custom_command(
            OUTPUT "${_FMT_TAG}"
            DEPENDS "${_CXX_FILE}"
                    "${PROJECT_SOURCE_DIR}/../.clang-format"
            COMMAND "${CLANG_FORMAT}" -style=file -i "${_CXX_FILE}"
            COMMAND "${CMAKE_COMMAND}" -E make_directory "${_FMT_TAGS_DIR}"
            COMMAND "${CMAKE_COMMAND}" -E touch "${_FMT_TAG}"
            COMMENT "clang-format ${_FMT_TAG_NAME}")
        list(APPEND _FMT_TAGS "${_FMT_TAG}")
    endforeach()
endif()

find_program(CMAKE_FORMAT cmake-format)
if(CMAKE_FORMAT)
    file(
        GLOB_RECURSE _CMAKE_FILES
        RELATIVE "${PROJECT_SOURCE_DIR}"
        "${PROJECT_SOURCE_DIR}/cmake/*.cmake" "${PROJECT_SOURCE_DIR}/tests/*CMakeLists.txt")
    list(APPEND _CMAKE_FILES "CMakeLists.txt")

    foreach(_CMAKE_FILE ${_CMAKE_FILES})
        set(_FMT_TAG "${_FMT_TAGS_DIR}/${_CMAKE_FILE}.tag")
        get_filename_component(_FMT_TAG_DIR "${_FMT_TAG}" DIRECTORY)
        add_custom_command(
            OUTPUT "${_FMT_TAG}"
            DEPENDS "${PROJECT_SOURCE_DIR}/${_CMAKE_FILE}"
                    "${PROJECT_SOURCE_DIR}/.cmake-format"
            COMMAND "${CMAKE_FORMAT}" -c "${PROJECT_SOURCE_DIR}/.cmake-format" -i
                    "${PROJECT_SOURCE_DIR}/${_CMAKE_FILE}"
            COMMAND "${CMAKE_COMMAND}" -E make_directory "${_FMT_TAG_DIR}"
            COMMAND "${CMAKE_COMMAND}" -E touch "${_FMT_TAG}"
            COMMENT "cmake-format ${_CMAKE_FILE}")
        list(APPEND _FMT_TAGS "${_FMT_TAG}")
    endforeach()
endif()

if(_FMT_TAGS)
    add_custom_target(format DEPENDS ${_FMT_TAGS})
endif()
