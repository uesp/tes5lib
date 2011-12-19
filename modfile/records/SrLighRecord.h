/*===========================================================================
 *
 * File:		SrLighrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrLighRecord class.
 *
 *=========================================================================*/
#ifndef __SRLIGHRECORD_H
#define __SRLIGHRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srlighdatasubrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrLighRecord Definition
 *
 *=========================================================================*/
class CSrLighRecord : public CSrIdRecord 
{
  DECLARE_SRSUBRECCREATE()
  DECLARE_SRFIELDMAP()
  DECLARE_SRCLASS(CSrLighRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrStringSubrecord*		m_pModel;
	CSrFloatSubrecord*		m_pFnamData;
	CSrSubrecord*			m_pObndData;
	CSrLighDataSubrecord*	m_pLightData;
	CSrSubrecord*			m_pModtData;
	CSrFormidSubrecord*		m_pSnamData;
	CSrLStringSubrecord*	m_pItemName;

	static srlighdata_t s_NullLightData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
  CSrLighRecord();
  virtual void Destroy (void);

    	/* Return a new instance of the class */
  static CSrRecord* Create (void) { return new CSrLighRecord; }

		/* Get class members */
  

		/* Initialize a new record */
  void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
  virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
  virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);


		/* Begin field method definitions */
	DECLARE_SRFIELD_ITEMNAME(CSrLighRecord)
	DECLARE_SRFIELD_MODEL(CSrLighRecord, SR_NAME_MODL)

	DECLARE_SRFIELD_EDITORID(CSrLighRecord, HoldSound, GetHoldSound, SetHoldSound)
	DECLARE_SRMETHOD_FORMID(HoldSound, m_pSnamData, SR_NAME_SNAM)

	DECLARE_SRFIELD_METHODFLOAT(CSrLighRecord, m_pFnamData, FNam, SR_NAME_FNAM)
	//DECLARE_SRFIELD_EDITORID(CSrLighRecord, FNam, GetFNam, SetFNam)
	//DECLARE_SRMETHOD_FORMID(FNam, m_pFnamData, SR_NAME_FNAM)

};
/*===========================================================================
 *		End of Class CSrLighRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrLighRecord.H
 *=========================================================================*/
