#include <SPI.h>
#include <TimerOne.h>
#include "vfd_pins.h"
#include "asciitable.h"

#define VFD_USE_SPI 1
#if VFD_USE_SPI
SPISettings settings(100000, MSBFIRST, SPI_MODE0);
#endif

const int CLOCK = 13;
const int DATA  = 11;
const int LATCH = 10;

static const uint32_t elements[] = {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P};
static const size_t numel = sizeof(elements) / sizeof(A);

static const uint32_t grids[] = {G1, G2, G3, G4, G5, G6, G7, G8, G9};
static const size_t ngrids = sizeof(grids) / sizeof(G1);

// static const uint32_t letters[] = {
//     letter_a,  letter_b,  letter_c,  letter_d,  letter_e,  letter_f,  letter_g,  letter_h,
//     letter_i,  letter_j,  letter_k,  letter_l,  letter_m,  letter_n,  letter_o,  letter_p,
//     letter_q,  letter_r,  letter_s,  letter_t,  letter_u,  letter_v,  letter_w,  letter_x,
//     letter_y,  letter_z,
//     0};

volatile int len_max = ngrids;
volatile char str[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void setup() {
    Serial.begin(9600);

#if VFD_USE_SPI
    SPI.begin();
#else
    pinMode(CLOCK, OUTPUT);
    pinMode(DATA,  OUTPUT);
#endif

    pinMode(LATCH, OUTPUT);

    Timer1.initialize(1e6 / (60 * ngrids));
    Timer1.attachInterrupt(renderString);
    Timer1.start();
    interrupts();
}

void loop() {
    static unsigned i = 0;
    while (Serial.available() > 0) {
        char c = Serial.read();
        // if ('a' <= c && c <= 'z')
        //     c &= ~(1 << 5);
        str[i % ngrids] = c;
        i++;
        Serial.print((int) c);
        Serial.print(" ");
        Serial.print(c);
        Serial.print(" ");
        Serial.println(ASCIITABLE[c]);
    }
}

inline void write_letter(uint32_t letter, uint32_t grids) {
    uint32_t buff = ~(letter | grids);
    digitalWrite(LATCH, HIGH);

#if VFD_USE_SPI
    SPI.beginTransaction(settings);
    SPI.transfer(buff >> 24);
    SPI.transfer(buff >> 16);
    SPI.transfer(buff >> 8);
    SPI.transfer(buff);
    SPI.endTransaction();
#else
    shiftOut(DATA, CLOCK, MSBFIRST, buff >> 24);
    shiftOut(DATA, CLOCK, MSBFIRST, buff >> 16);
    shiftOut(DATA, CLOCK, MSBFIRST, buff >> 8);
    shiftOut(DATA, CLOCK, MSBFIRST, buff);
#endif

    digitalWrite(LATCH, LOW);
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
}

inline void write_string(char *str) {
    for (int i = 0; i < ngrids; i++) {
        if (!str[i])
            return;
        // write_letter(letters[str[i] - 'A'], grids[i]);
        write_letter(ASCIITABLE[str[i]], grids[i]);
    }
}

void renderString(void) {
    volatile static unsigned pos = 0;
    write_letter(ASCIITABLE[str[pos % 9]], grids[pos % 9]);
    pos++;
}
