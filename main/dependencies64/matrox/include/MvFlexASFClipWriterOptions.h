//==========================================================================;
//
// Copyright (c) 2006-2011 Matrox Electronic Systems Ltd. All rights reserved.
//
// This code and information is provided "as is" without warranty of any kind,
// either expressed or implied, including but not limited to the implied
// warranties of merchantability and/or fitness for a particular purpose.
//
// Disclaimer: Matrox Electronic Systems Ltd. reserves the right to make
// changes in specifications and code at any time and without notice.
// No responsibility is assumed by Matrox Electronic Systems Ltd. for
// its use; nor for any infringements of patents or other rights of
// third parties resulting from its use. No license is granted under
// any patents or patent rights of Matrox Electronic Systems Ltd.
//
//==========================================================================;
//                    MVFLEXASFCLIPWRITEROPTIONS.H
//==========================================================================;
// @module  Matrox Video
//==========================================================================;
//   Birth Date:             JULY 31, 2006 - 8:57:02 AM
//   Operating System:       WinXP
//   Author:                 --
//==========================================================================;
//   Matrox Electronic Systems Ltd.
//   Dorval, Quebec, Canada
//==========================================================================;

#pragma once 

#include "mvFlexDefinitions.h"

#define MAX_LENGTH   100
// Namespace containing definitions for the Flex Windows Media File Writer options.
namespace NMvFlexASFClipWriterOptions
{
   // All the options that can be used with the Flex Windows Media File Writer.
   enum EMvFlexASFClipWriterOptions
   {
      keMvFlexASFClipWriterOptionsInvalid = 0,
      keMvFlexASFClipWriterOptionsVideoCodecConfig, // Configures which video codec will be used.  Use with SMvFlexASFClipWriterOptionsVideoCodecConfig. 
      keMvFlexASFClipWriterOptionsAudioCodecConfig, // Configures which audio codec will be used.  Use with SMvFlexASFClipWriterOptionsAudioCodecConfig.
      keMvFlexASFClipWriterOptionsIsSourceLive,     // Tells the codec that the source is live and it must encode as fast as possible (it may drop frames).  Use with a boolean (bool) value.
      keMvFlexASFClipWriterOptionsLast,
   };

   // Used to choose which video codec will be used to compress the video data.
   enum EMvFlexASFClipWriterOptionsVideoCodecType
   {
      keMvFlexASFClipWriterOptionsVideoCodecTypeInvalid = 0,
      keMvFlexASFClipWriterOptionsVideoCodecTypeDisabled,                           // The writer will not write video data to the file.
      keMvFlexASFClipWriterOptionsVideoCodecTypeWindowMediaVideo9,                  // The writer will use the WMV 9.0 video codec.
      keMvFlexASFClipWriterOptionsVideoCodecTypeWindowMediaVideo9AdvancedProfile,   // The writer will use the WMV 9.0 Advanced codec.
      keMvFlexASFClipWriterOptionsVideoCodecTypeLast,
   };

   // Used to choose which audio codec will be used to compress the audio data.
   enum EMvFlexASFClipWriterOptionsAudioCodecType
   {
      keMvFlexASFClipWriterOptionsAudioCodecTypeInvalid = 0,
      keMvFlexASFClipWriterOptionsAudioCodecTypeDisabled,                           // The writer will not write audio data to the file.
      keMvFlexASFClipWriterOptionsAudioCodecTypeWindowMediaAudio9_1,                // The writer will use the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecTypeWindowMediaAudio9_1Professional,    // The writer will use the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecTypeWindowMediaAudio9_1Lossless,        // The writer will use the WMA 9.1 lossless audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecTypeLast,
   };

   // Used to choose which audio format will be generated by the audio codec.
   enum EMvFlexASFClipWriterOptionsAudioCodecFormat
   {
      keMvFlexASFClipWriterOptionsAudioCodecFormatInvalid = 0,
      
