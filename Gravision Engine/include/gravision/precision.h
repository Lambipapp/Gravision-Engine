#pragma once
#include <gravision/core.h>
#include <float.h>
#include <math.h>

namespace gravision {
#if 1
	#define SINGLE_PRECISION
	//real uses single pressision floating points for now
	typedef float real;

	// Defines the precision of the square root operator. 
	#define real_sqrt sqrtf

	//Defines the precision of the poweropperator to match the float data type
	#define real_pow powf
#else

	#define DOUBLE_PRECISION
	typedef double real;
	#define real_sqrt sqrt
	#define real_pow pow
#endif
}