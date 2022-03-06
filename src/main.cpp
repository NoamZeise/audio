#include "audio.h"


int main()
{
  Audio::Manager manager;

  manager.Play("test.wav", false, 1.0f);
}