      // Codec format for Windows Media Audio 9.1.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_192kbps_48kHz_stereo,     // The writer will write a CBR 192 kbps, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_160kbps_48kHz_stereo,     // The writer will write a CBR 160 kbps, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_128kbps_48kHz_stereo,     // The writer will write a CBR 128 kbps, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_96kbps_48kHz_stereo,      // The writer will write a CBR 96 kbps, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_64kbps_48kHz_stereo,      // The writer will write a CBR 64 kbps, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_VBR_Quality98_48kHz_stereo,   // The writer will write a VBR Quality98, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormat_VBR_Quality90_48kHz_stereo,   // The writer will write a VBR Quality90, 48kHz stereo audio stream using the WMA 9.1 audio codec.
      
      // Codec format for Windows Media Audio 9.1 Professional.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_440kbps_48kHz_2channel_24bit,   // The writer will write a CBR 440 kbps, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_384kbps_48kHz_2channel_24bit,   // The writer will write a CBR 384 kbps, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_256kbps_48kHz_2channel_24bit,   // The writer will write a CBR 256 kbps, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_192kbps_48kHz_2channel_24bit,   // The writer will write a CBR 192 kbps, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_128kbps_48kHz_2channel_24bit,   // The writer will write a CBR 128 kbps, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality98_48kHz_2channel_24bit, // The writer will write a VBR Quality98, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality90_48kHz_2channel_24bit, // The writer will write a VBR Quality90, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality75_48kHz_2channel_24bit, // The writer will write a VBR Quality75, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality50_48kHz_2channel_24bit, // The writer will write a VBR Quality50, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality25_48kHz_2channel_24bit, // The writer will write a VBR Quality25, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality10_48kHz_2channel_24bit, // The writer will write a VBR Quality10, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 professional audio codec.
      
      // Codec format for Windows Media Audio 9.1 Lossless.
      keMvFlexASFClipWriterOptionsAudioCodecFormatLossless_VBR_Quality100_48kHz_2channel_24bit,    // The writer will write a VBR Quality100, 48kHz 2-channel 24-bit audio stream using the WMA 9.1 lossless audio codec.
      
      keMvFlexASFClipWriterOptionsAudioCodecFormatLast,
   };


   // Used to choose the type of video compression that will be performed by the video codec.
   enum EMvFlexASFClipWriterOptionsVideoCodecMode
   {
      keMvFlexASFClipWriterOptionsVideoCodecModeInvalid = 0,
      keMvFlexASFClipWriterOptionsVideoCodecModeConstantBitRate,                 // VBR is not used, CBR is used.
      keMvFlexASFClipWriterOptionsVideoCodecModeVariableBitRateQualityBased,     // Quality-based VBR.
      keMvFlexASFClipWriterOptionsVideoCodecModeVariableBitRateConstrained,      // Constrains the peak bit rate and also (optionally) the peak buffer window.
      keMvFlexASFClipWriterOptionsVideoCodecModeVariableBitRateUnconstrained,    // No constraints on the peak bit rate.
      keMvFlexASFClipWriterOptionsVideoCodecModeLast,
   };

   // Used to configure the first video stream.
   // The stream resolution information is specifed by IMvFlexWriter::OpenFile.
   struct SMvFlexASFClipWriterOptionsVideoCodecConfig
   {
      uint32_t size;                                             // Specifies the structure size in bytes.
      EMvFlexASFClipWriterOptionsVideoCodecType eCodecType;    // Specifies the video codec type that will be used for capturing the video stream.  
      EMvFlexASFClipWriterOptionsVideoCodecMode eCodecMode;    // Specifies the video codec mode that will be used for capturing the video stream.
      LCID          sLanguage;                                 // Specifies the language that will be used for the video stream.
      unsigned long ulBitRateInBitsPerSecond;                  // Specifies the bit rate in bits per second for the video stream.
      unsigned long ulMaximumBitRateInBitsPerSecond;           // Specifies the maximum bit rate in bits per second for the video stream.   
      unsigned long ulBufferWindowInMilliseconds;              // Specifies the buffer windows in millisecond for the video stream.
      unsigned long ulMaximumBufferWindowInMilliseconds;       // Specifies the maximum buffer windows in millisecond for the video stream.
      EMvFrameRate  eFramesPerSecond;                          // Specifies the frame rate for the video stream.
      unsigned long ulSecondsPerKeyframe;                      // Specifies the key frame interval. 
      unsigned long ulQualitySettings;                         // Specifies the quality setting, which must be a value from 0 to 100.
      unsigned long ulVariableBitRateQualitySettings;          // Specifies the VBR quality setting, which must be a value from 0 to 100.
   };

