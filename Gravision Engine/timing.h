#pragma once
struct TimingData
{
	//current frame since application started
	unsigned frameNumber;

	//the timestamp when the last frame ended
	unsigned lastFrameStamp;

	//the length of the last frame in millis
	unsigned lastFrameDuration;

	//The clockstamp of the end of the last frame.
	unsigned long lastFrameClockStamp;

	//the length of the laste frame in clock ticks
	unsigned long lastFrameClockDuration;

	//is rendering paused
	bool isPaused;

	//average frame length
	double averageFrameDuration;

	//frames per second
	float fps;

	//Gets the global timing data object.
	static TimingData& get();

	//Updates the timing system, should be called once per frame.
	static void update();

	//Initialises the frame information system. Use the overall
	static void init();

	//Deinitialises the frame information system.
	static void deinit();

	// Gets the global system time, in the best resolution possible. Timing is in milliseconds.
	static unsigned getTime();

	//Gets the clock ticks since process start.
	static unsigned long getClock();


private:
	// These are private to stop instances being created: use get().
	TimingData() {}
	TimingData(const TimingData &) {}
	TimingData& operator=(const TimingData &);
};

