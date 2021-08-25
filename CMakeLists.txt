cmake_minimum_required(VERSION 3.10)

project(libenc28j60)
set(ENC_SRC src/enc_init.c
            src/enc_hardware_integration.c)
set(ENC_INCLUDE include/)

add_library(enc28j60 ${ENC_SRC})
target_include_directories(enc28j60 PRIVATE ${ENC_INCLUDE})