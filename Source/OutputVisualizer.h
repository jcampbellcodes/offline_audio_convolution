/*
  ==============================================================================

    AudioVisualizerController.h
    Created: 17 Sep 2017 5:41:09pm
    Author:  Jack Campbell

  ==============================================================================
*/

#pragma once

#include "./AudioVisualizerController.h"
#include "./ImpulseVisualizer.h"
#include "./InputVisualizer.h"

//==============================================================================
/*
*/



class OutputVisualizer    : public AudioVisualizerController
{
public:
    //AudioVisualizerController();
    OutputVisualizer(int width, int height, InputVisualizer* _input, ImpulseVisualizer* impulse);
    void 	filesDropped (const StringArray &files, int x, int y) override;
    void convolveInput();
private:
    InputVisualizer* input;
    ImpulseVisualizer* impulse;
    dsp::Convolution convolution;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputVisualizer)
};
