/*===========================================================================
 *
 * File:	Srutils.CPP
 * Author:	Dave Humphrey (dave@uesp.net)
 * Created On:	25 November 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srutils.h"
#include "windows.h"


CSString	g_SrManualInstallPath("");


/*===========================================================================
 *
 * Function - bool GetSrInstallPath (Buffer);
 *
 * Attempt to find Skyrim's install path in the registry. On success true
 * is returned and the path copied to the given buffer. On error false is
 * returned.
 *
 * HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Bethesda Softworks\Skyrim
 *
 *=========================================================================*/
bool GetSrInstallPath (CSString& OutputBuffer) 
{
  HKEY  hKey;
  BYTE  Buffer[300];
  DWORD Size = 256;
  DWORD Type;
  int   Result;

		/* Use the manual install path if set */
  if (!g_SrManualInstallPath.IsEmpty())
  {
	  OutputBuffer = g_SrManualInstallPath;
	  return true;
  }

  OutputBuffer.Empty();
  Result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, SR_REG_SUBKEY, 0, KEY_READ, &hKey);

  if (Result != ERROR_SUCCESS) 
  {
	  Result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, SR_REG_SUBKEY64, 0, KEY_READ, &hKey);

	  if (Result != ERROR_SUCCESS)
	  {
		AddSrGeneralError("Failed to find Skyrim's install path in the Windows registry!");
		return (false);
	  }
  }

  Result = RegQueryValueEx(hKey, SR_REG_INSTALLPATH, NULL, &Type, Buffer, &Size);

  if (Result == ERROR_SUCCESS && Type == REG_SZ) 
  {
    OutputBuffer = (char *)Buffer;
  }
  else 
  {
    AddSrGeneralError("Failed to find Skyrim's install path in the Windows registry!");
    RegCloseKey(hKey);
    return (false);
  }
     
  RegCloseKey(hKey);
  return (true);
}
/*===========================================================================
 *		End of Function GetSrInstallPath()
 *=========================================================================*/
