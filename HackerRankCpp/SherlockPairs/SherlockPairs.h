#pragma once

#include "../SolutionBase.h"

namespace SherlockPairs {
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	class								Solution 
		: public						SolutionBase				{
		public:
										Solution					();
									   ~Solution					();

			int							main						();

			friend class				constructor;
			struct						constructor {
										constructor();
			};
			static constructor			static_init;
	};
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	class								Factory 
		: public						IFactory					{
		public:
			SolutionBase*				create						()								{ return new Solution(); }
	};
//	-----------------------------------	---------------------------	-------------------------------	--------------------
};