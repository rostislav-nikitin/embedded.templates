#include "startup.hpp"

int main()
{
	// Configure different stuff
	
	AppBuilder builder;

	App app = builder
			.setParam1()
			.setParam2()
			.build();
	
	app.run();
}
