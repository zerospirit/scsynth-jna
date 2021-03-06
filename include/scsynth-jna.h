#ifndef _SCSYTNH_JNA_
#define _SCSYNTH_JNA__

#include <stdarg.h>
#include "SC_Types.h"

#if defined(SC_DARWIN) || defined(SC_IPHONE)
#include <CoreFoundation/CFString.h>
#endif

#include "SC_Reply.h"

#ifdef SC_WIN32
# define SC_DLLEXPORT __declspec(dllexport)
#else
# define SC_DLLEXPORT
#endif

struct ScsynthJnaStartOptions
{
  int32 verbosity;
  const char* UGensPluginPath;
  const char* inDeviceName;
  const char* outDeviceName;
  uint32 numControlBusChannels;
  uint32 numAudioBusChannels;
  uint32 numInputBusChannels;
  uint32 numOutputBusChannels;
  uint32 bufLength;
  uint32 preferredHardwareBufferFrameSize;
  uint32 preferredSampleRate;
  uint32 numBuffers;
  uint32 maxNodes;
  uint32 maxGraphDefs;
  uint32 realTimeMemorySize;
  uint32 maxWireBufs;
  uint32 numRGens;
};

extern "C" {
  SC_DLLEXPORT ScsynthJnaStartOptions* scsynth_jna_get_default_start_options();
  SC_DLLEXPORT int scsynth_jna_get_device_count();
  SC_DLLEXPORT const char* scsynth_jna_get_device_name(int i);
  SC_DLLEXPORT int scsynth_jna_get_device_max_input_channels(int i);
  SC_DLLEXPORT int scsynth_jna_get_device_max_output_channels(int i);
    
  SC_DLLEXPORT int scsynth_jna_init();	
  SC_DLLEXPORT World* scsynth_jna_start(ScsynthJnaStartOptions *options);	  
  SC_DLLEXPORT void scsynth_jna_cleanup();
  SC_DLLEXPORT struct SndBuf * scsynth_jna_copy_sndbuf(World *world, uint32 index);  
}

#endif // _SCSYNTH_JNA__
