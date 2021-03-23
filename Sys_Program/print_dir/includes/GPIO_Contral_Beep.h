#ifndef _GPIO_CONTRAL_BEEP_H
#define _GPIO_CONTRAL_BEEP_H
#include "stdio.h"
#include "DEBUG.h"
#define BEEP_GPIO_INDEX		"19"

#define GPIO_CONTRAL_INDEX	BEEP_GPIO_INDEX

#if (MODEL_STATUS)
	#define GPIO_DIRECTORY		"/sys/class/gpio/export"
	#define GPIO_CONTRAL		"/sys/class/gpio"
#else
	#define GPIO_DIRECTORY		"./export.txt"
#endif

int beep_initial();

int beep_contral(
			Contral_Enum Operation_L
		);


#endif
