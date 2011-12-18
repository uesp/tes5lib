/*===========================================================================
 *
 * File:		SrIngrrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrIngrRecord class.
 *
 *=========================================================================*/
#ifndef __SRINGRRECORD_H
#define __SRINGRRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sritem1record.h"
	#include "../subrecords/sringrenitsubrecord.h"
	#include "../subrecords/sringrdatasubrecord.h"
	#include "../subrecords/srefitsubrecord.h"
	#include "../subrecords/srctdasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrIngrRecord Definition
 *
 *=========================================================================*/
class CSrIngrRecord : public CSrItem1Record 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrIngrRecord, CSrItem1Record)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*			m_pBoundsData;
	CSrIngrEnitSubrecord*	m_pEnitData;
	CSrIngrDataSubrecord*	m_pIngrData;
	CSrSubrecord*			m_pModtData;
	CSrFormidSubrecord*		m_pPickupSound;
	CSrFormidSubrecord*		m_pDropSound;

	static sringrdata_t     s_NullIngrData;
	static sringrenitdata_t s_NullIngrEnitData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrIngrRecord();
	virtual void Destroy (void);

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrIngrRecord; }

		/* Get class members */
	sringrdata_t&     GetIngrData (void) { return m_pIngrData ? m_pIngrData->GetIngrData() : s_NullIngrData; }
	sringrenitdata_t& GetEnitData (void) { return m_pEnitData ? m_pEnitData->GetIngrData() : s_NullIngrEnitData; }
	dword GetEffectCount (void) { return CountSubrecords(SR_NAME_EFID); }  

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	DECLARE_SRFIELD_DWORD1(CSrIngrRecord, Unknown, GetEnitData().Unknown, GetEnitData().Unknown)

		/* Begin field method definitions */
	DECLARE_SRFIELD_DWORD1(CSrIngrRecord, Value, GetIngrData().Value, GetIngrData().Value)
	DECLARE_SRFIELD_FLOAT1(CSrIngrRecord, Weight, GetIngrData().Weight, GetIngrData().Weight)

	DECLARE_SRFIELD_EDITORID(CSrIngrRecord, PickupSound,  GetPickupSound,  SetPickupSound)
	DECLARE_SRMETHOD_FORMID(PickupSound, m_pPickupSound, SR_NAME_YNAM)

	DECLARE_SRFIELD_EDITORID(CSrIngrRecord, DropSound,  GetDropSound,  SetDropSound)
	DECLARE_SRMETHOD_FORMID(DropSound, m_pDropSound, SR_NAME_ZNAM)

	DECLARE_SRFIELD_DWORD1(CSrIngrRecord, EffectCount, GetEffectCount(), dword Tmp);

};
/*===========================================================================
 *		End of Class CSrIngrRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrIngrRecord.H
 *=========================================================================*/
