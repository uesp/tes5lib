/*===========================================================================
 *
 * File:		Srweaprecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Defines the CSrWeapRecord class for weapon records.
 *
 *=========================================================================*/
#ifndef __SRWEAPRECORD_H
#define __SRWEAPRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sritem2record.h"
  #include "../subrecords/srweapdatasubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrWeapRecord Definition
 *
 * Holds weapon data.
 *
 *=========================================================================*/
class CSrWeapRecord : public CSrItem2Record 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrWeapRecord, CSrItem2Record)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  CSrWeapDataSubrecord*		m_pWeaponData;
  CSrDwordSubrecord*		m_pVNAM;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrWeapRecord();
  //virtual ~CSrWeapRecord() { Destroy(); }
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrWeapRecord; }

	/* Get class members */
  srweapdata_t* GetWeaponData	  (void) { return (m_pWeaponData   ? &m_pWeaponData->GetWeaponData() : NULL); }
  float         GetWeight		  (void) { return (m_pWeaponData   ?  m_pWeaponData->GetWeight()     : 0.0f); }
  dword         GetValue		  (void) { return (m_pWeaponData   ?  m_pWeaponData->GetValue()      : 0); }
  word          GetDamage		  (void) { return (m_pWeaponData   ?  m_pWeaponData->GetDamage()     : 0); }
  dword			GetVNAM           (void) { return m_pVNAM ? m_pVNAM->GetValue() : 0; }
  const SSCHAR*	GetWeaponType     (void);
  const SSCHAR*	GetWeaponMaterial (void);

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

  	/* Set class members */
  void SetWeight (const float Value) { if (m_pWeaponData != NULL) m_pWeaponData->SetWeight(Value); }
  void SetValue  (const dword Value) { if (m_pWeaponData != NULL) m_pWeaponData->SetValue(Value); }
  void SetDamage (const word  Value) { if (m_pWeaponData != NULL) m_pWeaponData->SetDamage(Value); }
  void SetVNAM   (const dword Value) { if (m_pVNAM != NULL) m_pVNAM->SetValue(Value); }
  void SetWeaponType     (const srformid_t FormID);
  void SetWeaponMaterial (const srformid_t FormID);
  	 

	/* Begin field method definitions */
  DECLARE_SRFIELD(FieldWeight)
  DECLARE_SRFIELD(FieldValue)
  DECLARE_SRFIELD(FieldDamage)
  DECLARE_SRFIELD(FieldType)
  DECLARE_SRFIELD(FieldMaterial)
  DECLARE_SRFIELD(FieldVNAM)

};
/*===========================================================================
 *		End of Class CSrWeapRecord Definition
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Function Definitions
 *
 *=========================================================================*/
/*===========================================================================
 *		End of Function Definitions
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srweaprecord.H
 *=========================================================================*/
