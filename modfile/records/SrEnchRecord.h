/*===========================================================================
 *
 * File:		SrEnchrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrEnchRecord class.
 *
 *=========================================================================*/
#ifndef __SRENCHRECORD_H
#define __SRENCHRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srctdasubrecord.h"
	#include "../subrecords/srenitsubrecord.h"
	#include "../subrecords/srefitsubrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrEnchRecord Definition
 *
 *=========================================================================*/
class CSrEnchRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrEnchRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*			m_pBounds;
	CSrLStringSubrecord*	m_pItemName;
	CSrEnitSubrecord*		m_pEffectData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
  CSrEnchRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrEnchRecord; }

		/* Get class members */
  srenitdata_t& GetEnchantData (void) { return m_pEffectData ? m_pEffectData->GetEnchantData() : s_NullEffectData; }

  dword		  GetEffectCount (void) { return CountSubrecords(SR_NAME_EFIT); }
  const char* GetBaseEnchant (void);
  const char* GetItemTypes   (void);
  void        SetBaseEnchant (const char* pString);
  void        SetItemTypes   (const char* pString);
  

		/* Initialize a new record */
  void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


		/* Begin field method definitions */
	DECLARE_SRFIELD(FieldBaseEnchant)
	DECLARE_SRFIELD(FieldUserData)
	DECLARE_SRFIELD(FieldItemTypes)
	DECLARE_SRFIELD(FieldEffectCount)
	DECLARE_SRFIELD(FieldEnchantCost)
	DECLARE_SRFIELD(FieldCharge)
	DECLARE_SRFIELD_CONDITION(CSrEnchRecord);
	DECLARE_SRFIELD_FULLNAME(CSrEnchRecord);


	static srenitdata_t	s_NullEffectData;
};
/*===========================================================================
 *		End of Class CSrEnchRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrEnchRecord.H
 *=========================================================================*/
