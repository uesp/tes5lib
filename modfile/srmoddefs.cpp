/*===========================================================================
 *
 * File:		Srmoddefs.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srmoddefs.h"
#include "ctype.h"


/*===========================================================================
 *
 * Begin Global Constants
 *
 *=========================================================================*/
const srrgba_t SR_COLOR_NULL = { 0, 0, 0, 0 };

CSString g_SrLanguage("English");
/*===========================================================================
 *		End of Global Constants
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Constant String Tables
 *
 *=========================================================================*/
BEGIN_STRINGVALUE(s_SrMagicSchools)
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_ALTERATION,	"Alteration")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_CONJURATION,	"Conjuration")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_DESTRUCTION,	"Destruction")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_ILLUSION,		"Illusion")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_RESTORATION,	"Restoration")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_NONE,			"None")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrMagicTypes)
	ADD_STRINGVALUE( SR_MAGIC_TYPE_EXTRADMG,	"Extra Damage")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_POISON,		"Poison")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_FIRE,		"Fire")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_SHOCK,		"Shock")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_FROST,		"Frost")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_DRAIN,		"Drain")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_NONE,		"None")
END_STRINGVALUE()

BEGIN_STRINGVALUE(s_SrConditionOperators)
	ADD_STRINGVALUE( SR_CONDOP_EQUAL,			"==")
	ADD_STRINGVALUE( SR_CONDOP_NOTEQUAL,		"!=")
	ADD_STRINGVALUE( SR_CONDOP_GREATER,			">")
	ADD_STRINGVALUE( SR_CONDOP_GREATEREQUAL,	">=")
	ADD_STRINGVALUE( SR_CONDOP_LESS,			"<")
	ADD_STRINGVALUE( SR_CONDOP_LESSEQUAL,		"<=")
END_STRINGVALUE()


/*===========================================================================
 *		End of Constant String Tables
 *=========================================================================*/


/*===========================================================================
 *
 * Begin String Table Lookup Functions
 *
 *=========================================================================*/
const SSCHAR* GetSrMagicSchoolString		(const int Value) { return s_SrMagicSchoolsMap.FindValue(Value); }
const SSCHAR* GetSrMagicTypeString			(const int Value) { return s_SrMagicTypesMap.FindValue(Value); }
const SSCHAR* GetSrConditionOperatorString	(const int Value) { return s_SrConditionOperatorsMap.FindValue(Value); }

bool GetSrMagicSchoolValue			(int& Value, const SSCHAR* pString) { return s_SrMagicSchoolsMap.FindString(Value, pString); }
bool GetSrMagicTypeValue			(int& Value, const SSCHAR* pString) { return s_SrMagicTypesMap.FindString(Value, pString); }
bool GetSrConditionOperatorValue	(int& Value, const SSCHAR* pString) { return s_SrConditionOperatorsMap.FindString(Value, pString); }
/*===========================================================================
 *		End of String Table Lookup Functions
 *=========================================================================*/


/*===========================================================================
 *
 * Function - bool SrFixupFormid (OutputFormID, OrigFormID, FixupArray);
 *
 *=========================================================================*/
