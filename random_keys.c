#include "random_keys.h"
#include "action.h"
#include "keymap_german.h"
#include <stdint.h>

static uint8_t get_rand(uint8_t max) {
#if defined(__AVR_ATmega32U4__)
  uint8_t output = (TCNT0 + TCNT1 + TCNT3 + TCNT4) % (max + 1);
#else
  uint8_t output = rand() % (max + 1);
#endif
  return output;
}

static void write_char(uint8_t code) {
  register_code(code);
  unregister_code(code);
}

void tap_random_binary() {
  write_char(9 * get_rand(1) + KC_1);
}

void tap_random_decimal() {
  write_char( KC_1 + get_rand(9) );
}

void tap_random_hexadecimal() {
  uint8_t key = get_rand(15);
  switch(key) {
    case 0 ... 9:
      write_char( KC_1 + key );
      break;
    case 10 ... 15:
      register_code(KC_LSFT);
      write_char( KC_A + key - 10 );
      unregister_code(KC_LSFT);
      break;
  }
}

void tap_random_german_base64() {
  uint8_t key = get_rand(63);
  switch(key) {
    case 0 ... 25:
      write_char( KC_A + key );
      break;
    case 26 ... 51:
      register_code(KC_LSFT);
      write_char( KC_A + key - 26 );
      unregister_code(KC_LSFT);
      break;
    case 52 ... 61:
      write_char( KC_1 + key - 52 );
      break;
    case 62:
      write_char(DE_PLUS);
      break;
    case 63:
      register_code(KC_LSFT);
      write_char(KC_7);
      unregister_code(KC_LSFT);
      break;
  }
}

void tap_random_binary_byte() {
  for(uint8_t i = 0; i < 8; i++) {
    tap_random_binary();
  }
}

void tap_random_decimal_byte() {
  uint8_t byte = get_rand(255);
  uint8_t counter = 0;
  if( byte == 0 ) {
    write_char(KC_0);
  }
  while( byte > 0 ) {
    uint8_t digit = byte % 10;
    switch(digit) {
      case 0:
	write_char(KC_0);
        break;
      case 1 ... 9:
	write_char( KC_1 + digit -1 );
	break;
    }
    write_char(KC_LEFT);
    byte = byte / 10;
    counter++;
  }
  for(uint8_t i = 0; i < counter; i++) {
    write_char(KC_RGHT);
  }
}

void tap_random_hexadecimal_byte() {
  tap_random_hexadecimal();
  tap_random_hexadecimal();
}

void tap_random_coinflip() {
  write_char(KC_BSPC);
  write_char(KC_APP);
  register_code(KC_LSFT);
  write_char(DE_DOT);
  write_char( DE_8 + get_rand(1) );
  unregister_code(KC_LSFT);
}

void tap_random_dice6() {
  register_code(DE_ALGR);
  write_char(DE_8);
  unregister_code(DE_ALGR);
  write_char( KC_1 + get_rand(5) );
  register_code(DE_ALGR);
  write_char(DE_9);
  unregister_code(DE_ALGR);
}
