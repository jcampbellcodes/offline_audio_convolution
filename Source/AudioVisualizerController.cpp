/*
  ==============================================================================

    AudioVisualizerController.cpp
    Created: 17 Sep 2017 5:41:09pm
    Author:  Jack Campbell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioVisualizerController.h"

//==============================================================================
AudioVisualizerController::AudioVisualizerController() : _model(), thumbnailCache(1), thumbnail(515, formatManager, thumbnailCache)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    formatManager.registerBasicFormats();
    
    this->thumbnail.addChangeListener(this);
    setSize (400, 600);
}

AudioVisualizerController::AudioVisualizerController(int width, int height) : _model(), thumbnailCache(1), thumbnail(515, formatManager, thumbnailCache)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    formatManager.registerBasicFormats();
    
    this->thumbnail.addChangeListener(this);
    setSize (width, height);
}

AudioVisualizerController::~AudioVisualizerController()
{
    this->thumbnail.clear();
}

void AudioVisualizerController::paint (Graphics& g)
{
    const Rectangle<int> thumbnailBounds (0, 0, getWidth(), getHeight());
    
    if (thumbnail.getNumChannels() == 0)
    {
        g.setColour (Colours::darkgrey);
        g.fillRect (thumbnailBounds);
        g.setColour (Colours::white);
        g.drawFittedText ("No File Loaded", thumbnailBounds, Justification::centred, 1.0f);
    }
    else
    {
        g.setColour (Colours::white);
        g.fillRect (thumbnailBounds);
        
        g.setColour (Colours::red);                                     // [8]
        
        thumbnail.drawChannels (g,                                      // [9]
                                thumbnailBounds,
                                0.0,                                    // start time
                                thumbnail.getTotalLength(),             // end time
                                1.0f);                                  // vertical zoom
    }
}

void AudioVisualizerController::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

bool AudioVisualizerController::isInterestedInFileDrag (const StringArray &files)
{
    printf("interested in file drag");
    return true;
}
void AudioVisualizerController::filesDropped (const StringArray &files, int, int)
{
    printf("file name: %s", files[0].toRawUTF8());
    File file(files[0]);
    AudioFormatReader* reader = formatManager.createReaderFor (file);
    
    if (reader != nullptr)
    {
        ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource (reader, true);
        transportSource.setSource (newSource, 0, nullptr, reader->sampleRate);
        //playButton.setEnabled (true);
        thumbnail.setSource (new FileInputSource (file));          // [7]
        readerSource = newSource.release();
    }
    //this->_model.setAudioFile(file);
   
}

void AudioVisualizerController::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source == &transportSource)
    {
        if (transportSource.isPlaying())
            changeState (Playing);
        else
            changeState (Stopped);
    }
    
    
    if (source == &thumbnail)        thumbnailChanged();
}

void AudioVisualizerController::changeState(TransportState newState)
{
    if (state != newState)
    {
        state = newState;
        
        switch (state)
        {
            case Stopped:                           // [3]
                //stopButton.setEnabled (false);
                //playButton.setEnabled (true);
                transportSource.setPosition (0.0);
                break;
                
            case Starting:                          // [4]
                //playButton.setEnabled (false);
                transportSource.start();
                break;
                
            case Playing:                           // [5]
                //stopButton.setEnabled (true);
                break;
                
            case Stopping:                          // [6]
                transportSource.stop();
                break;
        }
    }
}

void AudioVisualizerController::thumbnailChanged()
{
    repaint();
}
