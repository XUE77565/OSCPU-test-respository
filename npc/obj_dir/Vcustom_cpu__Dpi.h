// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VCUSTOM_CPU__DPI_H_
#define VERILATED_VCUSTOM_CPU__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/xyzabc/Desktop/OSCPU-test-respository/npc/vsrc/define.v:4:30
    extern int pmem_read(int raddr);
    // DPI import at /home/xyzabc/Desktop/OSCPU-test-respository/npc/vsrc/define.v:5:30
    extern void pmem_write(int addr, int data, int mask);
    // DPI import at /home/xyzabc/Desktop/OSCPU-test-respository/npc/vsrc/wb.v:4:30
    extern void set_ebreak();

#ifdef __cplusplus
}
#endif

#endif  // guard
