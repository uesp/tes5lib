/*===========================================================================
 *
 * File:		SrLvlnrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrLvlnRecord class.
 *
 *=========================================================================*/
#ifndef __SRLVLNRECORD_H
#define __SRLVLNRECORD_H


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
 * Begin Class CSrLvlnRecord Definition
 *
 *=========================================================================*/
class CSrLvlnRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrLvlnRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrSubrecord*		m_pCoedData;
	CSrSubrecord*		m_pModlData;
	CSrSubrecord*		m_pObndData;
	CSrSubrecord*		m_pModtData;
	CSrSubrecord*		m_pLvldData;
	CSrSubrecord*		m_pLvlfData;
	CSrSubrecord*		m_pLlctData;
	CSrSubrecord*		m_pLvloData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

	/* Class Constructors/Destructors */
  CSrLvlnRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrLvlnRecord; }

	/* Get class members */
  

	/* Initialize a new record */
  void InitializeNew (void);

	/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


  /* Begin field method definitions */


};
/*===========================================================================
 *		End of Class CSrLvlnRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrLvlnRecord.H
 *=========================================================================*/
