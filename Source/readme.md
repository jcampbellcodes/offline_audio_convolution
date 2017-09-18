***OFFLINE CONVOLUTION REVERB***
*jack campbell*

--- how to build
- grab the JUCE Library code, create builds directory
- use this source directory and jucer file



todo:
XXXiteration 1XXX:
drag audio files onto top two viewports and display them

iteration 2:
be able to play these audio files

iteration 3:
on generate button click, convolve the two audio files, save the result and display it in a new AudioVisualizer on the bottom

iteration 4:
save the result as a WAV or OGG file



-- AudioVisualizerModel
- contains reference to loaded audio file
- getter/setter for audio file

-- AudioVisualizerController (drag and drop listener)
- listener for dragging an audio file onto the viewport; sets its model's file and 
- has a view: the AudioThumbnail and AudioThumbnailClass components. updates this as necessary
