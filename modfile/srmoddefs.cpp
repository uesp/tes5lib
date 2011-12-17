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


BEGIN_STRINGVALUE(s_SrSpellTypes)
	ADD_STRINGVALUE( SR_SPELL_TYPE_SPELL,		"Spell")
	ADD_STRINGVALUE( SR_SPELL_TYPE_DISEASE,		"Disease")
	ADD_STRINGVALUE( SR_SPELL_TYPE_POWER,		"Destruction")
	ADD_STRINGVALUE( SR_SPELL_TYPE_LESSERPOWER,	"Lesser Power")
	ADD_STRINGVALUE( SR_SPELL_TYPE_ABILITY,		"Ability")
	ADD_STRINGVALUE( SR_SPELL_TYPE_POISON,		"Poison")
	ADD_STRINGVALUE( SR_SPELL_TYPE_VOICE,		"Voice")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSpellCastAnims)
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_NONE,		"None")
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_PROJECTILE,	"Projectile")
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_SUSTAINED,	"Sustained")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSpellCastTypes)
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_0,		"CastType0")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_1,		"CastType1")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_2,		"CastType2")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_3,		"CastType3")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_4,		"CastType4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeA)
	ADD_STRINGVALUE( 0,		"0")
	ADD_STRINGVALUE( 1,		"1")
	ADD_STRINGVALUE( 4,		"4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeB)
	ADD_STRINGVALUE( 0,		"0")
	ADD_STRINGVALUE( 1,		"1")
	ADD_STRINGVALUE( 2,		"2")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeC)
	ADD_STRINGVALUE( 0,		"0")
	ADD_STRINGVALUE( 1,		"1")
	ADD_STRINGVALUE( 2,		"2")
	ADD_STRINGVALUE( 3,		"3")
	ADD_STRINGVALUE( 4,		"4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeD)
	ADD_STRINGVALUE( 6,		"6")
	ADD_STRINGVALUE( 12,	"12")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrBodyParts)
	ADD_STRINGVALUE( SR_BODYPARTS_SKIN				,	"Skin")
	ADD_STRINGVALUE( SR_BODYPARTS_HEAD				,	"Head")
	ADD_STRINGVALUE( SR_BODYPARTS_CHEST				,	"Chest")
	ADD_STRINGVALUE( SR_BODYPARTS_HANDS				,	"Hands")
	ADD_STRINGVALUE( SR_BODYPARTS_BEARD				,	"Beard")
	ADD_STRINGVALUE( SR_BODYPARTS_AMULET			,	"Amulet")
	ADD_STRINGVALUE( SR_BODYPARTS_RING				,	"Ring")
	ADD_STRINGVALUE( SR_BODYPARTS_FEET				,	"Feet")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN1			,	"0x00000100")
	ADD_STRINGVALUE( SR_BODYPARTS_SHIELD			,	"Shield")
	ADD_STRINGVALUE( SR_BODYPARTS_ANIMALSKIN		,	"AnimalSkin")
	ADD_STRINGVALUE( SR_BODYPARTS_UNDERSKIN			,	"UnderSkin")
	ADD_STRINGVALUE( SR_BODYPARTS_CROWN				,	"Crown")
	ADD_STRINGVALUE( SR_BODYPARTS_FACE				,	"Face")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONHEAD		,	"DragonHead")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONLWING		,	"DragonLeftWing")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONRWING		,	"DragonRightWing")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONBODY		,	"DragonBody")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN3			,	"0x00100000")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN4			,	"0x00300000")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN2			,	"0x80000000")
END_STRINGVALUE()

BEGIN_STRINGVALUE(s_SrArmorTypes)
	ADD_STRINGVALUE( SR_ARMORTYPE_NONE,		"None")
	ADD_STRINGVALUE( SR_ARMORTYPE_LIGHT,	"Light")
	ADD_STRINGVALUE( SR_ARMORTYPE_HEAVY,	"Heavy")
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

const SSCHAR* GetSrSpellTypeString		(const int Value) { return s_SrSpellTypesMap.FindValue(Value); }
const SSCHAR* GetSrSpellCastTypeString	(const int Value) { return s_SrSpellCastTypesMap.FindValue(Value); }
const SSCHAR* GetSrSpellCastAnimString	(const int Value) { return s_SrSpellCastAnimsMap.FindValue(Value); }

