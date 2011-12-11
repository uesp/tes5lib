/*===========================================================================
 *
 * File:		SrActirecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrActiRecord class.
 *
 *=========================================================================*/
#ifndef __SRACTIRECORD_H
#define __SRACTIRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sritem1record.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrActiRecord Definition
 *
 *=========================================================================*/
class CSrActiRecord : public CSrItem1Record 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrActiRecord, CSrItem1Record)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pDmdsData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pPnamData;
	CSrSubrecord*		m_pKnamData;
	CSrSubrecord*		m_pDestData;
	CSrSubrecord*		m_pVmadData;
	CSrSubrecord*		m_pModtData;
	CSrSubrecord*		m_pModsData;
	CSrSubrecord*		m_pDstdData;
	CSrSubrecord*		m_pDmdlData;
	CSrSubrecord*		m_pDmdtData;
	CSrSubrecord*		m_pDstfData;
	CSrSubrecord*		m_pRnamData;
	CSrSubrecord*		m_pVnamData;
	CSrSubrecord*		m_pWnamData;
	CSrSubrecord*		m_pSnamData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrActiRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrActiRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrActiRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrActiRecord.H
 *=========================================================================*/