bool SrFixupFormid (srformid_t& OutputFormID, const srformid_t OrigFormID, CSrFormidFixupArray& FixupArray) 
{
  dword OldModIndex;
  dword NewModIndex;

	/* Special case for the NULL formid */
  if (OrigFormID == SR_FORMID_NULL) 
  {
    OutputFormID = SR_FORMID_NULL;
    return (true);
  }

  OldModIndex = SR_GETMODINDEX(OrigFormID);
  
  if (!FixupArray.IsValidIndex(OldModIndex)) 
  {
    AddSrGeneralError("Warning: Modindex of form 0x%08X is not valid (must be 0-%d)!", OrigFormID, FixupArray.GetSize()-1);
    //return (false); //Turn into just a warning?
  }
  
  NewModIndex  = FixupArray[OldModIndex];
  OutputFormID = SR_MAKEFORMID(OrigFormID, NewModIndex);
  return (true);
}
/*===========================================================================
 *		End of Function SrFixupFormid()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindData (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindData (const byte* pData, const dword Size, srfinddata_t& FindData) 
{
  if ((FindData.Flags & SR_FIND_CASESENSITIVE) != 0) return SrFindDataCase(pData, Size, FindData);
  return SrFindDataNoCase(pData, Size, FindData); 
}
/*===========================================================================
 *		End of Function SrFindData()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindTextData (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindTextData (const byte* pData, const dword Size, srfinddata_t& FindData)
{
  if ((FindData.Flags & SR_FIND_CASESENSITIVE) != 0) return SrFindTextDataCase(pData, Size, FindData);
  return SrFindTextDataNoCase(pData, Size, FindData); 
}
/*===========================================================================
 *		End of Function SrFindTextData()
 *=========================================================================*/
 

/*===========================================================================
 *
 * Function - dword SrFindDataNoCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindDataNoCase (const byte* pData, const dword Size, srfinddata_t& FindData) {
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);
  
  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size) {
    if (pParse2[FindIndex] == pParse1[0]) {
      ++FindIndex;

      if (FindIndex == FindData.DataSize) {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
	++FindCount;
	if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
	FindIndex = 0;
      }
    }
    else {
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindDataNoCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindDataCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindDataCase (const byte* pData, const dword Size, srfinddata_t& FindData) 
{
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);
 
  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size) 
  {

    if (pParse2[FindIndex] == pParse1[0]) 
	{
      ++FindIndex;

      if (FindIndex == FindData.DataSize) 
	  {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
		++FindCount;
		if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
		FindIndex = 0;
      }
    }
    else
	{
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindDataCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindTextDataNoCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindTextDataNoCase (const byte* pData, const dword Size, srfinddata_t& FindData)
{
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);

  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size)
  {

  		/* Stop searching on the first non-text character */
    if (*pParse1 < 0x05 || *pParse1 > 0x7f) break;

    if (tolower(pParse2[FindIndex]) == tolower(pParse1[0]))
	{
      ++FindIndex;

      if (FindIndex == FindData.DataSize) 
	  {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
		++FindCount;
		if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
		FindIndex = 0;
      }
    }
    else 
	{
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindTextDataNoCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindTextDataCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindTextDataCase (const byte* pData, const dword Size, srfinddata_t& FindData)
{
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);

  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size)
  {

    		/* Stop searching on the first non-text character */
    if (*pParse1 < 0x05 || *pParse1 > 0x7f) break;

    if (tolower(pParse2[FindIndex]) == tolower(pParse1[0]))
	{
      ++FindIndex;

      if (FindIndex == FindData.DataSize)
	  {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
		++FindCount;
		if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
		FindIndex = 0;
      }
    }
    else
	{
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindTextDataCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - bool SrContainsRecordType (Name, pArray);
 *
 *=========================================================================*/
bool SrContainsRecordType (const srrectype_t Name, const srrectype_t* pArray)
{
  if (pArray == NULL) return (false);

  while (*pArray != SR_NAME_NULL)
  {
    if (*pArray == Name) return (true);
    ++pArray;
  }

  return (false);
}
/*===========================================================================
 *		End of Function SrContainsRecordType()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - bool SrPrepareEditorID (EditorID);
 *
 * Prepares the given editorID for use, removing whitespace and any invalid
 * characters. Returns false if the final result is not a valid editor ID.
 *
 *=========================================================================*/
bool SrPrepareEditorID (CSString& EditorID)
{

	/* Remove all whitespace */
  EditorID.Trim();

	/* Ensure the ID is only alpha-numeric */
  EditorID.RemoveCharsToMatch(isalnum);

	/* Empty string is not a valid ID */
  if (EditorID.IsEmpty()) return (false);

  return (true);
}
/*===========================================================================
 *		End of Function SrPrepareEditorID()
 *=========================================================================*/


