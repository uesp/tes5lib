/*===========================================================================
 *
 * File:	Srutils.H
 * Author:	Dave Humphrey (dave@uesp.net)
 * Created On:	25 November 2011
 *
 * Various Skyrim related utility functions and definitions.
 *
 *=========================================================================*/
#ifndef __SRUTILS_H
#define __SRUTILS_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srerrorhandler.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

	/* Registry keys */
  #define SR_REG_SUBKEY       "SOFTWARE\\Bethesda Softworks\\Skyrim"
  #define SR_REG_SUBKEY64     "SOFTWARE\\Wow6432Node\\Bethesda Softworks\\Skyrim"
  #define SR_REG_INSTALLPATH  "Installed Path"

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Function Definitions
 *
 *=========================================================================*/

	/* Attempt to find the Skyrim install path in the registry */
  bool GetSrInstallPath (CSString& Buffer);

/*===========================================================================
 *		End of Function Definitions
 *=========================================================================*/


  extern CSString	g_SrManualInstallPath;


#endif
/*===========================================================================
 *		End of File Srutils.H
 *=========================================================================*/
