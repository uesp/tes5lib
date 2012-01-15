/*===========================================================================
 *
 * File:		SrSpelrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrSpelRecord class.
 *
 *=========================================================================*/
#ifndef __SRSPELRECORD_H
#define __SRSPELRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srformidsubrecord.h"
	#include "../subrecords/srspitsubrecord.h"
    #include "../subrecords/srlstringsubrecord.h"
	#include "../subrecords/srefitsubrecord.h"
	#include "../subrecords/srctdasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrSpelRecord Definition
 *
 *=========================================================================*/
class CSrSpelRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrSpelRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrFormidSubrecord*		m_pEquipmentSlot;
	CSrSubrecord*			m_pBoundsData;
	CSrLStringSubrecord*	m_pItemName;
	CSrLStringSubrecord*	m_pDescription;
	CSrSpitSubrecord*		m_pSpellData;

	static srspitdata_t	s_NullSpellData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSpelRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrSpelRecord; }

	/* Get class members */
  srspitdata_t& GetSpellData (void) { return m_pSpellData ? m_pSpellData->GetSpellData() : s_NullSpellData; }
  const char* GetPerk (void);
  srformid_t  GetEquipSlotID (void) { return m_pEquipmentSlot ? m_pEquipmentSlot->GetValue() : 0; }
  const char* GetEquipSlot (void);
  bool IsAutoCalc (void) { return m_pSpellData ? m_pSpellData->IsAutoCalc() : false; }

  dword GetEffectCount (void) { return CountSubrecords(SR_NAME_EFID); }

  void SetPerk      (const char* pEditorID);
  void SetEquipSlot (const char* pEditorID);
  void SetEquipSlot (const srformid_t FormID);
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

		/* Begin field method definitions */
  DECLARE_SRFIELD(FieldPerkID)
  DECLARE_SRFIELD(FieldPerk)
  DECLARE_SRFIELD(FieldEquipSlotID)
  DECLARE_SRFIELD(FieldEquipSlot)
  DECLARE_SRFIELD(FieldSpellType)
  DECLARE_SRFIELD(FieldSpellFlags)
  DECLARE_SRFIELD(FieldCastAnim)
  DECLARE_SRFIELD(FieldCastTime)
  DECLARE_SRFIELD(FieldCastType)
  DECLARE_SRFIELD(FieldAutoCalc)
  DECLARE_SRFIELD(FieldCost)
  DECLARE_SRFIELD(FieldUnknown1)
  DECLARE_SRFIELD(FieldUnknown2)
  DECLARE_SRFIELD(FieldEffectCount)

  DECLARE_SRFIELD_FULLNAME(CSrSpelRecord);
  DECLARE_SRFIELD_DESCRIPTION(CSrSpelRecord, SR_NAME_DESC);
};
/*===========================================================================
 *		End of Class CSrSpelRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrSpelRecord.H
 *=========================================================================*/
