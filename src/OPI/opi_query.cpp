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
#include "opi_query.h"
#include "opi_host.h"
namespace OPI
{
	//! \cond INTERNAL_DOCUMENTATION
	class DistanceQueryImpl
	{
		public:
	};
	//! \endcond

	DistanceQuery::DistanceQuery()
	{
	}

	DistanceQuery::~DistanceQuery()
	{
	}

	ErrorCode DistanceQuery::rebuild(Population &data)
	{
		if(data.getSize() == 0)
			return SUCCESS;
		ErrorCode status;
		// ensure this DistanceQuery is enabled
		status = enable();
		// an error occured?
		if(status == SUCCESS)
			status = runRebuild(data);
		// forward propagation call
		getHost()->sendError(status);
		return status;
	}

	ErrorCode DistanceQuery::queryCubicPairs(Population &data, IndexPairList& pairs, float cube_size)
	{
		if(data.getSize() == 0)
			return SUCCESS;
		ErrorCode status;
		// ensure this DistanceQuery is enabled
		status = enable();
		// an error occured?
		if(status == SUCCESS)
			status = runCubicPairQuery(data, pairs, cube_size);
		getHost()->sendError(status);
		// forward propagation call
		return status;
	}

	void DistanceQuery::debugDraw()
	{
		if(isEnabled())
			runDebugDraw();
	}

	void DistanceQuery::runDebugDraw()
	{

	}
}
