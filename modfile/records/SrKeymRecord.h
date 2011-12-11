/*===========================================================================
 *
 * File:		SrKeymrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrKeymRecord class.
 *
 *=========================================================================*/
#ifndef __SRKEYMRECORD_H
#define __SRKEYMRECORD_H


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
 * Begin Class CSrKeymRecord Definition
 *
 *=========================================================================*/
class CSrKeymRecord : public CSrRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrKeymRecord, CSrRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pEdidData;
	CSrSubrecord*		m_pKsizData;
	CSrSubrecord*		m_pFullData;
	CSrSubrecord*		m_pModtData;
	CSrSubrecord*		m_pKwdaData;
	CSrSubrecord*		m_pYnamData;
	CSrSubrecord*		m_pZnamData;
	CSrSubrecord*		m_pDataData;
	CSrSubrecord*		m_pVmadData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrKeymRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrKeymRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrKeymRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrKeymRecord.H
 *=========================================================================*/
