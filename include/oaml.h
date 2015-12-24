#ifndef __OAML_H__
#define __OAML_H__


//
// Definitions
//

#define OAML_VOLUME_MIN	0
#define OAML_VOLUME_MAX	255

//
// Internal classes declaration
//

class ByteBuffer;
class oamlTrack;


//
// Main class
//

class oamlData {
private:
	int debug;
	oamlTrack *tracks[1024];
	int tracksN;

	oamlTrack *curTrack;

	ByteBuffer *dbuffer;

	int freq;
	int channels;
	int bytesPerSample;

	int tension;
	uint64_t tensionMs;
	int volume;

	uint64_t timeMs;

public:
	oamlData();
	~oamlData();

	int Init(const char *pathToMusic);
	void Shutdown();

	void SetAudioFormat(int audioFreq, int audioChannels, int audioBytesPerSample);
	void SetVolume(int vol);

	int PlayTrack(const char *name);
	int PlayTrackId(int id);

	void StopPlaying();

	bool IsTrackPlaying(const char *name);
	bool IsTrackPlayingId(int id);
	bool IsPlaying();

	void AddTension(int value);

	void SetCondition(int id, int value);

	void MixToBuffer(void *buffer, int size);

	void Update();
};

#endif /* __OAML_H__ */