const SSCHAR* GetSrEnchantTypeAString	(const int Value) { return s_SrEnchantTypeAMap.FindValue(Value); }
const SSCHAR* GetSrEnchantTypeBString	(const int Value) { return s_SrEnchantTypeBMap.FindValue(Value); }
const SSCHAR* GetSrEnchantTypeCString	(const int Value) { return s_SrEnchantTypeCMap.FindValue(Value); }
const SSCHAR* GetSrEnchantTypeDString	(const int Value) { return s_SrEnchantTypeDMap.FindValue(Value); }

const SSCHAR* GetSrBodyPartString		(const int Value) { return s_SrBodyPartsMap.FindValue(Value); }
const SSCHAR* GetSrArmorTypeString		(const int Value) { return s_SrArmorTypesMap.FindValue(Value); }

CSString GetSrBodyPartFlagString	(const dword Value) 
{ 
	CSString Buffer;

	for (dword i = 0; s_SrBodyParts[i].pString != NULL; ++i)
	{
		if (s_SrBodyParts[i].Value & Value)
		{
			Buffer += s_SrBodyParts[i].pString;
			Buffer += " ";
		}
	}

	return Buffer;
}


bool GetSrMagicSchoolValue			(int& Value, const SSCHAR* pString) { return s_SrMagicSchoolsMap.FindString(Value, pString); }
bool GetSrMagicTypeValue			(int& Value, const SSCHAR* pString) { return s_SrMagicTypesMap.FindString(Value, pString); }
bool GetSrConditionOperatorValue	(int& Value, const SSCHAR* pString) { return s_SrConditionOperatorsMap.FindString(Value, pString); }

bool GetSrSpellTypeValue		(int& Value, const SSCHAR* pString) { return s_SrSpellTypesMap.FindString(Value, pString); }
bool GetSrSpellCastTypeValue	(int& Value, const SSCHAR* pString) { return s_SrSpellCastTypesMap.FindString(Value, pString); }
bool GetSrSpellCastAnimValue	(int& Value, const SSCHAR* pString) { return s_SrSpellCastAnimsMap.FindString(Value, pString); }

bool GetSrEnchantTypeAValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeAMap.FindString(Value, pString); }
bool GetSrEnchantTypeBValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeBMap.FindString(Value, pString); }
bool GetSrEnchantTypeCValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeCMap.FindString(Value, pString); }
bool GetSrEnchantTypeDValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeDMap.FindString(Value, pString); }

bool GetSrBodyPartValue	 (int& Value, const SSCHAR* pString) { return s_SrBodyPartsMap.FindString(Value, pString); }
bool GetSrArmorTypeValue (int& Value, const SSCHAR* pString) { return s_SrArmorTypesMap.FindString(Value, pString); }


bool GetSrBodyPartFlagValue	(dword& Value, const SSCHAR* pString) 
{ 
	CSString	  Source(pString);
	CSStringArray SplitStrings;
	int 		  Flag;

	Value = 0;
	SplitString(SplitStrings, Source, ' ');

	for (dword i = 0; i < SplitStrings.GetSize(); ++i)
	{
		if (GetSrBodyPartValue(Flag, *SplitStrings[i])) Value |= Flag;
	}

	return true;
}

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


bool SrIsRecipeComponent (const srrectype_t Type)
{
	if (Type == SR_NAME_ALCH) return true;
	if (Type == SR_NAME_ARMO) return true;
	if (Type == SR_NAME_BOOK) return true;
	if (Type == SR_NAME_INGR) return true;
	if (Type == SR_NAME_MISC) return true;
	if (Type == SR_NAME_SCRL) return true;
	if (Type == SR_NAME_WEAP) return true;

	return false;
}


bool SrIsRecipeResult (const srrectype_t Type)
{
	if (Type == SR_NAME_ALCH) return true;
	if (Type == SR_NAME_ARMO) return true;
	if (Type == SR_NAME_BOOK) return true;	
	if (Type == SR_NAME_INGR) return true;
	if (Type == SR_NAME_MISC) return true;
	if (Type == SR_NAME_SCRL) return true;
	if (Type == SR_NAME_WEAP) return true;

	return false;
}