   // Used to configure the extra video stream for a multi-stream Windows Media file capture.
   struct SMvFlexASFClipWriterOptionsVideoCodecConfigWithResolution
   {
      uint32_t size;                                                                     // Specifies the structure size in bytes.
      EMvFlexASFClipWriterOptionsVideoCodecType eCodecType;                            // Specifies the video codec type that will be used for capturing the video stream.  
      EMvFlexASFClipWriterOptionsVideoCodecMode eCodecMode;                            // Specifies the video codec mode that will be used for capturing the video stream.
      LCID                                      sLanguage;                             // Specifies the language that will be used for the video stream.
      unsigned long                             ulBitRateInBitsPerSecond;              // Specifies the bit rate in bits per second for the video stream.
      unsigned long                             ulMaximumBitRateInBitsPerSecond;       // Specifies the maximum bit rate in bits per second for the video stream.
      unsigned long                             ulBufferWindowInMilliseconds;          // Specifies the buffer windows in millisecond for the video stream.
      unsigned long                             ulMaximumBufferWindowInMilliseconds;   // Specifies the maximum buffer windows in millisecond for the video stream.
      EMvFrameRate                              eFramesPerSecond;                      // Specifies the frame rate for the video stream.
      unsigned long                             ulSecondsPerKeyframe;                  // Specifies the key frame interval.
      unsigned long                             ulQualitySettings;                     // Specifies the quality setting, which must be a value from 0 to 100.
      unsigned long                             ulVariableBitRateQualitySettings;      // Specifies the VBR quality setting, which must be a value from 0 to 100.
      SMvResolutionInfo                         sResolutionInfo;
   };

   //Used to configure the audio stream settings.
   struct SMvFlexASFClipWriterOptionsAudioCodecConfig
   {
      uint32_t size;                                                // Specifies the structure size in bytes.
      EMvFlexASFClipWriterOptionsAudioCodecType eCodecType;       // Specifies the audio codec type that will be used for capturing the audio stream.  
      EMvFlexASFClipWriterOptionsAudioCodecFormat eCodecFormat;   // Specifies the audio codec format that will be used for capturing the audio stream.
      LCID          sLanguage;                                    // Specifies the language that will be used for the audio stream.
      unsigned long ulBufferWindowInMilliseconds;                 // Specifies the buffer window that will be used when capturing the audio stream.
   };

   // Used to configure the video/audio frame indexing on/off.
   struct SMvFlexASFClipWriterOptionsVideoAudioFrameIndexing
   {
      uint32_t      size;                         // Specifies the structure size in bytes.
      bool        bVideoFrameIndexing;          // Specifies whether or not to add a frame index for the video stream. 
      bool        bAudioFrameIndexing;          // Specifies whether or not to add a frame index for the audio stream.
   };

   struct SMvFlexASFClipWriterOptionsSkipFrameOnLowMemory
   {
      uint32_t                  size;                                           // Specifies the structure size in bytes.
      bool                    bEnableSkipFrameOnLowMemory;                   // Specifies whether or not to enable skip frame for large bit rate and frame size capture 
      unsigned long           ulMemPercentageRemainToStartSkipFrame;         // Specifies how many percentage memory left to start skip frame
   };

}
#define MV_ASF_Options_Video_Codec_Mode(eMvASFOptionsVideoCodecMode) \
   ((eMvASFOptionsVideoCodecMode == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeInvalid) ? ("Invalid") : \
 (eMvASFOptionsVideoCodecMode == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeConstantBitRate) ? ("CBR") : \
 (eMvASFOptionsVideoCodecMode == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeVariableBitRateQualityBased) ? ("VBRBased") : \
 (eMvASFOptionsVideoCodecMode == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeVariableBitRateConstrained) ? ("VBRConstrained") : \
 (eMvASFOptionsVideoCodecMode == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeVariableBitRateUnconstrained) ? ("VBRUnconstrained") : \
 (eMvASFOptionsVideoCodecMode == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeLast) ? ("Last") : \
 ("???"))

