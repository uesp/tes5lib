/*===========================================================================
 *
 * File:		SrMgefRecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	1 December 2011
 *
 * Defines the CSrMgefRecord class for magic effect records.
 *
 *=========================================================================*/
#ifndef __SRMGEFRECORD_H
#define __SRMGEFRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sridkeyrecord.h"
  #include "../subrecords/srmgefdatasubrecord.h"
  #include "../subrecords/srlstringsubrecord.h"
  #include "../subrecords/srctdasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrMgefRecord Definition
 *
 * Holds magic effect data.
 *
 *=========================================================================*/
class CSrMgefRecord : public CSrIdKeyRecord {
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrMgefRecord, CSrIdKeyRecord)
  
  /*---------- Begin Protected Class Members --------------------*/
protected:
  CSrMgefDataSubrecord*	m_pData;
  CSrLStringSubrecord*	m_pFullName;
  CSrLStringSubrecord*	m_pDescription;

  static srmgefdata_t s_SrNullEffectData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrMgefRecord();
  //virtual ~CSrMgefRecord() { Destroy(); }
  virtual void Destroy (void);

  	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrMgefRecord; }

	/* Get class members */
  srmgefdata_t& GetEffectData  (void) { return m_pData ? m_pData->GetEffectData() : s_SrNullEffectData; }
  const char*   GetFullName    (void) { return m_pFullName ? m_pFullName->GetString().c_str() : ""; }
  const char*   GetDescription (void) { return m_pDescription ? m_pDescription->GetString().c_str() : ""; }
  dword			GetSchool	   (void) { return GetEffectData().School; }
  dword			GetEffectType  (void) { return GetEffectData().EffectType; }
  dword			GetConditionCount (void) { return CountSubrecords(SR_NAME_CTDA); }

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

	/* Set class members */
  void SetFullName    (const char* pString) { if (m_pFullName) m_pFullName->SetString(pString); }
  void SetDescription (const char* pString) { if (m_pDescription) m_pDescription->SetString(pString); }

	/* Begin field method definitions */
  DECLARE_SRFIELD(FieldFullName)
  DECLARE_SRFIELD(FieldDescription)
  DECLARE_SRFIELD(FieldSchool)
  DECLARE_SRFIELD(FieldEffectType)
  DECLARE_SRFIELD(FieldConditionCount)
  DECLARE_SRFIELD(FieldSkillLevel)
  DECLARE_SRFIELD(FieldCastingDelay)
  DECLARE_SRFIELD(FieldUserData)
  DECLARE_SRFIELD(FieldMagicFlags)
  DECLARE_SRFIELD(FieldBaseCost)
  
};
/*===========================================================================
 *		End of Class CSrMgefRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrMgefRecord.H
 *=========================================================================*/
