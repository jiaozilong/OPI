/* OPI: Orbital Propagation Interface
 * Copyright (C) 2014 Institute of Aerospace Systems, TU Braunschweig, All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */
#include "opi_error.h"

namespace OPI
{
	const char* ErrorMessage(int code)
	{
		switch(code)
		{
			case SUCCESS:
				return "No error";
			case INVALID_ARGUMENT:
				return "Invalid argument";
			case UNKNOWN_VARIABLE:
				return "Unknown variable";
			case INDEX_RANGE:
				return "Index out of range";
			case INVALID_TYPE:
				return "Invalid type";
			case DIRECTORY_NOT_FOUND:
				return "Directory not found";
			case INVALID_DEVICE:
				return "Invalid device";
			case INVALID_PROPERTY:
				return "Invalid property";
			case INCOMPATIBLE_TYPES:
				return "INCOMPATIBLE_TYPES";
			case NOT_IMPLEMENTED:
				return "Not implemented";
			case CUDA_REQUIRED:
				return "CUDA Required";
			case CUDA_OLDVERSION:
				return "CUDA version too old";
			case UNKNOWN_ERROR:
				break;
//			default:

		}
		return "Unknown error";
	}
}

extern "C"
{
	const char* OPI_ErrorMessage(int code)
	{
		return OPI::ErrorMessage(code);
	}
}
