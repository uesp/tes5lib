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
  srlighdata_t& GetLightData (void) { return m_pLightData ? m_pLightData->GetLightData() : s_NullLightData; }
  
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

	DECLARE_SRFIELD_INT1(CSrLighRecord, Time, GetLightData().Time, GetLightData().Time)
	DECLARE_SRFIELD_DWORD1(CSrLighRecord, Radius, GetLightData().Radius, GetLightData().Radius)
	DECLARE_SRFIELD_DWORDFLAG1(CSrLighRecord, Color, GetLightData().Color, GetLightData().Color)
	DECLARE_SRFIELD_DWORD1(CSrLighRecord, Value, GetLightData().Value, GetLightData().Value)
	DECLARE_SRFIELD_DWORD1(CSrLighRecord, Unknown1, GetLightData().Unknown1, GetLightData().Unknown1)
	DECLARE_SRFIELD_DWORD1(CSrLighRecord, Unknown2, GetLightData().Unknown2, GetLightData().Unknown2)

	DECLARE_SRFIELD_FLOAT1(CSrLighRecord, FallOff, GetLightData().FallOff, GetLightData().FallOff)
	DECLARE_SRFIELD_FLOAT1(CSrLighRecord, FOV, GetLightData().FOV, GetLightData().FOV)
	
	DECLARE_SRFIELD_FLOAT1(CSrLighRecord, Unknown3, GetLightData().Unknown3, GetLightData().Unknown3)
	DECLARE_SRFIELD_FLOAT1(CSrLighRecord, Unknown4, GetLightData().Unknown4, GetLightData().Unknown4)
	DECLARE_SRFIELD_FLOAT1(CSrLighRecord, Unknown5, GetLightData().Unknown5, GetLightData().Unknown5)
	
	DECLARE_SRFIELD_FLOAT1(CSrLighRecord, Weight, GetLightData().Weight, GetLightData().Weight)
};
/*===========================================================================
 *		End of Class CSrLighRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrLighRecord.H
 *=========================================================================*/
