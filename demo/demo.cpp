#include <iostream>
#include <audio.h>

#include <string>
#include <chrono>
#include <thread>

int main() {
    std::cout << "--- Audio Demo ---\n";

    audio::Manager audio;
    std::string audioFile = "test.ogg";
    audio.Play(audioFile, false, 0.5f);
    std::cout << "Playing: " << audioFile << std::endl;
    std::cout << "Press Ctrl-C to stop\n";
    while(audio.Playing(audioFile)) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
