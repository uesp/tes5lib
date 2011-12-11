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
  #include "srrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrPerkRecord Definition
 *
 *=========================================================================*/
class CSrPerkRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrPerkRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pEpftData;
	CSrSubrecord*		m_pPrkcData;
	CSrSubrecord*		m_pDescData;
	CSrSubrecord*		m_pEpf2Data;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pPrkeData;
	CSrSubrecord*		m_pPrkfData;
	CSrSubrecord*		m_pEpfdData;
	CSrSubrecord*		m_pCis2Data;
	CSrSubrecord*		m_pNnamData;
	CSrSubrecord*		m_pVmadData;
	CSrSubrecord*		m_pEpf3Data;



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
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrPerkRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrPerkRecord.H
 *=========================================================================*/
