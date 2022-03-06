#ifndef AUDIO_H
#define AUDIO_H

#include <sndfile.h>
#include <portaudio/portaudio.h>

#include <stdexcept>
#include <string>
#include <vector>
#include <utility>
#include <map>

#include <iostream>

namespace Audio
{

namespace {

const int FRAMES_PER_BUFFER = 512;

struct AudioData
{
	AudioData()
	{
		data = nullptr;
		sampleCount = 0;
	}
	AudioData(std::string filename)
	{
		SNDFILE* file = sf_open(filename.c_str(), SFM_READ, &this->info);
    	if (sf_error(file) != SF_ERR_NO_ERROR) 
			throw std::runtime_error("failed to load audio data at " + filename);
		this->sampleCount = info.frames * info.channels;
		this->data = new float[sampleCount];
		if(sf_readf_float(file, this->data, info.frames) != info.frames)
		{
			sf_close(file);
			throw std::runtime_error("incorect num of sampels loaded from audio data at " + filename);
		}
		sf_close(file);
	}
	~AudioData()
	{
		delete[] data;
	}
	float* data;
	SF_INFO  info;
	sf_count_t sampleCount;
};

struct Instance
{
	Instance(AudioData* audio)
	{
		this->audio = audio;
	}
	AudioData* audio;
	int current = 0;
	PaStream *stream;
};

static int soundCallback(const void *input, void *output,
						 unsigned long framesPerBuffer,
						 const PaStreamCallbackTimeInfo* time,
						 PaStreamCallbackFlags statusFlags,
						 void *userData)
{
	Instance *data = (Instance*)userData;
	float *out = (float*)output;
	std::cout << "here" << std::endl;
	memset(out, 0, sizeof(float) * framesPerBuffer * data->audio->info.channels);
	for (unsigned int i = 0; i < framesPerBuffer * data->audio->info.channels; i++ )
    {
		std::cout << "inner" << std::endl;
		if (data->current >= data->audio->sampleCount)
			return paComplete;
					std::cout << "copy" << std::endl;	
		out[i] = data->audio->data[data->current++];
					std::cout << "copycomplete" << std::endl;
    }
			std::cout << "end" << std::endl;
	return paContinue;
}

} //unnamed namespace end

class Manager
{
public:
	Manager() 
	{
		if(sizeof(float) != 4)
			throw std::runtime_error("float must be 32bit");
		PaError err;
		err = Pa_Initialize();
		if(err != paNoError) throw std::runtime_error("Failed to initialize Port Audio\n Err: " + std::string(Pa_GetErrorText(err)));
	}
	~Manager()
	{
		PaError err;
		err = Pa_Terminate();
		//if(err != paNoError) throw std::runtime_error("failed to terminate Port Audio");
	}

	void loadAudioFile(std::string filename)
	{
		loaded[filename] = AudioData(filename);
	}
	
	void Play(std::string filename)
	{
		if(loaded.count(filename) == 0)
		{
			this->loadAudioFile(filename);
		}
		activeAudio.push_back(Instance(&loaded[filename]));
		Instance* instance = &activeAudio[activeAudio.size() - 1];

		PaError err = Pa_OpenDefaultStream(&instance->stream,
											0,
											instance->audio->info.channels,
											paFloat32,
											instance->audio->info.samplerate,
											FRAMES_PER_BUFFER,
											soundCallback,
											instance);
		if(err != paNoError) 
			throw std::runtime_error("failed to open default stream for file at " + filename);

		err = Pa_StartStream(instance->stream);
		if(err != paNoError)
			throw std::runtime_error("failed to start stream at " + filename);
		
		while(Pa_IsStreamActive(instance->stream))
    	{
        	Pa_Sleep(100);
    	}

		std::cout << instance->current << std::endl;

		err = Pa_CloseStream(instance->stream);
		if(err != paNoError) throw std::runtime_error("failed to close stream"); 
		activeAudio.erase(activeAudio.begin());
	}
private:
	std::map<std::string, AudioData> loaded;
	std::vector<Instance> activeAudio; 
};

} //audio namespace end

#endif