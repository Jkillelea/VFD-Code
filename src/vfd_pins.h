#ifndef _VFD_PINS_H_
#define _VFD_PINS_H_

#include <stdint.h>

// segments
#define  A   ((uint32_t)  1  <<  0 )
#define  B   ((uint32_t)  1  <<  2 )
#define  C   ((uint32_t)  1  <<  9 )
#define  D   ((uint32_t)  1  <<  14)
#define  E   ((uint32_t)  1  <<  21)
#define  F   ((uint32_t)  1  <<  24)
#define  G   ((uint32_t)  1  <<  4 )
#define  H   ((uint32_t)  1  <<  3 )
#define  I   ((uint32_t)  1  <<  7 )
#define  J   ((uint32_t)  1  <<  15)
#define  K   ((uint32_t)  1  <<  17)
#define  L   ((uint32_t)  1  <<  20)
#define  M   ((uint32_t)  1  <<  22)
#define  N   ((uint32_t)  1  <<  6 )
#define  O   ((uint32_t)  1  <<  12)
#define  P   ((uint32_t)  1  <<  18)

// grids
#define  G1  ((uint32_t)  1  <<  23)
#define  G2  ((uint32_t)  1  <<  19)
#define  G3  ((uint32_t)  1  <<  16)
#define  G4  ((uint32_t)  1  <<  13)
#define  G5  ((uint32_t)  1  <<  11)
#define  G6  ((uint32_t)  1  <<  10)
#define  G7  ((uint32_t)  1  <<  8 )
#define  G8  ((uint32_t)  1  <<  5 )
#define  G9  ((uint32_t)  1  <<  1 )

// letters
#define  symbol_comma   ((uint32_t)  P  )
#define  symbol_period  ((uint32_t)  O  )
#define  letter_a       ((uint32_t)  A  |  B  |  C  |  E  |  F  |  I   |  M  )
#define  letter_b       ((uint32_t)  A  |  B  |  C  |  D  |  I  |  K   |  G  )
#define  letter_c       ((uint32_t)  A  |  D  |  E  |  F  )
#define  letter_d       ((uint32_t)  A  |  B  |  C  |  D  |  K  |  G   )
#define  letter_e       ((uint32_t)  A  |  D  |  E  |  F  |  M  |  I   )
#define  letter_f       ((uint32_t)  A  |  E  |  F  |  M  )
#define  letter_g       ((uint32_t)  A  |  C  |  D  |  E  |  F  |  I   )
#define  letter_h       ((uint32_t)  B  |  C  |  E  |  F  |  I  |  M   )
#define  letter_i       ((uint32_t)  A  |  G  |  K  |  D  )
#define  letter_j       ((uint32_t)  B  |  C  |  D  |  E  )
#define  letter_k       ((uint32_t)  E  |  F  |  M  |  H  |  J  )
#define  letter_l       ((uint32_t)  D  |  E  |  F  )
#define  letter_m       ((uint32_t)  B  |  C  |  E  |  F  |  H  |  N   )
#define  letter_n       ((uint32_t)  B  |  C  |  E  |  F  |  J  |  N   )
#define  letter_o       ((uint32_t)  A  |  B  |  C  |  D  |  E  |  F   )
#define  letter_p       ((uint32_t)  A  |  B  |  I  |  M  |  E  |  F   )
#define  letter_q       ((uint32_t)  A  |  B  |  C  |  D  |  E  |  F   |  J  )
#define  letter_r       ((uint32_t)  A  |  B  |  I  |  M  |  E  |  F   |  J  )
#define  letter_s       ((uint32_t)  A  |  F  |  M  |  I  |  C  |  D   )
#define  letter_t       ((uint32_t)  A  |  G  |  K  )
#define  letter_u       ((uint32_t)  B  |  C  |  D  |  E  |  F  )
#define  letter_v       ((uint32_t)  E  |  F  |  H  |  L  )
#define  letter_w       ((uint32_t)  B  |  C  |  E  |  F  |  J  |  L   )
#define  letter_x       ((uint32_t)  H  |  J  |  L  |  N  )
#define  letter_y       ((uint32_t)  F  |  M  |  I  |  B  |  C  |  D   )
#define  letter_z       ((uint32_t)  A  |  H  |  L  |  D  )
#define  number_zero    ((uint32_t)  A  |  B  |  C  |  D  |  E  |  F   |  H  |  L   )
#define  number_one     ((uint32_t)  G  |  K  )
#define  number_two     ((uint32_t)  A  |  B | I | M | E | D )
#define  number_three   ((uint32_t)  A  |  B  |  I  |  M  |  C  |  D   )
#define  number_four    ((uint32_t)  F  |  M  |  I  |  B  |  C  )
#define  number_five    ((uint32_t)  A  |  F  |  M  |  I  |  C  |  D   )
#define  number_six     ((uint32_t)  A  |  F  |  M  |  I  |  C  |  D   |  E  )
#define  number_seven   ((uint32_t)  A  |  H  |  L  )
#define  number_eight   ((uint32_t)  A  |  B  |  C  |  D  |  E  |  F   |  M  |  I)
#define  number_nine    ((uint32_t)  A  |  B  |  C  |  F  |  M  |  I)
#endif // _VFD_PINS_H_
