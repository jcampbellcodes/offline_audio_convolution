/*
  ==============================================================================

    AudioVisualizerController.h
    Created: 17 Sep 2017 5:41:09pm
    Author:  Jack Campbell

  ==============================================================================
*/

#pragma once

#include "./AudioVisualizerController.h"

//==============================================================================
/*
*/



class InputVisualizer    : public AudioVisualizerController
{
public:
    //AudioVisualizerController();
    InputVisualizer(int width, int height);
    void 	filesDropped (const StringArray &files, int x, int y) override;
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputVisualizer)
};
