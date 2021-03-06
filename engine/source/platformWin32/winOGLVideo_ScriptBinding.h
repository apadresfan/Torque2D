//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

/*! @addtogroup WindowsPlatform Windows Platform
	@ingroup TorqueScriptFunctions
	@{
*/

/*! Register a card profile with the card profile manager.

    Most of the parameters are fairly self-explanatory and very internal
     to the rendering code; however there are a few of note:
    @param vendor   The vendor string the card claims.
    @param renderer The renderer string the card claims.
    @param proFile  Name of the file where further configuration information is kept.
*/
ConsoleFunctionWithDocs( addCardProfile, ConsoleVoid, 16, 16,				
	(string vendor, string renderer,
    bool safeMode, bool lockArray, bool subImage, bool fogTexture,
    bool noEnvColor, bool clipHigh, bool deleteContext, bool texCompress,
    bool interiorLock, bool skipFirstFog, bool only16,	
    bool noArraysAlpha, string proFile))
{
   CardProfile profile;

   profile.vendor = dStrdup(argv[1]);
   profile.renderer = dStrdup(argv[2]);

   profile.safeMode = dAtob(argv[3]);
   profile.lockArray = dAtob(argv[4]);
   profile.subImage = dAtob(argv[5]);
   profile.fogTexture = dAtob(argv[6]);
   profile.noEnvColor = dAtob(argv[7]);
   profile.clipHigh = dAtob(argv[8]);
    profile.deleteContext = dAtob(argv[9]);
    profile.texCompress = dAtob(argv[10]);
    profile.interiorLock = dAtob(argv[11]);
    profile.skipFirstFog = dAtob(argv[12]);
    profile.only16 = dAtob(argv[13]);
    profile.noArraysAlpha = dAtob(argv[14]);

    if (strcmp(argv[15],""))
        profile.proFile = dStrdup(argv[15]);
    else
        profile.proFile = NULL;

   sCardProfiles.push_back(profile);
}

/*! Register with the profile manager what rendering mode is preferred with the specified card.
*/
ConsoleFunctionWithDocs( addOSCardProfile, ConsoleVoid, 6,6, (string vendor, string renderer, bool allowOpenGL, ...))
{
   OSCardProfile profile;

   profile.vendor = dStrdup(argv[1]);
   profile.renderer = dStrdup(argv[2]);

   profile.allowOpenGL = dAtob(argv[3]);
    profile.preferOpenGL = dAtob(argv[5]);

   sOSCardProfiles.push_back(profile);
}

/*! @} */ // end group WindowsPlatform
