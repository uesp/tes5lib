/*===========================================================================
 *
 * File:		SrLvlirecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrLvliRecord class.
 *
 *=========================================================================*/
#ifndef __SRLVLIRECORD_H
#define __SRLVLIRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srlvlosubrecord.h"
	#include "../subrecords/srbytesubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


	#define SR_LVLIFLAG_CALCULATEEACH	0x01
	#define SR_LVLIFLAG_CALCULATEALL	0x02
	#define SR_LVLIFLAG_USEALL			0x04

	#define SR_LVLI_MAXITEMCOUNT			255


/*===========================================================================
 *
 * Begin Class CSrLvliRecord Definition
 *
 *=========================================================================*/
class CSrLvliRecord : public CSrIdRecord 
{
	DECLARE_SRSUBRECCREATE()
	DECLARE_SRFIELDMAP()
	DECLARE_SRCLASS(CSrLvliRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*			m_pObndData;
	CSrByteSubrecord*		m_pChanceNone;
	CSrByteSubrecord*		m_pFlags;
	CSrByteSubrecord*		m_pItemCount;
	CSrFormidSubrecord*		m_pGlobal;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrLvliRecord();
	virtual void Destroy (void);

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrLvliRecord; }

		/* Get class members */
	dword GetItemCount    (void) { return m_pItemCount ? m_pItemCount->GetValue() : 0; }
	byte  GetListFlags    (void) { return m_pFlags ? m_pFlags->GetValue() : 0; }
	byte  GetChanceNone   (void) { return m_pChanceNone ? m_pChanceNone->GetValue() : 0; }
	bool  IsCalculateEach (void) { return CheckFlagBits(GetListFlags(), SR_LVLIFLAG_CALCULATEEACH); }
	bool  IsCalculateAll  (void) { return CheckFlagBits(GetListFlags(), SR_LVLIFLAG_CALCULATEALL); }
	bool  IsUseAll        (void) { return CheckFlagBits(GetListFlags(), SR_LVLIFLAG_USEALL); }  

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	void SetChanceNone    (const byte Value);
	void SetCalculateEach (const bool Flag);
	void SetCalculateAll  (const bool Flag);
	void SetUseAll        (const bool Flag);
	void UpdateItemCount  (void);


		/* Begin field method definitions */
    DECLARE_SRFIELD_BYTE(CSrLvliRecord, ChanceNone, GetChanceNone, SetChanceNone)
    DECLARE_SRFIELD_DWORD1(CSrLvliRecord, ItemCount, GetItemCount(), dword Tmp)
	DECLARE_SRFIELD_BOOL(CSrLvliRecord, CalculateEach, IsCalculateEach, SetCalculateEach)
	DECLARE_SRFIELD_BOOL(CSrLvliRecord, CalculateAll, IsCalculateAll, SetCalculateAll)
	DECLARE_SRFIELD_BOOL(CSrLvliRecord, UseAll, IsUseAll, SetUseAll)
	DECLARE_SRFIELD_EDITORID(CSrLvliRecord, Global, GetGlobal, SetGlobal)
	DECLARE_SRMETHOD_FORMID(Global, m_pGlobal, SR_NAME_LVLG)

};
/*===========================================================================
 *		End of Class CSrLvliRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrLvliRecord.H
 *=========================================================================*/
