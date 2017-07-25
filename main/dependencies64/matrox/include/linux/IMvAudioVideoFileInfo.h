//==========================================================================;
//
// (c) Copyright Matrox Electronic Systems Ltd., 2002. All rights reserved.
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

#pragma once

//////////////////////////////////////////////////////////////////////////
//
// Summary:
//    Retrieves audio and video file information. 
//
//////////////////////////////////////////////////////////////////////////
interface IMvAudioVideoFileInfo : public IUnknown
{
public:

   //
   // Summary:
   //    Opens an audio/video file.
   // Return value:
   //    - MV_NOERROR, if completed successfully. 
   //    - HRESULT error code, if the function reports an error. 
   //
   virtual HRESULT __stdcall OpenFile
      (
      wchar_t * in_pwszFileName  // Pointer to the path and file name of the file to open.
      ) = 0;

   //
   // Summary:
   //    Opens an audio/video file with an associated index file.  The index
   //    file would contain information on the indexing of the data inside
   //    the file.
   // Return value:
   //    - MV_NOERROR, if completed successfully. 
   //    - HRESULT error code, if the function reports an error. 
   //
   virtual HRESULT __stdcall OpenFileWithIndex
      (
      wchar_t * in_pwszFileName,  // Points to the path and filename of the file to open.     
      wchar_t * in_pwszIndexFileName // Points to the path and filename of the index file associated with the file to open.  
      ) = 0;

   //
   // Summary:
   //    Retrieves audio and video file information.
   // Return value:
   //    - MV_NOERROR, if completed successfully. 
   //    - HRESULT error code, if the function reports an error. 
   //
   virtual HRESULT __stdcall GetAVFileInfo
      (
      SMvAudioVideoFileInfo * io_psmvAVFileInfo // Pointer to the SMvAudioVideoFileInfo file info structure.
      ) = 0;

   //
   // Summary:
   //    Closes the audio/video file.
   // Return value:
   //    - MV_NOERROR, if completed successfully. 
   //    - HRESULT error code, if the function reports an error. 
   //
   virtual HRESULT __stdcall Close() = 0;



   //
   // Summary:
   //  Gets the spanned file interface  of the element.
   //
   // Remarks:
   //    - The caller allocates space and the caller frees the space.
   // 
   // Return values: 
   //    - MV_NOERROR, if completed successfully.
   //    - MV_E_INVALID_POINTER, if the parameter out_ppwszFileName is an invalid pointer.
   //    - MV_E_OUT_OF_MEMORY, if there is not sufficient memory available.
   // 
   //
   virtual HRESULT __stdcall GetSpannedFiles
   (
      IMvdSpannedFiles ** out_pISpannedFiles // Pointer to the file names' pointer.
   ) = 0;

};

