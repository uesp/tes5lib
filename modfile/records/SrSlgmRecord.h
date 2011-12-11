/*===========================================================================
 *
 * File:		SrSlgmrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrSlgmRecord class.
 *
 *=========================================================================*/
#ifndef __SRSLGMRECORD_H
#define __SRSLGMRECORD_H


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
 * Begin Class CSrSlgmRecord Definition
 *
 *=========================================================================*/
class CSrSlgmRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrSlgmRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pKsizData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pSoulData;
	CSrSubrecord*		m_pModtData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pKwdaData;
	CSrSubrecord*		m_pSlcpData;
	CSrSubrecord*		m_pNam0Data;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSlgmRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrSlgmRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrSlgmRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrSlgmRecord.H
 *=========================================================================*/
