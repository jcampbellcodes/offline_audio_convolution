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
AudioVisualizerController::AudioVisualizerController() : _model(), thumbnailCache(1), thumbnail(515, _model.getFormatManager(), thumbnailCache)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    this->thumbnail.addChangeListener(this);
    setSize (800, 600);
}

AudioVisualizerController::~AudioVisualizerController()
{
    this->thumbnail.clear();
}

void AudioVisualizerController::paint (Graphics& g)
{
    const Rectangle<int> thumbnailBounds (10, 100, getWidth() - 20, getHeight() - 120);
    
    if (thumbnail.getNumChannels() == 0)
    {
        // draw no file loaded text on a box
    }
    else
    {
        // use the thumbnail to draw
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
    this->_model.setAudioFile(file);
    //thumbnail.setSource (new FileInputSource (file));          // [7]
}

void AudioVisualizerController::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source == &thumbnail)        thumbnailChanged();
}

void AudioVisualizerController::thumbnailChanged()
{
    repaint();
}
