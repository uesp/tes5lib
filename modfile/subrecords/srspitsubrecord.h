/*===========================================================================
 *
 * File:		Srspitsubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	12 December 2011
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRSPITSUBRECORD_H
#define __SRSPITSUBRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "srsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

	#define SRSPIT_SUBRECORD_SIZE	36

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/
#pragma pack(push, 1)

	struct srspitdata_t 
	{
		dword		BaseCost;
		word		AutoCalc;
		word		Flags;
		dword		SpellType;
		float		CastTime;
		int			CastAnim;
		int			CastType;
		float		Unknown1;
		float		Unknown2;
		srformid_t	PerkID;
	};

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrSpitSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrSpitSubrecord : public CSrSubrecord 
{
  DECLARE_SRCLASS(CSrSpitSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srspitdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { return File.Read(&m_Data,  m_RecordSize); }
  virtual bool WriteData (CSrFile& File) { return File.Write(&m_Data, m_RecordSize); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSpitSubrecord();
  //virtual ~CSrSpitSubrecord() { Destroy(); }
  virtual void Destroy (void);

		/* Change any matching formid in the subrecord */
  virtual dword ChangeFormID (const srformid_t NewID, const srformid_t OldID) 
  {
	if (m_Data.PerkID == OldID) 
	{
	  m_Data.PerkID = NewID;
	  return (1);
	}

	return (0); 
  }

  virtual dword CountUses (const srformid_t FormID) 
  {
	  return (FormID == m_Data.PerkID);
  }

		/* Fixup the modindex of formids */
  virtual bool FixupFormID (CSrFormidFixupArray& FixupArray) 
  {
	return SrFixupFormid(m_Data.PerkID, m_Data.PerkID, FixupArray);
  }

	/* Compare two subrecord fields */
  virtual bool CompareFields (int& Result, const int FieldID, CSrSubrecord* pSubrecord);

  	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) 
  {
	CSrSpitSubrecord* pSubrecord1 = SrCastClassNull(CSrSpitSubrecord, pSubrecord);
	m_RecordSize = SRSPIT_SUBRECORD_SIZE;

	if (pSubrecord1 != NULL) 
	{
	  m_Data = pSubrecord1->GetSpellData();
	}
	else 
	{
	  memset(&m_Data, 0, sizeof(m_Data));
	}
	return (true);
  }

  	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrSpitSubrecord); }

	/* Get class members */
  srspitdata_t& GetSpellData	(void) { return (m_Data); }
  virtual byte*	GetData			(void) { return (byte *)(&m_Data); }
  bool          IsAutoCalc		(void) { return m_Data.AutoCalc == 0; }

  	/* Get a string representation of a subrecord field */
  bool GetField (CSString& Buffer, const int FieldID);
  	
	/* Initialize a new record */
  void InitializeNew (void);

	/* Set class members */
  void SetAutoCalc (const bool  Flag)  { m_Data.AutoCalc = !Flag; }

};
/*===========================================================================
 *		End of Class CSrSpitSubrecord Definition
 *=========================================================================*/




#endif
/*===========================================================================
 *		End of File Srenitsubrecord.H
 *=========================================================================*/
