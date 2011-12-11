/*===========================================================================
 *
 * File:		SrArmorecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrArmoRecord class.
 *
 *=========================================================================*/
#ifndef __SRARMORECORD_H
#define __SRARMORECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridkeyrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrArmoRecord Definition
 *
 *=========================================================================*/
class CSrArmoRecord : public CSrIdKeyRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrArmoRecord, CSrIdKeyRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*		m_pMod4Data;
	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pTnamData;
	CSrSubrecord*		m_pMo4tData;
	CSrSubrecord*		m_pBidsData;
	CSrSubrecord*		m_pMod2Data;
	CSrSubrecord*		m_pMo2tData;
	CSrSubrecord*		m_pYnamData;
	CSrSubrecord*		m_pBodtData;
	CSrSubrecord*		m_pZnamData;
	CSrSubrecord*		m_pRnamData;
	CSrSubrecord*		m_pDescData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pDnamData;
	CSrSubrecord*		m_pEitmData;
	CSrSubrecord*		m_pEtypData;
	CSrSubrecord*		m_pBamtData;
	CSrSubrecord*		m_pMo2sData;
	CSrSubrecord*		m_pMo4sData;
	CSrSubrecord*		m_pVmadData;
	CSrLStringSubrecord*	m_pItemName;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrArmoRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrArmoRecord; }

	/* Get class members */
  const SSCHAR* GetItemName (void) { return (m_pItemName ? m_pItemName->GetString().c_str() : ""); }
  virtual bool HasFullItemName (void) { return (true); }
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

  void SetItemName (const SSCHAR* pString);


	/* Begin field method definitions */
  DECLARE_SRFIELD(FieldItemName)


};
/*===========================================================================
 *		End of Class CSrArmoRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrArmoRecord.H
 *=========================================================================*/
