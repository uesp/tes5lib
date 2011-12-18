/*===========================================================================
 *
 * File:		SrSndrrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrSndrRecord class.
 *
 *=========================================================================*/
#ifndef __SRSNDRRECORD_H
#define __SRSNDRRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "sridrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrSndrRecord Definition
 *
 *=========================================================================*/
class CSrSndrRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrSndrRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pFnamData;
	CSrSubrecord*		m_pSnamData;
	CSrSubrecord*		m_pCnamData;
	CSrSubrecord*		m_pOnamData;
	CSrSubrecord*		m_pGnamData;
	CSrSubrecord*		m_pCtdaData;
	CSrSubrecord*		m_pAnamData;
	CSrSubrecord*		m_pLnamData;
	CSrSubrecord*		m_pBnamData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrSndrRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrSndrRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrSndrRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrSndrRecord.H
 *=========================================================================*/
