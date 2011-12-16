/*===========================================================================
 *
 * File:		Srenitsubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	12 December 2011
 *
 * Description
 *
 *=========================================================================*/
#ifndef __SRENITSUBRECORD_H
#define __SRENITSUBRECORD_H


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

	/* Standard ENIT subrecord size in bytes */
  #define SRENIT_SUBRECORD_SIZE	36

	/* Enchantment flags */
  #define SR_ENCHFLAG_MANUALCALC 0x00000001

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/
#pragma pack(push, 1)

	/* ENIT data structure */
  struct srenitdata_t 
  {
	dword		ChargeAmount;
	dword		TypeA;
	dword		TypeB;
	dword		EnchantCost;
	dword		TypeC;
	dword		TypeD;
	float		StaffMod;
	srformid_t	BaseEnchID;
	srformid_t	ItemTypesID;
  };

#pragma pack(pop)
/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrEnitSubrecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrEnitSubrecord : public CSrSubrecord 
{
  DECLARE_SRCLASS(CSrEnitSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srenitdata_t	m_Data;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { m_Data.ItemTypesID = 0; return File.Read(&m_Data,  m_RecordSize); }
  virtual bool WriteData (CSrFile& File) { return File.Write(&m_Data, m_RecordSize); }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrEnitSubrecord();
  //virtual ~CSrEnitSubrecord() { Destroy(); }
  virtual void Destroy (void);

	/* Compare two subrecord fields */
  virtual bool CompareFields (int& Result, const int FieldID, CSrSubrecord* pSubrecord);

  	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) {
	CSrEnitSubrecord* pSubrecord1 = SrCastClassNull(CSrEnitSubrecord, pSubrecord);
	m_RecordSize = SRENIT_SUBRECORD_SIZE;

	if (pSubrecord1 != NULL) 
	{
	  m_Data = pSubrecord1->GetEnchantData();
	}
	else 
	{
	  memset(&m_Data, 0, sizeof(m_Data));
	}
	return (true);
  }

  	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrEnitSubrecord); }

	/* Get class members */
  srenitdata_t& GetEnchantData	(void) { return (m_Data); }
  virtual byte*	GetData			(void) { return (byte *)(&m_Data); }
  dword			GetType			(void) { return (m_Data.TypeA); }
  dword			GetCharge		(void) { return (m_Data.ChargeAmount); }
  dword			GetCost			(void) { return (m_Data.EnchantCost); }
  bool          IsAutoCalc		(void) { return !CheckFlagBits(m_Data.TypeA, SR_ENCHFLAG_MANUALCALC); }

  	/* Get a string representation of a subrecord field */
  bool GetField (CSString& Buffer, const int FieldID);
  	
	/* Initialize a new record */
  void InitializeNew (void);

	/* Set class members */
  void SetAutoCalc (const bool  Flag)  { FlipFlagBits(m_Data.TypeA,  SR_ENCHFLAG_MANUALCALC, !Flag); }
  void SetType     (const dword Value) { m_Data.TypeA        = Value; }
  void SetCharge   (const dword Value) { m_Data.ChargeAmount = Value; }
  void SetCost     (const dword Value) { m_Data.EnchantCost  = Value; }

};
/*===========================================================================
 *		End of Class CSrEnitSubrecord Definition
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnitSubrecord Method - int CompareFields (Result, FieldID, pSubrecord);
 *
 *=========================================================================*/
inline bool CSrEnitSubrecord::CompareFields (int& Result, const int FieldID, CSrSubrecord* pSubrecord) {
  CSrEnitSubrecord* pEnit = SrCastClass(CSrEnitSubrecord, pSubrecord);

  if (pEnit != NULL) {

    switch (FieldID) {
      case SR_FIELD_CHARGE:
        Result = (int)GetCharge() - (int)pEnit->GetCharge();
		return (true);
      case SR_FIELD_COST:
        Result = (int)GetCost() - (int)pEnit->GetCost();
		return (true);
      case SR_FIELD_AUTOCALC:
        Result = (int)IsAutoCalc() - (int)pEnit->IsAutoCalc();
		return (true);
      case SR_FIELD_RANGE:
		Result = (int)GetType() - (int)pEnit->GetType();
		return (true);
     }

   }

	/* Check subrecord */
  return CSrSubrecord::CompareFields(Result, FieldID, pSubrecord);
 }
/*===========================================================================
 *		End of Class Method CSrEnitSubrecord::CompareFields()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrEnitSubrecord Method - bool GetField (Buffer, FieldID);
 *
 *=========================================================================*/
inline bool CSrEnitSubrecord::GetField (CSString& Buffer, const int FieldID) {
  
  switch (FieldID) {
    case SR_FIELD_CHARGE:
        Buffer.Format("%u", GetCharge());
		return (true);
    case SR_FIELD_COST:
        Buffer.Format("%u", GetCost());
		return (true);
    case SR_FIELD_AUTOCALC:
        Buffer.Format("%s", BooleanToString(IsAutoCalc()));
		return (true);
    case SR_FIELD_RANGE:
        Buffer.Format("%d", GetType());
		return (true);
   }

  return CSrSubrecord::GetField(Buffer, FieldID);
 }
/*===========================================================================
 *		End of Class Method CSrEnitSubrecord::GetField()
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srenitsubrecord.H
 *=========================================================================*/
