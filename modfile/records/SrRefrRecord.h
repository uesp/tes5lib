/*===========================================================================
 *
 * File:		SrRefrrecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrRefrRecord class.
 *
 *=========================================================================*/
#ifndef __SRREFRRECORD_H
#define __SRREFRRECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridrecord.h"
	#include "../subrecords/srrefrdatasubrecord.h"
    #include "../subrecords/srbytesubrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrRefrRecord Definition
 *
 *=========================================================================*/
class CSrRefrRecord : public CSrIdRecord 
{
	DECLARE_SRSUBRECCREATE()
	DECLARE_SRFIELDMAP()
	DECLARE_SRCLASS(CSrRefrRecord, CSrIdRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
  	CSrByteSubrecord*		m_pMarkerFlags;
	CSrSubrecord*		m_pXsclData;
	CSrSubrecord*		m_pXczaData;
	CSrSubrecord*		m_pXrgdData;
	CSrFormidSubrecord*	m_pBaseObject;
	CSrSubrecord*		m_pXtelData;
	CSrSubrecord*		m_pXrmrData;
	CSrRefrDataSubrecord*		m_pReferenceData;
	CSrSubrecord*		m_pVmadData;
	CSrSubrecord*		m_pXlrmData;
	CSrSubrecord*		m_pXprmData;
	CSrSubrecord*		m_pXndpData;
	CSrSubrecord*		m_pXcvlData;
	CSrSubrecord*		m_pXmboData;
	CSrSubrecord*		m_pXhtwData;
	CSrSubrecord*		m_pXltwData;
	CSrSubrecord*		m_pXprdData;
	CSrFormidSubrecord*		m_pLocationRefType;
	CSrSubrecord*		m_pXlibData;
	CSrSubrecord*		m_pXppaData;
	CSrSubrecord*		m_pInamData;
	CSrSubrecord*		m_pXaprData;
	CSrSubrecord*		m_pXactData;
	CSrSubrecord*		m_pPdtoData;
	CSrSubrecord*		m_pXspcData;
	CSrSubrecord*		m_pXlocData;
	CSrSubrecord*		m_pXemiData;
	CSrSubrecord*		m_pXespData;
	CSrSubrecord*		m_pXfvcData;
	CSrSubrecord*		m_pXapdData;
	CSrSubrecord*		m_pXpodData;
	CSrSubrecord*		m_pXlkrData;
	CSrSubrecord*		m_pXrdsData;
	CSrSubrecord*		m_pXligData;
	CSrSubrecord*		m_pXalpData;
	CSrSubrecord*		m_pXownData;
	CSrSubrecord*		m_pXeznData;
	CSrSubrecord*		m_pXmbrData;
	CSrSubrecord*		m_pXtriData;
	CSrSubrecord*		m_pOnamData;
	CSrSubrecord*		m_pXtnmData;
	CSrSubrecord*		m_pXrnkData;
	CSrSubrecord*		m_pXlcmData;
	CSrSubrecord*		m_pXczcData;
	CSrSubrecord*		m_pSctxData;
	CSrSubrecord*		m_pLnamData;
	CSrSubrecord*		m_pXcntData;
	CSrSubrecord*		m_pXwcuData;
	CSrSubrecord*		m_pXpwrData;
	CSrSubrecord*		m_pXis2Data;
	CSrSubrecord*		m_pXocpData;
	CSrSubrecord*		m_pXmbpData;
	CSrSubrecord*		m_pXrgbData;
	CSrSubrecord*		m_pXlcnData;
	CSrLStringSubrecord*		m_pItemName;
	CSrSubrecord*		m_pXwcnData;
	CSrSubrecord*		m_pSchrData;
	CSrSubrecord*		m_pMarker;
	CSrWordSubrecord*		m_pMarkerType;


	static srrefrdata_t s_NullRefrData;



  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrRefrRecord();
	virtual void Destroy (void);

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrRefrRecord; }

		/* Get class members */
	srrefrdata_t& GetRefrData (void) { return m_pReferenceData ? m_pReferenceData->GetRefrData() : s_NullRefrData; }
	const char* GetMarkerType (void) { return GetSrMapMarkerTypeString(GetMarkerTypeID()); }

	bool IsMapMarker (void) { return m_pMarker != NULL; }

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

		/* Set class members */
	void SetMarkerType (const char* pString) { int Value = 0; if (GetSrMapMarkerTypeValue(Value, pString)) SetMarkerTypeID(Value); }


		/* Begin field method definitions */
	DECLARE_SRFIELD_FLOAT1(CSrRefrRecord, LocationX, GetRefrData().X, GetRefrData().X)
	DECLARE_SRFIELD_FLOAT1(CSrRefrRecord, LocationY, GetRefrData().Y, GetRefrData().Y)
	DECLARE_SRFIELD_FLOAT1(CSrRefrRecord, LocationZ, GetRefrData().Z, GetRefrData().Z)
	DECLARE_SRFIELD_FLOAT1(CSrRefrRecord, AngleX, GetRefrData().rX, GetRefrData().rX)
	DECLARE_SRFIELD_FLOAT1(CSrRefrRecord, AngleY, GetRefrData().rY, GetRefrData().rY)
	DECLARE_SRFIELD_FLOAT1(CSrRefrRecord, AngleZ, GetRefrData().rZ, GetRefrData().rZ)

	DECLARE_SRFIELD_ITEMNAME(CSrRefrRecord)

	DECLARE_SRFIELD_METHOD(CSrRefrRecord, MarkerType, GetMarkerType, SetMarkerType)
	DECLARE_SRFIELD_METHODDWORD(CSrRefrRecord, m_pMarkerType, MarkerTypeID, SR_NAME_TNAM)
	DECLARE_SRFIELD_METHODDBYTE(CSrRefrRecord, m_pMarkerFlags, MarkerFlags, SR_NAME_FNAM)

};
/*===========================================================================
 *		End of Class CSrRefrRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrRefrRecord.H
 *=========================================================================*/
