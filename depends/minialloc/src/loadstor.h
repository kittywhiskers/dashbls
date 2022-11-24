//
// This file contains code from randombit/botan library,
// originally released under the Simplified BSD License
// (see COPYING.BSD)
//
// Copyright (c) 1999 - 2022 The Botan Authors
//               1999 - 2017 Jack Lloyd
//                      2007 Yves Jerschow
//

#ifndef MINIALLOC_LOADSTOR_H
#define MINIALLOC_LOADSTOR_H

#include <cstddef>
#include <cstdint>
#include <cstring>

template<size_t B, typename T> inline constexpr uint8_t get_byte(T input)
{
   static_assert(B < sizeof(T), "Valid byte offset");

   const size_t shift = ((~B) & (sizeof(T) - 1)) << 3;
   return static_cast<uint8_t>((input >> shift) & 0xFF);
}

inline constexpr uint64_t make_uint64(uint8_t i0, uint8_t i1, uint8_t i2, uint8_t i3,
                                      uint8_t i4, uint8_t i5, uint8_t i6, uint8_t i7)
{
   return  ((static_cast<uint64_t>(i0) << 56) |
            (static_cast<uint64_t>(i1) << 48) |
            (static_cast<uint64_t>(i2) << 40) |
            (static_cast<uint64_t>(i3) << 32) |
            (static_cast<uint64_t>(i4) << 24) |
            (static_cast<uint64_t>(i5) << 16) |
            (static_cast<uint64_t>(i6) <<  8) |
            (static_cast<uint64_t>(i7)));
}

inline constexpr void store_le64(uint64_t in, uint8_t out[8])
{
   out[0] = get_byte<7>(in);
   out[1] = get_byte<6>(in);
   out[2] = get_byte<5>(in);
   out[3] = get_byte<4>(in);
   out[4] = get_byte<3>(in);
   out[5] = get_byte<2>(in);
   out[6] = get_byte<1>(in);
   out[7] = get_byte<0>(in);
}

inline uint64_t load_le64(const uint8_t in[], size_t off)
{
   in += off * sizeof(uint64_t);
   return make_uint64(in[7], in[6], in[5], in[4],
                      in[3], in[2], in[1], in[0]);
}

#endif // MINIALLOC_LOADSTOR_H
