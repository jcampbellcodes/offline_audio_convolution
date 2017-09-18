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
InputSignalDragDrop::InputSignalDragDrop () : inputSignal(), impulseResponse(), convolvedSignal()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (input_viewport = new Viewport ("input signal"));

    addAndMakeVisible (ir_viewport = new Viewport ("impulse response"));

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

    addAndMakeVisible (convolved_viewport = new Viewport ("convolved signal"));

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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    
    input_viewport->setViewedComponent(&this->inputSignal, false);
    addAndMakeVisible(input_viewport);
    //addAndMakeVisible(<#juce::Component *child#>)
    ir_viewport->setViewedComponent(&this->impulseResponse, false);
    convolved_viewport->setViewedComponent(&this->convolvedSignal, false);
    
    //[/Constructor]
}

InputSignalDragDrop::~InputSignalDragDrop()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    
    input_viewport = nullptr;
    ir_viewport = nullptr;
    comboBox = nullptr;
    label = nullptr;
    label2 = nullptr;
    convolved_viewport = nullptr;
    label3 = nullptr;
    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;
    label4 = nullptr;


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

    input_viewport->setBounds (0, 72, 304, 184);
    ir_viewport->setBounds (384, 72, 320, 184);
    comboBox->setBounds (560, 0, 150, 24);
    label->setBounds (0, 48, 150, 24);
    label2->setBounds (376, 48, 216, 24);
    convolved_viewport->setBounds (56, 344, 600, 150);
    label3->setBounds (304, 312, 150, 24);
    textButton->setBounds (96, 504, 150, 24);
    textButton2->setBounds (272, 504, 150, 24);
    textButton3->setBounds (464, 504, 150, 24);
    textButton4->setBounds (272, 272, 150, 24);
    label4->setBounds (288, 0, 112, 24);
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
  <VIEWPORT name="input signal" id="683644b7bcaffab7" memberName="input_viewport"
            virtualName="" explicitFocusOrder="0" pos="0 72 304 184" vscroll="1"
            hscroll="1" scrollbarThickness="8" contentType="0" jucerFile=""
            contentClass="" constructorParams=""/>
  <VIEWPORT name="impulse response" id="cadad4d8a9d66381" memberName="ir_viewport"
            virtualName="" explicitFocusOrder="0" pos="384 72 320 184" vscroll="1"
            hscroll="1" scrollbarThickness="8" contentType="0" jucerFile=""
            contentClass="" constructorParams=""/>
  <COMBOBOX name="new combo box" id="2df48afdde95becd" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="560 0 150 24" editable="0"
            layout="33" items="FIR&#10;FFT&#10;" textWhenNonSelected="" textWhenNoItems="FIR"/>
  <LABEL name="new label" id="7e501145e4d68d84" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 48 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="input signal" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="3a2472127aa01e06" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="376 48 216 24" edTextCol="ff000000"
         edBkgCol="0" labelText="impulse response" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <VIEWPORT name="convolved signal" id="2a534b4cd8d3d430" memberName="convolved_viewport"
            virtualName="" explicitFocusOrder="0" pos="56 344 600 150" vscroll="1"
            hscroll="1" scrollbarThickness="8" contentType="0" jucerFile=""
            contentClass="" constructorParams=""/>
  <LABEL name="new label" id="947256eccf805144" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="304 312 150 24" edTextCol="ff000000"
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
              virtualName="" explicitFocusOrder="0" pos="272 272 150 24" bgColOff="ff680086"
              buttonText="generate" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="155bf9d0f038cd6e" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="288 0 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="offline convolver" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
