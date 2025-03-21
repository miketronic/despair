// Copyright 2024 
// miketronic@github m1ketronic@discord -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include_next <halconf.h>

#undef HAL_USE_SPI
#define HAL_USE_SPI TRUE

#include_next "halconf.h"
