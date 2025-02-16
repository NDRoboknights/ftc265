//===- MemAlloc.h - Memory allocation functions -----------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
/// \file
///
/// This file defines counterparts of C library allocation functions defined in
/// the namespace 'std'. The new allocation functions crash on allocation
/// failure instead of returning null pointer.
///
//===----------------------------------------------------------------------===//

#ifndef WPIUTIL_WPI_MEMALLOC_H
#define WPIUTIL_WPI_MEMALLOC_H

#include "wpi/Compiler.h"
#include "wpi/ErrorHandling.h"
#include <cstdlib>

namespace wpi {

#ifdef _WIN32
#pragma warning(push)
    // Warning on NONNULL, report is not known to abort
#pragma warning(disable : 6387)
#pragma warning(disable : 28196)
#pragma warning(disable : 28183)
#endif

    LLVM_ATTRIBUTE_RETURNS_NONNULL inline void *safe_malloc(size_t Sz) {
        void *Result = std::malloc(Sz);
        if (Result == nullptr)
            report_bad_alloc_error("Allocation failed");
        return Result;
    }

    LLVM_ATTRIBUTE_RETURNS_NONNULL inline void *safe_calloc(size_t Count,
                                                            size_t Sz) {
        void *Result = std::calloc(Count, Sz);
        if (Result == nullptr)
            report_bad_alloc_error("Allocation failed");
        return Result;
    }

    LLVM_ATTRIBUTE_RETURNS_NONNULL inline void *safe_realloc(void *Ptr, size_t Sz) {
        void *Result = std::realloc(Ptr, Sz);
        if (Result == nullptr)
            report_bad_alloc_error("Allocation failed");
        return Result;
    }

#ifdef _WIN32
#pragma warning(pop)
#endif

}
#endif
