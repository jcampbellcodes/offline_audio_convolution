/*
  ==============================================================================

    InputVisualizer.cpp
    Created: 17 Nov 2017 10:16:48am
    Author:  Jack Campbell

  ==============================================================================
*/

#include "InputVisualizer.h"

InputVisualizer::InputVisualizer(int width, int height) : AudioVisualizerController(width, height) {};


// input just sets the input file and visualizes
void InputVisualizer::filesDropped (const StringArray &files, int, int)
{
    printf("file name: %s", files[0].toRawUTF8());
    File file(files[0]);
    this->_audioFile = file;
    thumbnail.setSource (new FileInputSource (file));          // [7]
    
}
