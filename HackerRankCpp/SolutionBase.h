#pragma once
 
#include <map>

class SolutionBase;

//	-----------------------------------	---------------------------	-------------------------------	--------------------
	class								IFactory {
		public:
			virtual
			SolutionBase *				create						();
	};
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	typedef std::map<char *, IFactory *> SolutionFactory;
//	-----------------------------------	---------------------------	-------------------------------	--------------------
	class								SolutionBase				{
		public:
										SolutionBase				();
									   ~SolutionBase				();
		virtual
		int								main						();

		static	SolutionFactory&     	solutionFactory				();									//	Avoid	unpredictable static initialization order


		friend class					static_constructor;
			struct					    static_constructor {
										static_constructor();
			};

		static static_constructor		static_init;

	};
//	-----------------------------------	---------------------------	-------------------------------	--------------------





