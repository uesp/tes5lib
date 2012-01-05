/*===========================================================================
 *
 * File:		SrPerkrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrPerkRecord class.
 *
 *=========================================================================*/
#ifndef __SRPERKRECORD_H
#define __SRPERKRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
	#include "../subrecords/srbytesubrecord.h"
	#include "../subrecords/srctdasubrecord.h"
	#include "../subrecords/srperkdatasubrecord.h"
	#include "../subrecords/srprkesubrecord.h"
	#include "../subrecords/srepfdsubrecord.h"
	#include "../subrecords/srarraysubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrPerkRecord Definition
 *
 *
 PRKE-0
 DATA-0
 PRKF

 PRKE-1
 DATA-1
 PRKF

 PRKE-2
 DATA-2
	PRKC
	CTDA
	CIS1
	CIS2
 EPFT
 EPFD
 EPF2
 EPF3
 PRKF

 *=========================================================================*/
class CSrPerkRecord : public CSrIdRecord 
{
	DECLARE_SRSUBRECCREATE()
	DECLARE_SRFIELDMAP()
	DECLARE_SRCLASS(CSrPerkRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrLStringSubrecord*	m_pDescription;
	CSrLStringSubrecord*	m_pItemName;
	CSrPerkDataSubrecord*	m_pPerkData;
	CSrFormidSubrecord*		m_pNextPerk;

	CSrArraySubrecord*		m_pCurrentSection;
	CSrArraySubrecord*		m_pCurrentSubSection;

	CSrByteSubrecord*		m_pLastEPFT;

	static srperkdata_t s_NullPerkData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrPerkRecord();
	virtual void Destroy (void);

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrPerkRecord; }

		/* Get class members */
	srperkdata_t& GetPerkData       (void) { return m_pPerkData ? m_pPerkData->GetPerkData() : s_NullPerkData; }  
	dword         CountPerkSections (void) { return CountSubrecords(SR_NAME_PRKE); }

		/* Only count the base conditions and not the section conditions */
	dword GetBaseConditionCount (void);

	const char* GetDataUnknown1 (void) { return GetSrPerkDataUnknown1TypeString((int) GetPerkData().Unknown1); }
	const char* GetDataUnknown2 (void) { return GetSrPerkDataUnknown2TypeString((int) GetPerkData().Unknown2); }
	const char* GetDataUnknown3 (void) { return GetSrPerkDataUnknown3TypeString((int) GetPerkData().Unknown3); }

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	void SetDataUnknown1 (const char* pString) { int Value(1); GetSrPerkDataUnknown1TypeValue(Value, pString); GetPerkData().Unknown1 = Value; }
	void SetDataUnknown2 (const char* pString) { int Value(1); GetSrPerkDataUnknown2TypeValue(Value, pString); GetPerkData().Unknown2 = Value; }
	void SetDataUnknown3 (const char* pString) { int Value(1); GetSrPerkDataUnknown3TypeValue(Value, pString); GetPerkData().Unknown3 = Value; }


		/* Begin field method definitions */
	DECLARE_SRFIELD_FULLNAME(CSrPerkRecord)
	DECLARE_SRFIELD_DESCRIPTION(CSrPerkRecord, SR_NAME_DESC)
	DECLARE_SRFIELD_EDITORID1(CSrPerkRecord, NextPerk, SR_NAME_NNAM)

	DECLARE_SRFIELD_METHOD(CSrPerkRecord, Unknown1, GetDataUnknown1, SetDataUnknown1)
	DECLARE_SRFIELD_METHOD(CSrPerkRecord, Unknown2, GetDataUnknown2, SetDataUnknown2)
	DECLARE_SRFIELD_METHOD(CSrPerkRecord, Unknown3, GetDataUnknown3, SetDataUnknown3)

	DECLARE_SRFIELD_DWORD1(CSrPerkRecord, PerkSections, CountPerkSections(), dword Tmp)
	DECLARE_SRFIELD_DWORD1(CSrPerkRecord, ConditionCount, GetBaseConditionCount(), dword Tmp)

};
/*===========================================================================
 *		End of Class CSrPerkRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrPerkRecord.H
 *=========================================================================*/
