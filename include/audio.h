#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <vector>
#include <map>

namespace audio
{
    //internal, dont use
    struct AudioData;
    struct Instance;

class Manager
{
public:
    Manager();
    ~Manager();

    void RemovePlayed();

//optional, can frontload loading to make Play() faster the first time on a file
    void LoadAudioFile(std::string filename);
    void Play(std::string filename, bool loop, float volume);

    void Resume(std::string filename);

    void Pause(std::string filename);

    void Stop(std::string filename);

    void StopAll();
    void SetVolume(std::string filename, float volume);
    bool Playing(std::string filename);

private:
	std::map<std::string, AudioData*> loaded;
	std::vector<Instance*> activeAudio;
};

} //audio namespace end

#endif
