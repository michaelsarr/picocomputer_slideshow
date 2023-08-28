cmake_minimum_required(VERSION 3.13)

project(MY-RP6502-PROJECT C ASM)

add_subdirectory(rp6502-sdk)

add_executable(slideshow)
target_sources(slideshow PRIVATE
    src/main.c
)
target_link_libraries(slideshow PRIVATE
    rp6502
)
