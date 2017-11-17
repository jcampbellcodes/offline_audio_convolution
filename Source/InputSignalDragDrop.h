/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#ifndef INPUTDRAGDROP
#define INPUTDRAGDROP
#include "../JuceLibraryCode/JuceHeader.h"
#include "./InputVisualizer.h"
#include "./ImpulseVisualizer.h"
#include "./OutputVisualizer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class InputSignalDragDrop  : public Component,
                             public ComboBoxListener,
                             public ButtonListener
{
public:
    //==============================================================================
    InputSignalDragDrop ();
    ~InputSignalDragDrop();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    //AudioVisualizerController inputSignal;
    //AudioVisualizerController impulseResponse;
    //AudioVisualizerController convolvedSignal;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<TextButton> play_btn;
    ScopedPointer<TextButton> stop_btn;
    ScopedPointer<TextButton> textButton3;
    ScopedPointer<TextButton> generate_btn;
    ScopedPointer<Label> label4;
    ScopedPointer<InputVisualizer> input_signal;
    ScopedPointer<ImpulseVisualizer> impulse_response;
    ScopedPointer<OutputVisualizer> convolved_signal;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputSignalDragDrop)
};

//[EndFile] You can add extra defines here...
#endif
//[/EndFile]
