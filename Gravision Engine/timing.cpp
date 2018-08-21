#include "timing.h"

#include <windows.h>
#include <mmsystem.h>

static double qpcFrequency;

// Hold internal timing data for the performance counter.
static bool qpcFlag;

// Holds the global frame time that is passed around
static TimingData *timingData = NULL;


void initTime()
{

	LONGLONG time;

	qpcFlag = (QueryPerformanceFrequency((LARGE_INTEGER*)&time) > 0);

	// Check if we have access to the performance counter at this
	// resolution.
	if (qpcFlag) qpcFrequency = 1000.0 / time;

}
unsigned long systemClock()
{
	__asm {
		rdtsc;
	}
}
unsigned systemTime()
{

	if (qpcFlag)
	{
		static LONGLONG qpcMillisPerTick;
		QueryPerformanceCounter((LARGE_INTEGER*)&qpcMillisPerTick);
		return (unsigned)(qpcMillisPerTick * qpcFrequency);
	}
	else
	{
		return unsigned(timeGetTime());
	}

}

TimingData & TimingData::get()
{
	// TODO: insert return statement here
}

void TimingData::update()
{
}

void TimingData::init()
{
	// Set up the timing system.
	initTime();

	// Create the frame info object
	if (!timingData) timingData = new TimingData();

	// Set up the frame info structure.
	timingData->frameNumber = 0;

	timingData->lastFrameStamp = systemTime();
	timingData->lastFrameDuration = 0;

	timingData->lastFrameClockStamp = getClock();
	timingData->lastFrameClockDuration = 0;

	timingData->isPaused = false;

	timingData->averageFrameDuration = 0;
	timingData->fps = 0;
}

void TimingData::deinit()
{
}

unsigned TimingData::getTime()
{
	return 0;
}

unsigned long TimingData::getClock()
{
	return 0;
}

TimingData & TimingData::operator=(const TimingData &)
{
	// TODO: insert return statement here
}
