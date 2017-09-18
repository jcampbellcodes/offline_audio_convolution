/*
  ==============================================================================

    AudioVisualizerModel.cpp
    Created: 17 Sep 2017 5:40:57pm
    Author:  Jack Campbell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioVisualizerModel.h"

//==============================================================================
AudioVisualizerModel::AudioVisualizerModel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AudioVisualizerModel::~AudioVisualizerModel()
{
}

void AudioVisualizerModel::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("AudioVisualizerModel", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void AudioVisualizerModel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void AudioVisualizerModel::setAudioFile(const juce::File &file)
{
    AudioFormatReader* reader = nullptr;//formatManager.createReaderFor (file);
    
    if (reader != nullptr)
    {
        ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource (reader, true);
        transportSource.setSource (newSource, 0, nullptr, reader->sampleRate);
        readerSource = newSource.release();
    }
}
