/*===========================================================================
 *
 * File:		Sridrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Defines the CSrIdRecord which is used to derive any record class that
 * have an editor ID (EDID).
 *
 *=========================================================================*/
#ifndef __SRIDRECORD_H
#define __SRIDRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srrecord.h"
  #include "../subrecords/srformidarraysubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/
/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrIdRecord Definition
 *
 * Description
 *
 *=========================================================================*/
class CSrIdRecord : public CSrRecord {
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrIdRecord, CSrRecord)


  /*---------- Begin Protected Class Members --------------------*/
protected:
  CSrStringSubrecord*		m_pEditorID;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrIdRecord();
  virtual void Destroy (void);

	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return (new CSrIdRecord); }

	/* Get the current editor ID */
  const SSCHAR* GetEditorID (void) const            { return (m_pEditorID ? (const SSCHAR *)m_pEditorID->GetString().c_str() : ""); }
  bool          IsEditorID  (const SSCHAR* pString) { return SafeStringCompare(GetEditorID(), pString, true) == 0; }
  bool          HasEditorID (void) const            { return (m_pEditorID != NULL && m_pEditorID->GetString()[0] != NULL_CHAR); }
  		
	/* Initialize a new record */
  virtual void InitializeNew (void);

	/* Called when a subrecord is added to the record */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);
  
	/* Set the editor ID */
  void SetEditorID (const SSCHAR *pData);

	/* Begin field method definitions */
  DECLARE_SRFIELD(FieldEditorID)

};
/*===========================================================================
 *		End of Class CSrIdRecord Definition
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

	/* Array of record pointers  */
  typedef CSrPtrArray<CSrIdRecord>    CSrIdRecordArray;
  typedef CSrRefPtrArray<CSrIdRecord> CSrRefIdRecordArray;

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/



#endif
/*===========================================================================
 *		End of File Sridrecord.H
 *=========================================================================*/
