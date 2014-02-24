#include "CrappyCraft.h"
#include <Windows.h>

int CrappyCraft::Main(std::vector<std::string> &arguments)
{
	
	return 0;
}

int main(int argc, char **argv)
{
	std::vector<std::string> arguments(argv, argv + argc);
	return CrappyCraft().Main(arguments);
}