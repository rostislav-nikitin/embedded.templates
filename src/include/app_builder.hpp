#ifndef __APP_BUILDER_HPP__
#define __APP_BUILDER_HPP__

#include "app.hpp"

class AppBuilder
{
public:
	AppBuilder &setParam1();
	AppBuilder &setParam2();

	App build();
};

#endif
