//===- NativeFormatting.h - Low level formatting helpers ---------*- C++-*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef WPIUTIL_WPI_NATIVE_FORMATTING_H
#define WPIUTIL_WPI_NATIVE_FORMATTING_H

#include "wpi/raw_ostream.h"

#include <cstdint>
#include <optional>

namespace wpi {
    enum class FloatStyle {
        Exponent, ExponentUpper, Fixed, Percent
    };
    enum class IntegerStyle {
        Integer,
        Number,
    };
    enum class HexPrintStyle {
        Upper, Lower, PrefixUpper, PrefixLower
    };

    size_t getDefaultPrecision(FloatStyle Style);

    bool isPrefixedHexStyle(HexPrintStyle S);

    void write_integer(raw_ostream &S, unsigned int N, size_t MinDigits,
                       IntegerStyle Style);

    void write_integer(raw_ostream &S, int N, size_t MinDigits, IntegerStyle Style);

    void write_integer(raw_ostream &S, unsigned long N, size_t MinDigits,
                       IntegerStyle Style);

    void write_integer(raw_ostream &S, long N, size_t MinDigits,
                       IntegerStyle Style);

    void write_integer(raw_ostream &S, unsigned long long N, size_t MinDigits,
                       IntegerStyle Style);

    void write_integer(raw_ostream &S, long long N, size_t MinDigits,
                       IntegerStyle Style);

    void write_hex(raw_ostream &S, uint64_t N, HexPrintStyle Style,
                   std::optional <size_t> Width = std::nullopt);

    void write_double(raw_ostream &S, double D, FloatStyle Style,
                      std::optional <size_t> Precision = std::nullopt);
}

#endif

