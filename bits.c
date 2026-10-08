/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return 1 << 31;
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
  int i = x & y;
  int j = (~x) & (~y);
  int k = (~i) & (~j);
	return k;
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  int i = (~x) + 1;
  int j = x >> 31;
  int k = i & j;
  return k;
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  int i =(x >> (src  << 3)) & 0xFF;
  int j = x & (~(0xFF << (dst << 3)));
  int k = j | (i << (dst << 3));
  return k;
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  int i = ~ (((1 << 31) >> n) << 1);
  int j = x >> n;
  int k = i & j;
  return k;
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int i = 0x0F + (0x0F << 8) + (0x0F << 16) + (0x0F << 24);
  int low = x & i;
  int high = (x >> 4) & i;
  return (low << 4) + high;
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
  int y = ~x;
  int i = y & (y + ~0);
  int j = i & (~i + 1);
  return j;
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  x = x ^ (x >> 16);
  x = x ^ (x >> 8);
  x = x ^ (x >> 4);
  x = x ^ (x >> 2);
  x = x ^ (x >> 1);
  return ! (x & 1);
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  int s = n & 31;
  int i = ~(((1 << 31) >> s) << 1);
  int right = (x >> s) & i;
  int leftShift = (~s + 1) & 31;
  int left = x << leftShift;
  return right | left;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int block = 1 << n;
  int quotient = x >> n;
  int mask = block + ~0;
  int remainder = x & mask;
  int half = block >> 1;
  int equal = !(remainder ^ half);
  int greater = ((half + (~remainder + 1)) >> 31) & 1;
  int odd = quotient & 1;
  int roundUp = greater | (equal & odd);
  return (quotient + roundUp) << n;
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int average = (x & y) + ((x ^ y) >> 1);
  int odd = (x ^ y) & 1;
  int sx = x >> 31;
  int sy = y >> 31;
  int signDiff = sx ^ sy;
  int diff = x + (~y + 1);
  int greaterMask = (signDiff & ~sx) | (~signDiff & ~(diff >> 31));
  int greater = greaterMask & 1;
  return average + (odd & greater);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int sx = x >> 31;
  int sa = a >> 31;
  int sb = b >> 31;
  int signDiff_a = sa ^ sx;
  int signDiff_b = sb ^ sx;
  int ge_a = ((signDiff_a & ~sx) | (~signDiff_a & ~((x + (~a + 1)) >> 31))) & 1;
  int ge_b = ((signDiff_b & ~sx) | (~signDiff_b & ~((x + (~b + 1)) >> 31))) & 1;
  return (ge_a ^ ge_b) | !(x ^ a) | !(x ^ b);
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int T = 0x99 + (0x99 << 8) + (0x99 << 16) + (0x19 << 24);
  int sx = x >> 31;
  int Poverflow = (~sx) & ((T + (~x + 1)) >> 31);
  int Noverflow = sx & ((x + T) >> 31);
  int overflow = Poverflow | Noverflow;
  int result = (x << 2) + x;
  int sat = sx ^ ~(1 << 31);
  return (overflow & sat) | (~overflow & result);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
  int q = (x >> 2) + (y >> 2) + (z >> 2);
  int r = (x & 3) + (y & 3) + (z & 3);
  q = q + (r >> 2);
  int bound = 1 << 29;
  int maxQ = bound + ~0;
  int po = ((maxQ + (~q + 1)) >> 31) & 1;
  int no = ((q + bound) >> 31) & 1;
  return po + (~no + 1);
}

// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
  unsigned sign = uf & 0x80000000u;
  unsigned exp = (uf >> 23) & 0xFFu;
  unsigned frac = uf & 0x7FFFFFu;
  unsigned sig;
  unsigned prod;
  unsigned q;
  unsigned rem;

  if (exp == 0xFFu) {
    return uf;
  }

  if (exp == 0) {
    prod = frac + (frac << 1);
    q = prod >> 1;

    if ((prod & 1u) && (q & 1u)) {
      q = q + 1;
    }

    if (q >= 0x800000u) {
      return sign | (1u << 23) | (q & 0x7FFFFFu);
    }

    return sign | q;
  }

  sig = 0x800000u | frac;
  prod = sig + (sig << 1);

  if (prod < 0x2000000u) {
    q = prod >> 1;

    if ((prod & 1u) && (q & 1u)) {
      q = q + 1;
    }

    return sign | (exp << 23) | (q & 0x7FFFFFu);
  }

  if (exp == 254u) {
    return sign | 0x7F800000u;
  }

  q = prod >> 2;
  rem = prod & 3u;

  if (rem > 2u || (rem == 2u && (q & 1u))) {
    q = q + 1;
  }

  exp = exp + 1;

  return sign | (exp << 23) | (q & 0x7FFFFFu);
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
  unsigned sign = uf & 0x80000000u;
  unsigned exp = (uf >> 23) & 0xFFu;
  unsigned frac = uf & 0x7FFFFFu;
  unsigned k;
  unsigned sig;
  unsigned mask;
  unsigned rem;
  unsigned half;
  unsigned base;

  if (exp == 0xFFu) {
    return uf;
  }

  if (exp >= 150u) {
    return uf;
  }

  if (exp < 126u) {
    return sign;
  }

  if (exp == 126u) {
    if (frac == 0) {
      return sign;
    }
    return sign | 0x3F800000u;
  }

  k = 150u - exp;
  sig = 0x800000u | frac;

  mask = (1u << k) - 1u;
  rem = sig & mask;
  half = 1u << (k - 1u);
  base = sig & ~mask;

  if (rem > half ||
      (rem == half && ((base >> k) & 1u))) {
    base = base + (1u << k);
  }

  if (base & 0x1000000u) {
    base = base >> 1;
    exp = exp + 1;
  }

  return sign | (exp << 23) | (base & 0x7FFFFFu);
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
  unsigned sign = 0;
  unsigned mag = x;
  unsigned exp;
  unsigned frac;
  unsigned sig;
  unsigned shift;
  unsigned mask;
  unsigned rem;
  unsigned half;
  int p;

  if (x == 0) {
    return 0;
  }

  if (x < 0) {
    sign = 0x80000000u;
    mag = ~mag + 1u;
  }

  p = 31;
  while (((mag >> p) & 1u) == 0) {
    p = p - 1;
  }

  exp = p + 127;

  if (p <= 23) {
    frac = (mag << (23 - p)) & 0x7FFFFFu;
  } else {
    shift = p - 23;
    sig = mag >> shift;

    mask = (1u << shift) - 1u;
    rem = mag & mask;
    half = 1u << (shift - 1u);

    if (rem > half ||
        (rem == half && (sig & 1u))) {
      sig = sig + 1u;

      if (sig & 0x1000000u) {
        sig = sig >> 1;
        exp = exp + 1u;
      }
    }

    frac = sig & 0x7FFFFFu;
  }

  return sign | (exp << 23) | frac;
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int mask1 = 0x55 + (0x55 << 8) + (0x55 << 16) + (0x55 << 24);
  int mask2 = 0x33 + (0x33 << 8) + (0x33 << 16) + (0x33 << 24);
  int mask4 = 0x0F + (0x0F << 8) + (0x0F << 16) + (0x0F << 24);

  x = (x & mask1) + ((x >> 1) & mask1);
  x = (x & mask2) + ((x >> 2) & mask2);
  x = (x + (x >> 4)) & mask4;
  x = x + (x >> 8);
  x = x + (x >> 16);
  return x & 0x3F;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x) {
  int mask;
  mask = (0xFF << 8) | 0xFF;
  x = ((x >> 16) & mask) | (x << 16);
  mask = mask ^ (mask << 8);
  x = ((x >> 8) & mask) | ((x & mask) << 8);
  mask = mask ^ (mask << 4);
  x = ((x >> 4) & mask) | ((x & mask) << 4);
  mask = mask ^ (mask << 2);
  x = ((x >> 2) & mask) | ((x & mask) << 2);
  mask = mask ^ (mask << 1);
  x = ((x >> 1) & mask) | ((x & mask) << 1);
  return x;
}
