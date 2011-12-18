/*===========================================================================
 *
 * File:		SrScrlrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrScrlRecord class.
 *
 *=========================================================================*/
#ifndef __SRSCRLRECORD_H
#define __SRSCRLRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sritem1record.h"
	#include "../subrecords/srlstringsubrecord.h"
	#include "../subrecords/srspitsubrecord.h"
	#include "../subrecords/srscrldatasubrecord.h"
	#include "../subrecords/srefitsubrecord.h"
	#include "../subrecords/srctdasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrScrlRecord Definition
 *
 *=========================================================================*/
class CSrScrlRecord : public CSrItem1Record 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrScrlRecord, CSrItem1Record)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrFormidSubrecord*		m_pEquipmentSlot;
	CSrSubrecord*			m_pBoundsData;
	CSrLStringSubrecord*	m_pDescription;
	CSrSubrecord*			m_pMdobData;
	CSrSubrecord*			m_pModtData;
	CSrScrlDataSubrecord*	m_pScrlData;
	CSrSpitSubrecord*		m_pSpitData;

	static srscrldata_t	s_NullScrollData;
	static srspitdata_t	s_NullSpitData;
	

  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:
	
		/* Class Constructors/Destructors */
	CSrScrlRecord();
	virtual void Destroy (void);
	
	   	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrScrlRecord; }
	
		/* Get class members */
	srscrldata_t& GetScrollData (void) { return m_pScrlData ? m_pScrlData->GetScrlData() : s_NullScrollData; }
	srspitdata_t& GetSpitData   (void) { return m_pSpitData ? m_pSpitData->GetSpellData() : s_NullSpitData; }
	dword GetEffectCount (void) { return CountSubrecords(SR_NAME_EFID); }
	const char* GetCastAnim (void) { return GetSrSpellCastAnimString(GetSpitData().CastAnim); }
	const char* GetCastType (void) { return GetSrSpellCastTypeString(GetSpitData().CastType); }

  		/* Initialize a new record */
	void InitializeNew (void);
	
		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	void SetCastAnim (const char* pString) { GetSrSpellCastAnimValue(GetSpitData().CastAnim, pString); }
	void SetCastType (const char* pString) { GetSrSpellCastTypeValue(GetSpitData().CastType, pString); }

	
		/* Begin field method definitions */
	DECLARE_SRFIELD_DESCRIPTION(CSrScrlRecord, SR_NAME_DESC)

	DECLARE_SRFIELD_DWORD1(CSrScrlRecord, EffectCount, GetEffectCount(), dword Tmp);
	DECLARE_SRFIELD_DWORD1(CSrScrlRecord, Value, GetScrollData().Value, GetScrollData().Value)
	DECLARE_SRFIELD_FLOAT1(CSrScrlRecord, Weight, GetScrollData().Weight, GetScrollData().Weight)

	DECLARE_SRFIELD_DWORD1(CSrScrlRecord, Cost, GetSpitData().BaseCost, GetSpitData().BaseCost)
	DECLARE_SRFIELD_FLOAT1(CSrScrlRecord, CastTime, GetSpitData().CastTime, GetSpitData().CastTime)

	DECLARE_SRFIELD_METHOD(CSrScrlRecord, CastAnim, GetCastAnim, SetCastAnim)
	DECLARE_SRFIELD_METHOD(CSrScrlRecord, CastType, GetCastType, SetCastType)
	
	DECLARE_SRFIELD_EDITORID(CSrScrlRecord, EquipSlot, GetEquipSlot, SetEquipSlot)
	DECLARE_SRMETHOD_FORMID(EquipSlot, m_pEquipmentSlot, SR_NAME_ETYP)
	
};
/*===========================================================================
 *		End of Class CSrScrlRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrScrlRecord.H
 *=========================================================================*/
