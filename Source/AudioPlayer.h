/*
  ==============================================================================

    AudioPlayer.h
    Created: 21 Sep 2017 10:06:28pm
    Author:  Jack Campbell

  ==============================================================================
*/

#pragma once
#ifndef AUDIOPLAYER
#define AUDIOPLAYER

/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

enum TransportState
{
    Stopped,
    Starting,
    Playing,
    Stopping
};

class InputSignalDragDrop;

class AudioPlayer   : public AudioAppComponent, public ChangeListener
{
public:


    
    void privSetAudioFile(const juce::File &file);
    
    static void setAudioFile(juce::File &file)
    {
        AudioPlayer::Instance().privSetAudioFile(file);
    }
    
    void changeState(TransportState newState);
    
    void changeListenerCallback (ChangeBroadcaster* source) override;
    
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    
    void releaseResources() override;
    
    

    //==============================================================================
    void paint (Graphics& g) override;

    void resized() override;
    
    static AudioPlayer& Instance()
    {
        if(!instance)
        {
            instance = new AudioPlayer();
        }
        return *instance;
    }


private:
    //==============================================================================

    // Your private member variables go here...
    
    //==============================================================================
    AudioPlayer();
    
    ~AudioPlayer();
    
    static AudioPlayer* instance;
    
    InputSignalDragDrop* dragDropView;
    // View
    TransportState state;
    AudioFormatManager formatManager;                    // [3]
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;

    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPlayer)
};

#endif
