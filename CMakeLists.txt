cmake_minimum_required(VERSION 3.29)
project(printers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(snmp++-3.5.2)

add_executable(printers main.cpp
        PrinterData.h
        PrinterData.cpp
        SnmpGetPrinterdata.h
        SnmpGetPrinterdata.cpp
        PrinterDatasOids.h)

target_link_libraries(printers snmp++)

