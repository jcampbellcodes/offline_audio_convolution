/*
  ==============================================================================

    AudioVisualizerController.h
    Created: 17 Sep 2017 5:41:09pm
    Author:  Jack Campbell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/



class AudioVisualizerController    : public Component, public FileDragAndDropTarget, public ChangeListener
{
public:
    //AudioVisualizerController();
    AudioVisualizerController(int width, int height);
    ~AudioVisualizerController();

    void paint (Graphics&) override;
    void resized() override;
    
    virtual bool 	isInterestedInFileDrag (const StringArray &files) override;
    virtual void 	filesDropped (const StringArray &files, int x, int y) override;
    
    void changeListenerCallback (ChangeBroadcaster* source) override;

protected:
    

    AudioThumbnailCache thumbnailCache;                  // [1]
    AudioThumbnail thumbnail;                            // [2]
    AudioFormatManager formatManager; 
    
    File _audioFile;
    
    void transportSourceChanged();
    void thumbnailChanged();
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioVisualizerController)
};
