/*===========================================================================
 *
 * File:		SrAlchrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrAlchRecord class.
 *
 *=========================================================================*/
#ifndef __SRALCHRECORD_H
#define __SRALCHRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sritem1record.h"
	#include "../subrecords/srenitalchsubrecord.h"
	#include "../subrecords/srefitsubrecord.h"
	#include "../subrecords/sralchdatasubrecord.h"
	#include "../subrecords/srctdasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrAlchRecord Definition
 *
 *=========================================================================*/
class CSrAlchRecord : public CSrItem1Record 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrAlchRecord, CSrItem1Record)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*			m_pBoundsData;
	CSrSubrecord*			m_pModtData;
	CSrEnitAlchSubrecord*	m_pEnitData;
	CSrAlchDataSubrecord*	m_pAlchData;
	CSrFormidSubrecord*		m_pPickupSound;
	CSrFormidSubrecord*		m_pDropSound;
	CSrSubrecord*			m_pModsData;

	static sralchdata_t     s_NullAlchData;
	static srenitalchdata_t s_NullAlchEnitData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrAlchRecord();
	virtual void Destroy (void);

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrAlchRecord; }

		/* Get class members */
	sralchdata_t&     GetAlchData (void) { return m_pAlchData ? m_pAlchData->GetAlchData() : s_NullAlchData; }
	srenitalchdata_t& GetEnitData (void) { return m_pEnitData ? m_pEnitData->GetAlchData() : s_NullAlchEnitData; }
	dword GetEffectCount (void) { return CountSubrecords(SR_NAME_EFID); }  
	const char* GetPotionType (void) { return GetSrPotionTypeString(GetEnitData().Type); }

	const char* GetUseSound (void) { return CSrRecord::GetEditorIDHelper(GetEnitData().UseSoundID); } 

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	void SetPotionType (const char* pString) { GetSrPotionTypeValue(GetEnitData().Type, pString); }

	void SetUseSound (const char* pString);


	DECLARE_SRFIELD_EDITORID(CSrAlchRecord, UseSound,  GetUseSound,  SetUseSound)

	DECLARE_SRFIELD_METHOD(CSrAlchRecord, Type, GetPotionType, SetPotionType)
	DECLARE_SRFIELD_DWORD1(CSrAlchRecord, Value, GetEnitData().Value, GetEnitData().Value)
	DECLARE_SRFIELD_FLOAT1(CSrAlchRecord, Weight, GetAlchData().Weight, GetAlchData().Weight)

	DECLARE_SRFIELD_EDITORID(CSrAlchRecord, PickupSound,  GetPickupSound,  SetPickupSound)
	DECLARE_SRMETHOD_FORMID(PickupSound, m_pPickupSound, SR_NAME_YNAM)

	DECLARE_SRFIELD_EDITORID(CSrAlchRecord, DropSound,  GetDropSound,  SetDropSound)
	DECLARE_SRMETHOD_FORMID(DropSound, m_pDropSound, SR_NAME_ZNAM)

	DECLARE_SRFIELD_DWORD1(CSrAlchRecord, EffectCount, GetEffectCount(), dword Tmp);

};
/*===========================================================================
 *		End of Class CSrAlchRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrAlchRecord.H
 *=========================================================================*/


