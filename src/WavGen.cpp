#include "WavGen.h"

//convert input into little endian format
namespace little_endian_io
{
  template <typename Word>
  std::ostream& write_word( std::ostream& outs, Word value, unsigned size = sizeof(Word))
  {
    for (; size; --size, value >>= 8)
      outs.put(static_cast <char> (value & 0xFF));
    return outs;
  }
}

using namespace little_endian_io;

WavGenerator::WavGenerator(int channels, int BitsPerSample ) {
  channelNum = channels; 
  bps = BitsPerSample;
}


void WavGenerator::SaveWav(double data[], int dataLength, int rate) {
  int byteRate = (rate * channelNum * bps) / 8;
  std::ofstream output("res.wav", std::ios::out | std::ios::binary);
  // WAVE FILE HEADER

  /* R I F F |(s i z e)| f m t _ 
   * _ _ _ _ | _ _ _ _ | _ _ _ _ (bytes)
   ************************************/
  output << "RIFF----WAVEfmt ";  // chunk size left to be determined
  write_word(output,       16, 4);  // no extension data
  write_word(output,        1, 2);  // PCM - integer samples
  write_word(output,        2, 2);  // two channels (stereo file)
  write_word(output,     rate, 4);  // samples per second (Hz)
  write_word(output, byteRate, 4);  // (Sample Rate * BitsPerSample * Channels) / 8
  write_word(output,        4, 2);  // data block size (size of two integer samples, one for each channel, in bytes)
  write_word(output,      bps, 2);  // number of bits per sample (use a multiple of 8)

  // Write the data chunk header
  size_t data_chunk_pos = output.tellp();
  output << "data----";  // chunk size left to be determined

  //filling data
  for (int i = 0; i < dataLength; i++) {  
      write_word(output, (int)data[i], 2); 
  };

  size_t file_length = output.tellp();
  // Fix the data chunk header to contain the data size
  output.seekp(data_chunk_pos + 4);
  write_word(output, file_length - data_chunk_pos + 8);
  // Fix the file header to contain the proper RIFF chunk size, which is (file size - 8) bytes
  output.seekp(0 + 4);
  write_word(output, file_length - 8, 4); 
    
}