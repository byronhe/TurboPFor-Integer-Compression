/**
    Copyright (C) powturbo 2013-2014
    GPL v2 License

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    - email    : powturbo [AT] gmail.com
    - github   : https://github.com/powturbo
    - homepage : https://sites.google.com/site/powturbo/
    - twitter  : https://twitter.com/powturbo

    bitpack_.h - "Integer Compression" bit packing 
**/
#include <stdint.h>
#define USE_BITPACK 64
#if 0
#define SRCI(__ip) __ip+=32
#define SRC(__ip,__x) __ip[__x]
#define SRC1(__ip,__x) __ip[__x]
//#define SRCP( __ip)
#else
#define SRCI(__ip)
#define SRC1(__ip,__x) (*(__ip/*+1*/))
#define SRC( __ip,__x) (*__ip++)
//#define SRCP( __ip) (__ip++)
#endif

  #if USE_BITPACK == 64
#include "bitpack64_.h"
#define BITPACK32(__ip, __n, __nbits, __op, __parm) do { typeof(__ip[0]) *__ipe=(__ip)+(__n);/*((__n+31)&0xffffffe0u)*/;\
  switch(__nbits) {\
    case  0:__ip = __ipe; break;\
    case  1:do BITPACK64_1( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  2:do BITPACK64_2( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  3:do BITPACK64_3( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  4:do BITPACK64_4( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  5:do BITPACK64_5( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  6:do BITPACK64_6( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  7:do BITPACK64_7( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  8:do BITPACK64_8( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  9:do BITPACK64_9( __ip, __op, __parm) while(__ip < __ipe); break;\
    case 10:do BITPACK64_10(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 11:do BITPACK64_11(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 12:do BITPACK64_12(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 13:do BITPACK64_13(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 14:do BITPACK64_14(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 15:do BITPACK64_15(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 16:do BITPACK64_16(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 17:do BITPACK64_17(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 18:do BITPACK64_18(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 19:do BITPACK64_19(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 20:do BITPACK64_20(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 21:do BITPACK64_21(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 22:do BITPACK64_22(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 23:do BITPACK64_23(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 24:do BITPACK64_24(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 25:do BITPACK64_25(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 26:do BITPACK64_26(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 27:do BITPACK64_27(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 28:do BITPACK64_28(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 29:do BITPACK64_29(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 30:do BITPACK64_30(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 31:do BITPACK64_31(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 32:do BITPACK64_32(__ip, __op, __parm) while(__ip < __ipe);\
  }\
} while(0)
  #else
#include "bitpack32_.h" // Not included in the github package
#define BITPACK32(__ip, __n, __nbits, __op, __parm) do { typeof(__ip[0]) *__ipe=(__ip)+(__n);/*((__n+31)&0xffffffe0u)*/;\
  switch(__nbits) {\
    case  0:__ip = __ipe; break;\
    case  1:do BITPACK32_1( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  2:do BITPACK32_2( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  3:do BITPACK32_3( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  4:do BITPACK32_4( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  5:do BITPACK32_5( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  6:do BITPACK32_6( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  7:do BITPACK32_7( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  8:do BITPACK32_8( __ip, __op, __parm) while(__ip < __ipe); break;\
    case  9:do BITPACK32_9( __ip, __op, __parm) while(__ip < __ipe); break;\
    case 10:do BITPACK32_10(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 11:do BITPACK32_11(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 12:do BITPACK32_12(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 13:do BITPACK32_13(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 14:do BITPACK32_14(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 15:do BITPACK32_15(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 16:do BITPACK32_16(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 17:do BITPACK32_17(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 18:do BITPACK32_18(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 19:do BITPACK32_19(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 20:do BITPACK32_20(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 21:do BITPACK32_21(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 22:do BITPACK32_22(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 23:do BITPACK32_23(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 24:do BITPACK32_24(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 25:do BITPACK32_25(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 26:do BITPACK32_26(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 27:do BITPACK32_27(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 28:do BITPACK32_28(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 29:do BITPACK32_29(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 30:do BITPACK32_30(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 31:do BITPACK32_31(__ip, __op, __parm) while(__ip < __ipe); break;\
    case 32:do BITPACK32_32(__ip, __op, __parm) while(__ip < __ipe);\
  }\
} while(0)
  #endif
