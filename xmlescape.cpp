// -------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "xmlescape.h"
// -------------------------------------------------------------------------------------------------------------------------------
static const char* xml_tanslation_table[] = {
    "?",         // ASCII-Code: 000, CHR: 0x0
    "?",         // ASCII-Code: 001, CHR: 0x1
    "?",         // ASCII-Code: 002, CHR: 0x2
    "?",         // ASCII-Code: 003, CHR: 0x3
    "?",         // ASCII-Code: 004, CHR: 0x4
    "?",         // ASCII-Code: 005, CHR: 0x5
    "?",         // ASCII-Code: 006, CHR: 0x6
    "?",         // ASCII-Code: 007, CHR: 0x7
    "?",         // ASCII-Code: 008, CHR: 0x8
    nullptr,     // ASCII-Code: 009, CHR: TAB
    nullptr,     // ASCII-Code: 010, CHR: LF
    "?",         // ASCII-Code: 011, CHR: 0xb
    "?",         // ASCII-Code: 012, CHR: 0xc
    nullptr,     // ASCII-Code: 013, CHR: RET
    "?",         // ASCII-Code: 014, CHR: 0xe
    "?",         // ASCII-Code: 015, CHR: 0xf
    "?",         // ASCII-Code: 016, CHR: 0x10
    "?",         // ASCII-Code: 017, CHR: 0x11
    "?",         // ASCII-Code: 018, CHR: 0x12
    "?",         // ASCII-Code: 019, CHR: 0x13
    "?",         // ASCII-Code: 020, CHR: 0x14
    "?",         // ASCII-Code: 021, CHR: 0x15
    "?",         // ASCII-Code: 022, CHR: 0x16
    "?",         // ASCII-Code: 023, CHR: 0x17
    "?",         // ASCII-Code: 024, CHR: 0x18
    "?",         // ASCII-Code: 025, CHR: 0x19
    "?",         // ASCII-Code: 026, CHR: 0x1a
    "?",         // ASCII-Code: 027, CHR: 0x1b
    "?",         // ASCII-Code: 028, CHR: 0x1c
    "?",         // ASCII-Code: 029, CHR: 0x1d
    "?",         // ASCII-Code: 030, CHR: 0x1e
    "?",         // ASCII-Code: 031, CHR: 0x1f
    nullptr,     // ASCII-Code: 032, CHR:  
    nullptr,     // ASCII-Code: 033, CHR: !
    "&quot;",    // ASCII-Code: 034, CHR: "
    nullptr,     // ASCII-Code: 035, CHR: #
    nullptr,     // ASCII-Code: 036, CHR: $
    nullptr,     // ASCII-Code: 037, CHR: %
    "&amp;",     // ASCII-Code: 038, CHR: &
    "&apos;",    // ASCII-Code: 039, CHR: '
    nullptr,     // ASCII-Code: 040, CHR: (
    nullptr,     // ASCII-Code: 041, CHR: )
    nullptr,     // ASCII-Code: 042, CHR: *
    nullptr,     // ASCII-Code: 043, CHR: +
    nullptr,     // ASCII-Code: 044, CHR: ,
    nullptr,     // ASCII-Code: 045, CHR: -
    nullptr,     // ASCII-Code: 046, CHR: .
    nullptr,     // ASCII-Code: 047, CHR: /
    nullptr,     // ASCII-Code: 048, CHR: 0
    nullptr,     // ASCII-Code: 049, CHR: 1
    nullptr,     // ASCII-Code: 050, CHR: 2
    nullptr,     // ASCII-Code: 051, CHR: 3
    nullptr,     // ASCII-Code: 052, CHR: 4
    nullptr,     // ASCII-Code: 053, CHR: 5
    nullptr,     // ASCII-Code: 054, CHR: 6
    nullptr,     // ASCII-Code: 055, CHR: 7
    nullptr,     // ASCII-Code: 056, CHR: 8
    nullptr,     // ASCII-Code: 057, CHR: 9
    nullptr,     // ASCII-Code: 058, CHR: :
    nullptr,     // ASCII-Code: 059, CHR: ;
    "&lt;",      // ASCII-Code: 060, CHR: <
    nullptr,     // ASCII-Code: 061, CHR: =
    "&gt;",      // ASCII-Code: 062, CHR: >
    nullptr,     // ASCII-Code: 063, CHR: ?
    nullptr,     // ASCII-Code: 064, CHR: @
    nullptr,     // ASCII-Code: 065, CHR: A
    nullptr,     // ASCII-Code: 066, CHR: B
    nullptr,     // ASCII-Code: 067, CHR: C
    nullptr,     // ASCII-Code: 068, CHR: D
    nullptr,     // ASCII-Code: 069, CHR: E
    nullptr,     // ASCII-Code: 070, CHR: F
    nullptr,     // ASCII-Code: 071, CHR: G
    nullptr,     // ASCII-Code: 072, CHR: H
    nullptr,     // ASCII-Code: 073, CHR: I
    nullptr,     // ASCII-Code: 074, CHR: J
    nullptr,     // ASCII-Code: 075, CHR: K
    nullptr,     // ASCII-Code: 076, CHR: L
    nullptr,     // ASCII-Code: 077, CHR: M
    nullptr,     // ASCII-Code: 078, CHR: N
    nullptr,     // ASCII-Code: 079, CHR: O
    nullptr,     // ASCII-Code: 080, CHR: P
    nullptr,     // ASCII-Code: 081, CHR: Q
    nullptr,     // ASCII-Code: 082, CHR: R
    nullptr,     // ASCII-Code: 083, CHR: S
    nullptr,     // ASCII-Code: 084, CHR: T
    nullptr,     // ASCII-Code: 085, CHR: U
    nullptr,     // ASCII-Code: 086, CHR: V
    nullptr,     // ASCII-Code: 087, CHR: W
    nullptr,     // ASCII-Code: 088, CHR: X
    nullptr,     // ASCII-Code: 089, CHR: Y
    nullptr,     // ASCII-Code: 090, CHR: Z
    nullptr,     // ASCII-Code: 091, CHR: [
    nullptr,     // ASCII-Code: 092, CHR: BACKSLASH
    nullptr,     // ASCII-Code: 093, CHR: ]
    nullptr,     // ASCII-Code: 094, CHR: ^
    nullptr,     // ASCII-Code: 095, CHR: _
    nullptr,     // ASCII-Code: 096, CHR: `
    nullptr,     // ASCII-Code: 097, CHR: a
    nullptr,     // ASCII-Code: 098, CHR: b
    nullptr,     // ASCII-Code: 099, CHR: c
    nullptr,     // ASCII-Code: 100, CHR: d
    nullptr,     // ASCII-Code: 101, CHR: e
    nullptr,     // ASCII-Code: 102, CHR: f
    nullptr,     // ASCII-Code: 103, CHR: g
    nullptr,     // ASCII-Code: 104, CHR: h
    nullptr,     // ASCII-Code: 105, CHR: i
    nullptr,     // ASCII-Code: 106, CHR: j
    nullptr,     // ASCII-Code: 107, CHR: k
    nullptr,     // ASCII-Code: 108, CHR: l
    nullptr,     // ASCII-Code: 109, CHR: m
    nullptr,     // ASCII-Code: 110, CHR: n
    nullptr,     // ASCII-Code: 111, CHR: o
    nullptr,     // ASCII-Code: 112, CHR: p
    nullptr,     // ASCII-Code: 113, CHR: q
    nullptr,     // ASCII-Code: 114, CHR: r
    nullptr,     // ASCII-Code: 115, CHR: s
    nullptr,     // ASCII-Code: 116, CHR: t
    nullptr,     // ASCII-Code: 117, CHR: u
    nullptr,     // ASCII-Code: 118, CHR: v
    nullptr,     // ASCII-Code: 119, CHR: w
    nullptr,     // ASCII-Code: 120, CHR: x
    nullptr,     // ASCII-Code: 121, CHR: y
    nullptr,     // ASCII-Code: 122, CHR: z
    nullptr,     // ASCII-Code: 123, CHR: {
    nullptr,     // ASCII-Code: 124, CHR: |
    nullptr,     // ASCII-Code: 125, CHR: }
    nullptr,     // ASCII-Code: 126, CHR: ~
    nullptr,     // ASCII-Code: 127, CHR: 
};
// -------------------------------------------------------------------------------------------------------------------------------
std::ostream& xml_escape(std::ostream& out, const char* src)
{
  // repeat until termination char (0) or the stream fails.
  while (*src && out.good())
  {
    const char current = *src++;

    if (current < 128) 
    {
      // first not bit set (0..127), take from lookup table
      const char* entity = xml_tanslation_table[current];
      if (entity)
      {
        out << entity;
        continue;
      }
    }
    // every other char is taken as it is
    out << current;
  }
  return out;
}
// -------------------------------------------------------------------------------------------------------------------------------
