/*
  ==============================================================================

    InputVisualizer.cpp
    Created: 17 Nov 2017 10:16:48am
    Author:  Jack Campbell

  ==============================================================================
*/

#include "ImpulseVisualizer.h"
#include "AudioPlayer.h"

ImpulseVisualizer::ImpulseVisualizer(int width, int height) : AudioVisualizerController(width, height) {};

// input just sets the impulse response file and visualizes
void ImpulseVisualizer::filesDropped (const StringArray &files, int, int)
{
    printf("file name: %s", files[0].toRawUTF8());
    File file(files[0]);
    this->_audioFile = file;
    AudioPlayer::setImpulseFile(file);
    thumbnail.setSource (new FileInputSource (file));          // [7]
    
}
