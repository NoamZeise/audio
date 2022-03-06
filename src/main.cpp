#include "audio.h"

#include <stdexcept>
#include <iostream>

int main()
{
	try{
		Audio::Manager audioManager;
		audioManager.Play("test.wav");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}