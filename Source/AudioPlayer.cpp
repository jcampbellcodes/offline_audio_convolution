/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "./InputSignalDragDrop.h"
#include "./AudioPlayer.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
AudioPlayer* AudioPlayer::instance = nullptr;
void AudioPlayer::privSetAudioFile(const juce::File &file)
{
    AudioFormatReader* reader = formatManager.createReaderFor (file);
    changeState(Stopping);
    if (reader != nullptr)
    {
        ScopedPointer<AudioFormatReaderSource> newSource = new AudioFormatReaderSource (reader, true);
        transportSource.setSource (newSource, 0, nullptr, reader->sampleRate);
        readerSource = newSource.release();
        changeState(Starting);
    }
}
void AudioPlayer::changeState(TransportState newState)
{
    if (state != newState)
    {
        state = newState;
        
        switch (state)
        {
            case Stopped:                           // [3]
                transportSource.setPosition (0.0);
                break;
                
            case Starting:                          // [4]
                transportSource.start();
                break;
                
            case Playing:                           // [5]
                break;
                
            case Stopping:                          // [6]
                transportSource.stop();
                break;
        }
    }
}
void AudioPlayer::changeListenerCallback (ChangeBroadcaster* source)
{
    
     if (source == &transportSource)
     {
         if (transportSource.isPlaying())
            changeState (Playing);
         else
             changeState (Stopped);
     }
}
void AudioPlayer::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    transportSource.prepareToPlay (samplesPerBlockExpected, sampleRate);
}

void AudioPlayer::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    if (readerSource == nullptr)
            bufferToFill.clearActiveBufferRegion();
        else
            transportSource.getNextAudioBlock (bufferToFill);
}

void AudioPlayer::releaseResources()
{
    transportSource.releaseResources();
}

//==============================================================================
void AudioPlayer::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    // You can add your drawing code here!
}

void AudioPlayer::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

AudioPlayer::AudioPlayer()
{
    this->dragDropView = new InputSignalDragDrop();
    setSize (800, 600);
    
    // specify the number of input and output channels that we want to open
    setAudioChannels (2, 2);
    formatManager.registerBasicFormats();
    addAndMakeVisible(this->dragDropView);
}
AudioPlayer::~AudioPlayer()
{
    if(this->dragDropView)
    {
        delete this->dragDropView;
        this->dragDropView = nullptr;
    }
    shutdownAudio();
}


