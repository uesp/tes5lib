/*===========================================================================
 *
 * File:		SrFunctions.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	3 December 2011
 *
 * Script/console function data.
 *
 *=========================================================================*/
#ifndef __SRFUNCTIONS_H
#define __SRFUNCTIONS_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srmoddefs.h"  
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

		/* Arbitrary limit on function parameter count. Max used in Skyrim is 9 */
	#define SR_FUNCTION_MAXPARAMS	10

		/* Function Flags 
		 *		Flags in the lower 16 bits are from the Skyrim function data
		 *		Flags in the upper 16 bits are custom SkyEdit flags 
		 */
	#define SR_FUNCTION_FLAG_REF		0x01000000
	#define SR_FUNCTION_FLAG_BLOCK		0x02000000
	#define SR_FUNCTION_FLAG_CONSOLE	0x04000000
	#define SR_FUNCTION_FLAG_SCRIPT		0x08000000
	#define SR_FUNCTION_FLAG_IGNORE		0x10000000

		/* Function parameter flags */
	#define SR_FUNCPARAM_FLAG_OPT 0x01

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

struct srfuncparam_t
{
	dword	Type;
	dword	Flags;
};

  
struct srfunction_t
{
	dword			OpCode;
	const char*		Name;
	const char*		ShortName;
	dword			Flags;
	const char*		HelpText;
	dword			NumParams;
	srfuncparam_t	Params[SR_FUNCTION_MAXPARAMS];
};

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Function Definitions
 *
 *=========================================================================*/
	srfunction_t* GetSrFunction	(const char* pString);
	srfunction_t* GetSrFunction	(const dword OpCode);
	bool GetSrFunctionParamTypeValue (int& Value, const SSCHAR* pString);
	const SSCHAR* GetSrFunctionParamTypeString (const int Value);
	bool IsSrFunctionParamFormID (const dword ParamType);
/*===========================================================================
 *		End of Function Definitions
 *=========================================================================*/


	extern srfunction_t g_SrFunctions[];
	extern dword g_SrFunctionCount;


#endif
/*===========================================================================
 *		End of File SrFunctions.H
 *=========================================================================*/
