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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "InputSignalDragDrop.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
InputSignalDragDrop::InputSignalDragDrop ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("FIR"));
    comboBox->addItem (TRANS("FIR"), 1);
    comboBox->addItem (TRANS("FFT"), 2);
    comboBox->addSeparator();
    comboBox->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("input signal")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("impulse response")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("output")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("play"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0xff13c607));

    addAndMakeVisible (textButton2 = new TextButton ("new button"));
    textButton2->setButtonText (TRANS("stop"));
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colours::crimson);

    addAndMakeVisible (textButton3 = new TextButton ("new button"));
    textButton3->setButtonText (TRANS("save..."));
    textButton3->addListener (this);
    textButton3->setColour (TextButton::buttonColourId, Colour (0xff0611d0));

    addAndMakeVisible (textButton4 = new TextButton ("new button"));
    textButton4->setButtonText (TRANS("generate"));
    textButton4->addListener (this);
    textButton4->setColour (TextButton::buttonColourId, Colour (0xff680086));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("offline convolver")));
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (input_signal = new AudioVisualizerController (320, 160));
    input_signal->setName ("input signal");

    addAndMakeVisible (impulse_response = new AudioVisualizerController (320, 160));
    impulse_response->setName ("impulse response");

    addAndMakeVisible (convolved_signal = new AudioVisualizerController (528, 144));
    convolved_signal->setName ("convolved signal");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

InputSignalDragDrop::~InputSignalDragDrop()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comboBox = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;
    label4 = nullptr;
    input_signal = nullptr;
    impulse_response = nullptr;
    convolved_signal = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void InputSignalDragDrop::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff7000e7));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void InputSignalDragDrop::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    comboBox->setBounds (560, 0, 150, 24);
    label->setBounds (88, 48, 88, 24);
    label2->setBounds (464, 48, 112, 24);
    label3->setBounds (312, 312, 48, 24);
    textButton->setBounds (96, 504, 150, 24);
    textButton2->setBounds (272, 504, 150, 24);
    textButton3->setBounds (464, 504, 150, 24);
    textButton4->setBounds (288, 272, 104, 24);
    label4->setBounds (280, 152, 112, 24);
    input_signal->setBounds (8, 80, 264, 160);
    impulse_response->setBounds (392, 80, 264, 160);
    convolved_signal->setBounds (88, 344, 528, 144);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void InputSignalDragDrop::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void InputSignalDragDrop::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2)
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4)
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="InputSignalDragDrop" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="600">
  <BACKGROUND backgroundColour="ff7000e7"/>
  <COMBOBOX name="new combo box" id="2df48afdde95becd" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="560 0 150 24" editable="0"
            layout="33" items="FIR&#10;FFT&#10;" textWhenNonSelected="" textWhenNoItems="FIR"/>
  <LABEL name="new label" id="7e501145e4d68d84" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="88 48 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="input signal" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="3a2472127aa01e06" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="464 48 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="impulse response" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="947256eccf805144" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="312 312 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="output" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="9828601046c46721" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="96 504 150 24" bgColOff="ff13c607"
              buttonText="play" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e403bf2fb01af142" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="272 504 150 24" bgColOff="ffdc143c"
              buttonText="stop" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="aa9a7381001db93b" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="464 504 150 24" bgColOff="ff0611d0"
              buttonText="save..." connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="54b07578b1563b5e" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="288 272 104 24" bgColOff="ff680086"
              buttonText="generate" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="155bf9d0f038cd6e" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="280 152 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="offline convolver" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="input signal" id="40a5ca03491cd6a1" memberName="input_signal"
                    virtualName="" explicitFocusOrder="0" pos="8 80 264 160" class="AudioVisualizerController"
                    params="320, 160"/>
  <GENERICCOMPONENT name="impulse response" id="d326fe927b8ccec" memberName="impulse_response"
                    virtualName="" explicitFocusOrder="0" pos="392 80 264 160" class="AudioVisualizerController"
                    params="320, 160"/>
  <GENERICCOMPONENT name="convolved signal" id="bf0184a07e7f25db" memberName="convolved_signal"
                    virtualName="" explicitFocusOrder="0" pos="88 344 528 144" class="AudioVisualizerController"
                    params="528, 144"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
