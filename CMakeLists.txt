cmake_minimum_required(VERSION 3.22)
project(frama_c_input_invariant C)

set(CMAKE_C_STANDARD 11)

find_program(AFL_CLANG_FAST afl-clang-fast)
if(NOT AFL_CLANG_FAST)
    message(FATAL_ERROR "afl-clang-fast not found.")
endif()

function(add_afl_instrumentation PROG)
    set(INSTR_NAME "${PROG}_instr")

    add_custom_command(
            OUTPUT ${PROG}_instr
            COMMAND "${AFL_CLANG_FAST}"
            ${CMAKE_CURRENT_SOURCE_DIR}/${PROG}.c
            -o ${PROG}_instr
            DEPENDS ${PROG}.c
    )

    add_custom_target(${PROG} ALL
            DEPENDS ${PROG}_instr
    )

    file(READ "${CMAKE_SOURCE_DIR}/run_afl_fuzzing.sh" SCRIPT_CONTENT)
    string(REPLACE "PROG=\$1" "PROG=${PROG}"
           SCRIPT_CONTENT "${SCRIPT_CONTENT}")
    set(UPDATED_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/run_afl_fuzzing_${PROG}.sh")
    file(WRITE "${UPDATED_SCRIPT}" "${SCRIPT_CONTENT}")

    add_custom_command(
            TARGET ${PROG}
            POST_BUILD
            COMMAND chmod +x "${UPDATED_SCRIPT}"
            COMMENT "Setting executable permissions on ${UPDATED_SCRIPT}"
    )
endfunction()

add_afl_instrumentation(nested_cond)