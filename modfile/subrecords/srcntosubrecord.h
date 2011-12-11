/*===========================================================================
 *
 * File:		SrCNtoSubrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Defines the CSrCntoSubrecord used for storing a 32-bit dword.
 *
 *=========================================================================*/
#ifndef __SRCNTOSUBRECORD_H
#define __SRCNTOSUBRECORD_H


/*===========================================================================
 *
 * Begin Reqiured Includes
 *
 *=========================================================================*/
  #include "srsubrecord.h"
/*===========================================================================
 *		End of Reqiured Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrCntoSubrecord Definition
 *
 *=========================================================================*/
class CSrCntoSubrecord : public CSrSubrecord 
{
  DECLARE_SRCLASS(CSrCntoSubrecord, CSrSubrecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  srformid_t	m_FormID;
  dword			m_Count;


  /*---------- Begin Protected Class Methods --------------------*/
protected:

	/* Input/output the subrecord data */
  virtual bool ReadData  (CSrFile& File) { bool Result; Result = File.ReadDWord(m_FormID);  Result &= File.ReadDWord(m_Count); return Result; }
  virtual bool WriteData (CSrFile& File) { bool Result; Result = File.WriteDWord(m_FormID); Result &= File.WriteDWord(m_Count); return Result; }


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrCntoSubrecord() : m_FormID(0), m_Count(0) { }
  virtual void Destroy (void) { m_FormID = m_Count = 0; CSrSubrecord::Destroy(); }

  dword ChangeFormID (const srformid_t NewID, const srformid_t OldID);
  bool FixupFormID (CSrFormidFixupArray& FixupArray);
  bool CompareFields (int& Result, const int FieldID, CSrSubrecord* pSubrecord);
  bool GetField (CSString& Buffer, const int FieldID);

	/* Copy the content from an existing subrecord */
  virtual bool Copy (CSrSubrecord* pSubrecord) {
	CSrCntoSubrecord* pSubrecord1 = SrCastClassNull(CSrCntoSubrecord, pSubrecord);
	m_RecordSize = 8;

	if (pSubrecord1 != NULL) {
	  m_FormID = pSubrecord1->m_FormID;
	  m_Count  = pSubrecord1->m_Count;
	}
	else
	{
		m_FormID = 0;
		m_Count  = 0;
	}
	
	return (true);
  }

	/* Create a class instance */
  static CSrSubrecord* Create (void) { return (new CSrCntoSubrecord); }

	/* Initialize a new record */
  virtual void InitializeNew (void) { CSrSubrecord::InitializeNew();  m_FormID = m_Count = 0; m_RecordSize = 8; }
  	  
	/* Get class members */
  srformid_t	GetFormID   (void) { return (m_FormID); }
  dword			GetCount    (void) { return (m_Count); }
  virtual byte*	GetData     (void) { return (byte *)(&m_FormID); }

  	/* Set class methods */
  void SetItemFormID (const srformid_t Value) { m_FormID = Value; }
  void SetItemCount  (const dword      Value) { m_Count = Value; }
 
};
/*===========================================================================
 *		End of Class CSrCntoSubrecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srwordsubrec.H
 *=========================================================================*/
