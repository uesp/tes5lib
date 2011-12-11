/*===========================================================================
 *
 * File:		SrScrlrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrScrlRecord class.
 *
 *=========================================================================*/
#ifndef __SRSCRLRECORD_H
#define __SRSCRLRECORD_H


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
 * Begin Class CSrScrlRecord Definition
 *
 *=========================================================================*/
class CSrScrlRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrScrlRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pEtypData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pEfidData;
	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pDescData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pMdobData;
	CSrSubrecord*		m_pModtData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pSpitData;
	CSrSubrecord*		m_pEfitData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pKsizData;
	CSrSubrecord*		m_pKwdaData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrScrlRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrScrlRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrScrlRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrScrlRecord.H
 *=========================================================================*/
