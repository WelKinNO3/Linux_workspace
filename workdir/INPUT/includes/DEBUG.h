#ifndef _DEBUG_H
#define _DEBUG_H

#include "stdio.h"

#define MODEL_DEBUG	0x00
#define MODEL_LAUNCH	0x01

//#define MODEL_STATUS	MODEL_DEBUG
  #define MODEL_STATUS  MODEL_LAUNCH

typedef enum
{
	Contral_OPEN ,
	Contral_CLOSE
}Contral_Enum;

typedef enum
{
	Model_Debug ,
	Model_Launch
}Model_Enum;


#endif