#define MV_ASF_Options_Video_Codec_Type(eMvASFOptionsVideoCodecType) \
   ((eMvASFOptionsVideoCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecTypeInvalid) ? ("Invalid") : \
   (eMvASFOptionsVideoCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecTypeDisabled) ? ("Disabled") : \
   (eMvASFOptionsVideoCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecTypeWindowMediaVideo9) ? ("WMV9") : \
   (eMvASFOptionsVideoCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecTypeWindowMediaVideo9AdvancedProfile) ? ("WMV9AdvanceProfile") : \
   (eMvASFOptionsVideoCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecTypeLast) ? ("Last") : \
   ("???"))

#define MV_ASF_Options_Audio_Codec_Type(eMvASFOptionsAudioCodecType) \
   ((eMvASFOptionsAudioCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecTypeInvalid) ? ("Invalid") : \
   (eMvASFOptionsAudioCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecTypeDisabled) ? ("Disabled") : \
   (eMvASFOptionsAudioCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecTypeWindowMediaAudio9_1) ? ("WMA9_1") : \
   (eMvASFOptionsAudioCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecTypeWindowMediaAudio9_1Professional) ? ("WMA9_1Professional") : \
   (eMvASFOptionsAudioCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecTypeWindowMediaAudio9_1Lossless) ? ("WMA9_1Lossless") : \
   (eMvASFOptionsAudioCodecType == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeLast) ? ("Last") : \
   ("???"))

#define MV_ASF_Options_Audio_Codec_Format(eMvASFOptionsAudioCodecFormat) \
   ((eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatInvalid) ? ("Invalid") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_192kbps_48kHz_stereo) ? ("CBR 192Kbps 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_160kbps_48kHz_stereo) ? ("CBR 160Kbps 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_128kbps_48kHz_stereo) ? ("CBR 128Kbps 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_96kbps_48kHz_stereo) ? ("CBR 96Kbps 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_CBR_64kbps_48kHz_stereo) ? ("CBR 64Kbps 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_VBR_Quality98_48kHz_stereo) ? ("VBR Quality98 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormat_VBR_Quality90_48kHz_stereo) ? ("VBR Quality90 48kHz Stereo") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_440kbps_48kHz_2channel_24bit) ? ("CBR 440Kbps 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_384kbps_48kHz_2channel_24bit) ? ("CBR 384Kbps 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_256kbps_48kHz_2channel_24bit) ? ("CBR 256Kbps 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_192kbps_48kHz_2channel_24bit) ? ("CBR 192bps 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_CBR_128kbps_48kHz_2channel_24bit) ? ("CBR 128Kbps 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality98_48kHz_2channel_24bit) ? ("VBR Quality98 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality90_48kHz_2channel_24bit) ? ("VBR Quality90 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality75_48kHz_2channel_24bit) ? ("VBR Quality75 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality50_48kHz_2channel_24bit) ? ("VBR Quality50 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality25_48kHz_2channel_24bit) ? ("VBR Quality25 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatProfessional_VBR_Quality10_48kHz_2channel_24bit) ? ("VBR Quality10 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsAudioCodecFormatLossless_VBR_Quality100_48kHz_2channel_24bit) ? ("Lossless VBR Quality100 48kHz 2channel 24bit") : \
   (eMvASFOptionsAudioCodecFormat == NMvFlexASFClipWriterOptions::keMvFlexASFClipWriterOptionsVideoCodecModeLast) ? ("Last") : \
   ("???"))
   
