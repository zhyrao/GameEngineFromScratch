#include "BaseApplication.hpp"

// parse command line, read configuration, 
// initialzie all sub modules
int My::BaseApplication::Initialize()
{
	m_bQuit = false;

	return 0;
}

// Finalize all sub modules and clean 
// up all runtime temporary files.
void My::BaseApplication::Finalize()
{

}

// main loop
void My::BaseApplication::Tick()
{

}

bool My::BaseApplication::IsQuit()
{
	return m_bQuit;
}