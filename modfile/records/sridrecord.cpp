/*===========================================================================
 *
 * File:		Sridrecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "sridrecord.h"
#include "../srrecordhandler.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrIdRecord, CSrRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_EDID, CSrStringSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrIdRecord, CSrRecord)
	ADD_SRFIELDALL("EditorID",		SR_FIELD_EDITORID,		SRRF_ALNUM,				 CSrIdRecord, FieldEditorID)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CSrIdRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdRecord Constructor
 *
 *=========================================================================*/
CSrIdRecord::CSrIdRecord () :
	m_pEditorID(NULL)
{
}
/*===========================================================================
 *		End of Class CSrIdRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrIdRecord::Destroy (void) 
{
  m_pEditorID = NULL;
  
  CSrRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrIdRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrIdRecord::InitializeNew (void) 
{
  CSrRecord::InitializeNew();

  AddNewSubrecord(SR_NAME_EDID);
  if (m_pEditorID != NULL) m_pEditorID->InitializeNew(); 
}
/*===========================================================================
 *		End of Class Method CSrIdRecord::InitializeNew()
 *=========================================================================*/

  
/*===========================================================================
 *
 * Class CSrIdRecord Event - void OnAddSubrecord (pSubRecord);
 *
 *=========================================================================*/
void CSrIdRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

  if (pSubrecord->GetRecordType() == SR_NAME_EDID)
  {
    m_pEditorID = SrCastClass(CSrStringSubrecord, pSubrecord);
  }
  else
  {
    CSrRecord::OnAddSubrecord(pSubrecord);
  }
  
 }
/*===========================================================================
 *		End of Class Event CSrIdRecord::OnAddSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrIdRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

  if (m_pEditorID == pSubrecord)
    m_pEditorID = NULL;
  else
    CSrRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrIdRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrIdRecord Method - void SetEditorID (pString);
 *
 *=========================================================================*/
void CSrIdRecord::SetEditorID (const SSCHAR* pString) 
{

	/* Ensure the subrecord exists */
  if (m_pEditorID == NULL) 
  {
    AddNewSubrecord(SR_NAME_EDID);
    if (m_pEditorID == NULL) return;
  }

  m_pEditorID->SetString(pString);
}
/*===========================================================================
 *		End of Class Method CSrIdRecord::SetEditorID()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Get Field Methods
 *
 *=========================================================================*/
BEGIN_SRGETFIELD(CSrIdRecord::GetFieldEditorID)
	const SSCHAR* pString = GetEditorID();
	if (pString != NULL) String.Format("%s", pString);
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrEnchRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Compare Field Methods
 *
 *=========================================================================*/
DEFINE_SRCOMPFIELDSTRING(CSrIdRecord, CompareFieldEditorID, GetEditorID)
/*===========================================================================
 *		End of CSrIdRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Set Field Methods
 *
 *=========================================================================*/
BEGIN_SRSETFIELD(CSrIdRecord::SetFieldEditorID)
  AddSrGeneralError("Cannot set the editorID of a record from its SetField method!");
  return (false);
END_SRSETFIELD()
/*===========================================================================
 *		End of CSrIdRecord Set Field Methods
 *=========================================================================*/
