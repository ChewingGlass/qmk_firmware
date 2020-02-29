#pragma once

#include "dactyl_manuform.h"

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
	L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
	L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
	L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
	     L31, L32,                                         R32, R33,      \
                       L30,                         R34,                \
                               L41, L42, R41, R40,                          \
                               L44, L43, R43, R42                           \
	) \
	{ \
		{ L00, L01, L02, L03, L04 }, \
		{ L10, L11, L12, L13, L14 }, \
		{ L20, L21, L22, L23, L24 }, \
		{ L30, L31, L32, KC_NO, KC_NO }, \
		{ KC_NO, L41, L42, L43, L44 }, \
\
		{ R04, R03, R02, R01, R00 },    \
		{ R14, R13, R12, R11, R10 },    \
		{ R24, R23, R22, R21, R20 },    \
		{ KC_NO, R33, R32, KC_NO, KC_NO },  \
		{ KC_NO, R43, R42, R41, R40 }  \
	}

