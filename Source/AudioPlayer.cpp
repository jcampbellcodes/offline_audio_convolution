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

void AudioPlayer::privSetInputFile(const juce::File &file)
{
    this->_inputFile = file;
}

void AudioPlayer::privSetImpulseFile(const juce::File &file)
{
    this->_impulseFile = file;
    convolution.loadImpulseResponse(this->_impulseFile, true, true, this->_impulseFile.getSize());
}

void AudioPlayer::privStartPlaying()
{
    AudioFormatReader* reader = formatManager.createReaderFor (this->_inputFile);
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
    dsp::ProcessSpec spec {sampleRate, static_cast<uint32>(samplesPerBlockExpected), 2};
    convolution.prepare(spec);
    transportSource.prepareToPlay (samplesPerBlockExpected, sampleRate);
}

void AudioPlayer::reset()
{
    this->convolution.reset();
}

void AudioPlayer::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    if (readerSource == nullptr)
    {
        bufferToFill.clearActiveBufferRegion();
    }
    else
    {
        transportSource.getNextAudioBlock (bufferToFill);
        
        AudioSampleBuffer wetSamples;
        
        for(int channel = 0; channel < bufferToFill.buffer->getNumChannels(); channel++)
        {
            wetSamples.makeCopyOf(*bufferToFill.buffer);
        }
        dsp::AudioBlock<float> wet_block (wetSamples, (size_t)bufferToFill.startSample);
        dsp::AudioBlock<float> dry_block (*bufferToFill.buffer, (size_t)bufferToFill.startSample);
        this->convolution.process(dsp::ProcessContextReplacing<float>(wet_block));
        dry_block.multiply(1.0 - balance);
        wet_block.multiply(balance);
        dry_block.add(wet_block);
        
    }
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

AudioPlayer::AudioPlayer() : balance(0.5)
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


