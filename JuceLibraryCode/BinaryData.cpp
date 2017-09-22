/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== readme.md ==================
static const unsigned char temp_binary_data_0[] =
"***OFFLINE CONVOLUTION REVERB***\r\n"
"*jack campbell*\r\n"
"\r\n"
"--- how to build\r\n"
"- grab the JUCE Library code, create builds directory\r\n"
"- use this source directory and jucer file\r\n"
"\r\n"
"\r\n"
"\r\n"
"todo:\r\n"
"XXXiteration 1XXX:\r\n"
"drag audio files onto top two viewports and display them\r\n"
"\r\n"
"iteration 1.\r\n"
"\r\n"
"iteration 2:\r\n"
"be able to play these audio files\r\n"
"\r\n"
"iteration 3:\r\n"
"on generate button click, convolve the two audio files, save the result and display it in a new AudioVisualizer on the bottom\r\n"
"\r\n"
"iteration 4:\r\n"
"save the result as a WAV or OGG file\r\n"
"\r\n"
"\r\n"
"\r\n"
"-- AudioVisualizerModel\r\n"
"- contains reference to loaded audio file\r\n"
"- getter/setter for audio file\r\n"
"\r\n"
"-- AudioVisualizerController (drag and drop listener)\r\n"
"- listener for dragging an audio file onto the viewport; sets its model's file and \r\n"
"- has a view: the AudioThumbnail and AudioThumbnailClass components. updates this as necessary\r\n";

const char* readme_md = (const char*) temp_binary_data_0;


const char* getNamedResource (const char*, int&) throw();
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes) throw()
{
    unsigned int hash = 0;
    if (resourceNameUTF8 != 0)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xbe6091c8:  numBytes = 869; return readme_md;
        default: break;
    }

    numBytes = 0;
    return 0;
}

const char* namedResourceList[] =
{
    "readme_md"
};

}
