//
//  main.c
//  HeavyPortAudio
//
//  Created by Joe White on 30/07/2015.
//  Copyright (c) 2015 Enzien Audio. All rights reserved.
//

/*
 * This is an example program using Heavy, PortAudio and libsndfile to read
 * the contents of a file, process it through a heavy patch and send it to the
 * output. 
 * 
 * Expected data I/O format here are interleaved short values.
 */

#include <stdio.h>
#include "sndfile.h"
#include "portaudio.h"
#include "Heavy_ExamplePatch1.h"


// UserData struct to be passed to the audio callback
typedef struct {
  Hv_ExamplePatch1 *hvContext;
  short *fileBuffer;
  unsigned long fileNumFrames;
  unsigned long fileIndex;
} UserData;


// Helper methods
int check_sf_error(int tag, int error, SNDFILE *file);
int check_pa_error(int tag, PaError error);


// Main Audio Processing Callback
static int paCallback(const void *input, void *output,
    unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags, void *userData)
{
  UserData *data = (UserData *) userData;
  short *out = (short *) output;

  // calculate num frames left to read
  long numFramesLeft = data->fileNumFrames - data->fileIndex;
  long numFramesToRead = (numFramesLeft < frameCount) ? numFramesLeft : frameCount;

  // process buffers through heavy patch
  // expected data format here is interleaved short buffers
  // i.e: L R L R L R ...
  numFramesToRead = hv_ExamplePatch1_process_inline_short(data->hvContext,
      data->fileBuffer+data->fileIndex, out, (int) numFramesToRead);

  // increment read index
  data->fileIndex += numFramesToRead;
  
  return (data->fileIndex >= data->fileNumFrames) ? paComplete : paContinue;
}


int main(int argc, const char * argv[]) {

  UserData data = { NULL, NULL, 0, 0 };
  
  // Get input file path
  if (argc < 2) {
    printf("Invalid number of arguments:\n usage $ ./HeavyPortAudio /path/to/file.wav\n");
    return 1;
  }
  const char *inFilePath = argv[1];
  
  // Setup libsndfile
  SF_INFO info = {};
  SNDFILE *file = sf_open(inFilePath, SFM_READ, &info);
  if (check_sf_error(0, 0, file)) return 1;
  
  printf("Opening file:\n - filepath: %s\n - samplerate: %d\n - numchannels: %d\n - numframes: %lld\n\n",
      inFilePath, info.samplerate, info.channels, info.frames);
  
  // Load file contents into buffer
  data.fileNumFrames = info.frames;
  data.fileBuffer = (short *) malloc(data.fileNumFrames * info.channels * sizeof(short));
  sf_count_t framesRead = sf_read_short(file, data.fileBuffer, info.frames);
  if (framesRead != info.frames) {
    printf("Incorrect number of frames read (%lld) from file\n", framesRead);
  }

  const double sampleRate = (double) info.samplerate;
  const unsigned long blockSize = 256;

  // Setup PortAudio
  if (check_pa_error(1, Pa_Initialize())) return 1;
  
  // Setup Heavy context
  data.hvContext = hv_ExamplePatch1_new(sampleRate);

  printf("Instantiated heavy context:\n - numInputChannels: %d\n - numOutputChannels: %d\n\n",
      hv_getNumInputChannels(data.hvContext), hv_getNumOutputChannels(data.hvContext));
  
  // Opening stream
  PaStream *stream = NULL;
  if (check_pa_error(2,
      Pa_OpenDefaultStream(&stream, 0, hv_getNumOutputChannels(data.hvContext),
          paInt16, sampleRate, blockSize, paCallback, &data))) {
    return 1;
  }

  // Start Processing
  if (check_pa_error(3, Pa_StartStream(stream))) return 1;

  while (Pa_IsStreamActive(stream)) {
    Pa_Sleep(1000);
  }
  
  // Stop Processing
  if (check_pa_error(5, Pa_CloseStream(stream))) return 1;
  
  // Teardown
  hv_ExamplePatch1_free(data.hvContext);

  if (check_sf_error(6, sf_close(file), file)) return 1;

  if (check_pa_error(7, Pa_Terminate())) return 1;

  printf("Success\n");
  return 0;
}


int check_sf_error(int tag, int error, SNDFILE *file) {
  if (error || file == NULL) {
    printf("(#%d libsndfile error) %s\n", tag, sf_strerror(file));
    return 1;
  }
  return 0;
}


int check_pa_error(int tag, PaError error) {
  if (error != paNoError) {
    printf("(#%d portaudio error) %s\n", tag, Pa_GetErrorText(error));
    return 1;
  }
  return 0;
}
