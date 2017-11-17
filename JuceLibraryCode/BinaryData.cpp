/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== readme.md ==================
static const unsigned char temp_binary_data_0[] =
"***OFFLINE CONVOLUTION REVERB***\n"
"*jack campbell*\n"
"\n"
"--- how to build\n"
"- grab the JUCE Library code, create builds directory\n"
"- use this source directory and jucer file\n"
"\n"
"\n"
"\n"
"todo:\n"
"\n"
"iteration 3:\n"
"on generate button click, convolve the two audio files, save the result and display it in a new AudioVisualizer on the bottom\n"
"\n"
"iteration 4:\n"
"save the result as a WAV or OGG file\n"
"\n"
"\n"
"\n"
"-- AudioVisualizerModel\n"
"- contains reference to loaded audio file\n"
"- getter/setter for audio file\n"
"\n"
"-- AudioVisualizerController (drag and drop listener)\n"
"- listener for dragging an audio file onto the viewport; sets its model's file and \n"
"- has a view: the AudioThumbnail and AudioThumbnailClass components. updates this as necessary\n";

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
        case 0xbe6091c8:  numBytes = 698; return readme_md;
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
