/*
  ==============================================================================

    InputVisualizer.cpp
    Created: 17 Nov 2017 10:16:48am
    Author:  Jack Campbell

  ==============================================================================
*/

#include "OutputVisualizer.h"
#include "AudioPlayer.h"
OutputVisualizer::OutputVisualizer(int width, int height, InputVisualizer* _input, ImpulseVisualizer* _impulse) : AudioVisualizerController(width, height), input(_input), impulse(_impulse){};

// visualize wave and play sound
// don't listen to files dropped, listen for "generate button" click
void OutputVisualizer::filesDropped (const StringArray &files, int, int)
{
    
    printf("file name: %s", files[0].toRawUTF8());
    File file(files[0]);
    this->_audioFile = file;
    thumbnail.setSource (new FileInputSource (file));          // [7]
    
}

void OutputVisualizer::convolveInput()
{
    // get input file
    // get impulse response
    /*
    AudioFormatReader* reader = formatManager.createReaderFor (this->input->getFile());
    if (reader != nullptr)
    {
        AudioBuffer<float>* buff = new AudioBuffer<float>(reader->numChannels, reader->lengthInSamples);
        //reader->input->read(buff, int(reader->input->getTotalLength()));
        thumbnail.setReader(reader, 0xAABBAA);
        reader->read(buff, 0, int(reader->lengthInSamples), 0, true, true);
        
        dsp::ProcessSpec spec {reader->sampleRate, static_cast<uint32>(buff->getNumSamples()), 2};
        this->convolution.prepare(spec);
        
        
        convolution.loadImpulseResponse(this->impulse->getFile(), true, true, this->impulse->getFile().getSize());
        
        
        AudioSampleBuffer wetSamples;
        
        for(int channel = 0; channel < buff->getNumChannels(); channel++)
        {
            wetSamples.makeCopyOf(*buff);
        }
        dsp::AudioBlock<float> wet_block (wetSamples, 0);
        dsp::AudioBlock<float> dry_block (*buff, 0);
        this->convolution.process(dsp::ProcessContextReplacing<float>(wet_block));
        dry_block.multiply(1.0 - 0.5);
        wet_block.multiply(0.5);
        dry_block.add(wet_block);
        
    }*/
}
