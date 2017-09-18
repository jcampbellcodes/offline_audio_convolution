/*
  ==============================================================================

    AudioVisualizerModel.h
    Created: 17 Sep 2017 5:40:57pm
    Author:  Jack Campbell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AudioVisualizerModel    : public Component
{
public:
    AudioVisualizerModel();
    ~AudioVisualizerModel();

    void paint (Graphics&) override;
    void resized() override;

    const File& getAudioFile() const;
    void setAudioFile(const File& file);
    
    AudioFormatManager& getFormatManager() { return this->formatManager; };
    
private:

    AudioFormatManager formatManager;                    // [3]
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource transportSource;
    
    File _audioFile;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioVisualizerModel)
};
