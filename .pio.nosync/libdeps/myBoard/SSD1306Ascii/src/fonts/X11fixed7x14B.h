// STARTFONT 2.1
// COMMENT "$Id: 7x14B.bdf,v 1.25 2003-07-26 14:55:51+01 mgk25 Rel $"
// COMMENT "Send bug reports to Markus Kuhn <http://www.cl.cam.ac.uk/~mgk25/>"
// FONT -Misc-Fixed-Bold-R-Normal--14-130-75-75-C-70-ISO10646-1
//
// Note: Pixels are only six columns wide.
//
#ifndef X11fixed7x14B_h
#define X11fixed7x14B_h
GLCDFONTDECL(X11fixed7x14B) = {
  0x0, 0x0, // size of zero indicates fixed width font,
  6,    // width
  14,   // height
  0x20, // first char
  0x60, // char count  
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,  // space
  0X00,0X00,0XFC,0XFC,0X00,0X00,0X00,0X00,0X0D,0X0D,0X00,0X00,  // exclam
  0X00,0X1E,0X1E,0X00,0X1E,0X1E,0X00,0X00,0X00,0X00,0X00,0X00,  // quotedbl
  0X20,0XFC,0XFC,0XFC,0XFC,0X20,0X01,0X0F,0X0F,0X0F,0X0F,0X01,  // numbersign
  0X30,0X48,0XFC,0XFC,0X88,0X30,0X06,0X08,0X1F,0X1F,0X08,0X07,  // dollar
  0X18,0X3C,0XA4,0X78,0X1C,0X0C,0X0C,0X0E,0X07,0X09,0X0F,0X06,  // percent
  0X00,0XB8,0XFC,0X44,0XFC,0XB8,0X07,0X0F,0X08,0X07,0X0F,0X09,  // ampersand
  0X00,0X00,0X1E,0X1E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,  // quotesingle
  0X00,0XE0,0XF8,0X1C,0X06,0X02,0X00,0X03,0X0F,0X1C,0X30,0X20,  // parenleft
  0X00,0X02,0X06,0X1C,0XF8,0XE0,0X00,0X20,0X30,0X1C,0X0F,0X03,  // parenright
  0X8C,0X50,0XFC,0XFC,0X50,0X8C,0X01,0X00,0X01,0X01,0X00,0X01,  // asterisk
  0X80,0X80,0XF0,0XF0,0X80,0X80,0X00,0X00,0X07,0X07,0X00,0X00,  // plus
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X24,0X3C,0X1C,0X00,  // comma
  0X80,0X80,0X80,0X80,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,  // hyphen
  0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0C,0X0C,0X00,0X00,  // period
  0X00,0X00,0XC0,0XF0,0X3E,0X0E,0X38,0X3E,0X07,0X01,0X00,0X00,  // slash
  0XF8,0XFC,0X04,0X04,0XFC,0XF8,0X07,0X0F,0X08,0X08,0X0F,0X07,  // zero
  0X10,0X18,0XFC,0XFC,0X00,0X00,0X08,0X08,0X0F,0X0F,0X08,0X08,  // one
  0X18,0X1C,0X04,0XC4,0XFC,0X38,0X0C,0X0E,0X0B,0X09,0X08,0X08,  // two
  0X18,0X1C,0X44,0X44,0XFC,0XB8,0X06,0X0E,0X08,0X08,0X0F,0X07,  // three
  0X80,0XC0,0X60,0XF8,0XFC,0X00,0X03,0X03,0X02,0X0F,0X0F,0X02,  // four
  0X7C,0X7C,0X24,0X24,0XE4,0XC4,0X06,0X0E,0X08,0X08,0X0F,0X07,  // five
  0XF0,0XF8,0X4C,0X44,0XDC,0X98,0X07,0X0F,0X08,0X08,0X0F,0X07,  // six
  0X1C,0X1C,0XC4,0XF4,0X3C,0X0C,0X00,0X00,0X0F,0X0F,0X00,0X00,  // seven
  0X38,0XFC,0XC4,0XC4,0XFC,0X38,0X07,0X0F,0X08,0X08,0X0F,0X07,  // eight
  0X78,0XFC,0X84,0X84,0XFC,0XF8,0X06,0X0E,0X08,0X0C,0X07,0X03,  // nine
  0X00,0X00,0X30,0X30,0X00,0X00,0X00,0X00,0X06,0X06,0X00,0X00,  // colon
  0X00,0X00,0X00,0X30,0X30,0X00,0X00,0X00,0X12,0X1E,0X0E,0X00,  // semicolon
  0X80,0XC0,0X60,0X30,0X18,0X08,0X00,0X01,0X03,0X06,0X0C,0X08,  // less
  0X40,0X40,0X40,0X40,0X40,0X40,0X02,0X02,0X02,0X02,0X02,0X02,  // equal
  0X08,0X18,0X30,0X60,0XC0,0X80,0X08,0X0C,0X06,0X03,0X01,0X00,  // greater
  0X18,0X1C,0XC4,0XE4,0X3C,0X18,0X00,0X00,0X0D,0X0D,0X00,0X00,  // question
  0XF0,0XF8,0XEC,0XF4,0X1C,0XF8,0X03,0X07,0X0D,0X0B,0X0A,0X0B,  // at
  0XF8,0XFC,0X0C,0X0C,0XFC,0XF8,0X0F,0X0F,0X01,0X01,0X0F,0X0F,  // A
  0XFC,0XFC,0X44,0X44,0XFC,0X98,0X0F,0X0F,0X08,0X08,0X0F,0X07,  // B
  0XF8,0XFC,0X04,0X04,0X1C,0X18,0X07,0X0F,0X08,0X08,0X0E,0X06,  // C
  0XFC,0XFC,0X04,0X0C,0XF8,0XF0,0X0F,0X0F,0X08,0X0C,0X07,0X03,  // D
  0XFC,0XFC,0X44,0X44,0X44,0X04,0X0F,0X0F,0X08,0X08,0X08,0X08,  // E
  0XFC,0XFC,0X44,0X44,0X44,0X04,0X0F,0X0F,0X00,0X00,0X00,0X00,  // F
  0XF8,0XFC,0X04,0X84,0X9C,0X98,0X07,0X0F,0X08,0X08,0X0F,0X07,  // G
  0XFC,0XFC,0X40,0X40,0XFC,0XFC,0X0F,0X0F,0X00,0X00,0X0F,0X0F,  // H
  0X04,0X04,0XFC,0XFC,0X04,0X04,0X08,0X08,0X0F,0X0F,0X08,0X08,  // I
  0X00,0X00,0X00,0X00,0XFC,0XFC,0X06,0X0E,0X08,0X0C,0X07,0X03,  // J
  0XFC,0XFC,0XF0,0X98,0X0C,0X04,0X0F,0X0F,0X01,0X03,0X0E,0X0C,  // K
  0XFC,0XFC,0X00,0X00,0X00,0X00,0X0F,0X0F,0X08,0X08,0X08,0X08,  // L
  0XFC,0XF8,0X60,0X60,0XF8,0XFC,0X0F,0X0F,0X00,0X00,0X0F,0X0F,  // M
  0XFC,0XFC,0X70,0X80,0XFC,0XFC,0X0F,0X0F,0X00,0X03,0X0F,0X0F,  // N
  0XF8,0XFC,0X04,0X04,0XFC,0XF8,0X07,0X0F,0X08,0X08,0X0F,0X07,  // O
  0XFC,0XFC,0X84,0X84,0XFC,0X78,0X0F,0X0F,0X00,0X00,0X00,0X00,  // P
  0XF8,0XFC,0X04,0X04,0XFC,0XF8,0X07,0X0F,0X09,0X0A,0X1F,0X37,  // Q
  0XFC,0XFC,0X44,0XC4,0XFC,0X38,0X0F,0X0F,0X00,0X00,0X0F,0X0F,  // R
  0X18,0X3C,0XE4,0XC4,0X1C,0X18,0X06,0X0E,0X08,0X09,0X0F,0X06,  // S
  0X04,0X04,0XFC,0XFC,0X04,0X04,0X00,0X00,0X0F,0X0F,0X00,0X00,  // T
  0XFC,0XFC,0X00,0X00,0XFC,0XFC,0X07,0X0F,0X08,0X08,0X0F,0X07,  // U
  0XFC,0XFC,0X00,0X00,0XFC,0XFC,0X01,0X07,0X0E,0X0E,0X07,0X01,  // V
  0XFC,0XFC,0X80,0X80,0XFC,0XFC,0X07,0X0F,0X07,0X07,0X0F,0X07,  // W
  0X0C,0X3C,0XF0,0XF0,0X3C,0X0C,0X0C,0X0F,0X03,0X03,0X0F,0X0C,  // X
  0X1C,0X7C,0XE0,0XE0,0X7C,0X1C,0X00,0X00,0X0F,0X0F,0X00,0X00,  // Y
  0X04,0X04,0XC4,0XF4,0X3C,0X0C,0X0C,0X0F,0X0B,0X08,0X08,0X08,  // Z
  0X00,0XFE,0XFE,0X02,0X02,0X02,0X00,0X3F,0X3F,0X20,0X20,0X20,  // bracketleft
  0X0E,0X3E,0XF0,0XC0,0X00,0X00,0X00,0X00,0X01,0X07,0X3E,0X38,  // backslash
  0X00,0X02,0X02,0X02,0XFE,0XFE,0X00,0X20,0X20,0X20,0X3F,0X3F,  // bracketright
  0X04,0X06,0X03,0X03,0X06,0X04,0X00,0X00,0X00,0X00,0X00,0X00,  // asciicircum
  0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X30,0X30,0X30,0X30,0X30,  // underscore
  0X00,0X02,0X06,0X0C,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X00,  // grave
  0X40,0X60,0X20,0XA0,0XE0,0XC0,0X06,0X0F,0X09,0X08,0X0F,0X0F,  // a
  0XFC,0XFC,0X20,0X20,0XE0,0XC0,0X0F,0X0F,0X08,0X08,0X0F,0X07,  // b
  0XC0,0XE0,0X20,0X20,0X60,0X40,0X07,0X0F,0X08,0X08,0X0C,0X04,  // c
  0XC0,0XE0,0X20,0X20,0XFC,0XFC,0X07,0X0F,0X08,0X08,0X0F,0X0F,  // d
  0XC0,0XE0,0X20,0X20,0XE0,0XC0,0X07,0X0F,0X09,0X09,0X0D,0X05,  // e
  0X40,0X40,0XF8,0XFC,0X4C,0X48,0X00,0X00,0X0F,0X0F,0X00,0X00,  // f
  0XC0,0XE0,0X20,0XE0,0XC0,0X60,0X19,0X3F,0X2A,0X2B,0X39,0X10,  // g
  0XFC,0XFC,0X20,0X20,0XE0,0XC0,0X0F,0X0F,0X00,0X00,0X0F,0X0F,  // h
  0X00,0X00,0XEC,0XEC,0X00,0X00,0X00,0X00,0X0F,0X0F,0X00,0X00,  // i
  0X00,0X00,0X00,0X00,0XEC,0XEC,0X00,0X10,0X30,0X20,0X3F,0X1F,  // j
  0XFC,0XFC,0X80,0XC0,0X60,0X00,0X0F,0X0F,0X01,0X03,0X06,0X0C,  // k
  0X00,0X00,0XFC,0XFC,0X00,0X00,0X00,0X00,0X0F,0X0F,0X00,0X00,  // l
  0XE0,0XE0,0XC0,0XE0,0XE0,0XC0,0X0F,0X0F,0X07,0X07,0X0F,0X0F,  // m
  0XE0,0XE0,0X20,0X20,0XE0,0XC0,0X0F,0X0F,0X00,0X00,0X0F,0X0F,  // n
  0XC0,0XE0,0X20,0X20,0XE0,0XC0,0X07,0X0F,0X08,0X08,0X0F,0X07,  // o
  0XE0,0XE0,0X20,0X20,0XE0,0XC0,0X3F,0X3F,0X08,0X08,0X0F,0X07,  // p
  0XC0,0XE0,0X20,0X20,0XE0,0XE0,0X07,0X0F,0X08,0X08,0X3F,0X3F,  // q
  0XE0,0XE0,0X20,0X20,0XE0,0XC0,0X0F,0X0F,0X00,0X00,0X00,0X00,  // r
  0X40,0XE0,0XA0,0X20,0X60,0X40,0X04,0X0C,0X09,0X0B,0X0E,0X04,  // s
  0X20,0X20,0XFC,0XFC,0X20,0X20,0X00,0X00,0X07,0X0F,0X08,0X08,  // t
  0XE0,0XE0,0X00,0X00,0XE0,0XE0,0X07,0X0F,0X08,0X08,0X0F,0X0F,  // u
  0XE0,0XE0,0X00,0X00,0XE0,0XE0,0X00,0X03,0X0F,0X0F,0X03,0X00,  // v
  0XE0,0XE0,0X80,0X80,0XE0,0XE0,0X07,0X0F,0X07,0X07,0X0F,0X07,  // w
  0X60,0XE0,0X80,0X80,0XE0,0X60,0X0C,0X0E,0X03,0X03,0X0E,0X0C,  // x
  0X60,0XE0,0X80,0X00,0XE0,0XE0,0X10,0X31,0X27,0X3E,0X1F,0X01,  // y
  0X20,0X20,0X20,0XA0,0XE0,0X60,0X0C,0X0E,0X0B,0X09,0X08,0X08,  // z
  0X00,0X80,0XFC,0X7E,0X02,0X02,0X00,0X00,0X1F,0X3F,0X20,0X20,  // braceleft
  0X00,0X00,0XFE,0XFE,0X00,0X00,0X00,0X00,0X3F,0X3F,0X00,0X00,  // bar
  0X00,0X02,0X02,0X7E,0XFC,0X80,0X00,0X20,0X20,0X3F,0X1F,0X00,  // braceright
  0X1C,0X06,0X0C,0X0C,0X18,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,  // asciitilde
  0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3F,0X3F,0X3F,0X3F,0X3F,0X3F   // del
};
#endif  // X11fixed7x14B_h
