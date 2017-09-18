/*
  ==============================================================================

    AudioVisualizerController.h
    Created: 17 Sep 2017 5:41:09pm
    Author:  Jack Campbell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioVisualizerModel.h"

//==============================================================================
/*
*/
class AudioVisualizerController    : public Component, public FileDragAndDropTarget, public ChangeListener
{
public:
    AudioVisualizerController();
    ~AudioVisualizerController();

    void paint (Graphics&) override;
    void resized() override;
    
    bool 	isInterestedInFileDrag (const StringArray &files) override;
    void 	filesDropped (const StringArray &files, int x, int y) override;
    
    void changeListenerCallback (ChangeBroadcaster* source) override;
    void thumbnailChanged();

private:
    // Model
    AudioVisualizerModel _model; // saves file and audio parts here for use
    
    // View
    AudioThumbnailCache thumbnailCache;                  // [1]
    AudioThumbnail thumbnail;                            // [2]
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioVisualizerController)
};
