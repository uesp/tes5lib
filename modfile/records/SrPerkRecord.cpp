/*===========================================================================
 *
 * File:		SrPerkRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srPerkrecord.h"


srperkdata_t CSrPerkRecord::s_NullPerkData;


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrPerkRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VMAD, CSrDataSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrPerkDataSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_CTDA, CSrCtdaSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS1, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_CIS2, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PRKC, CSrByteSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PRKE, CSrPrkeSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PRKF, CSrDataSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_EPFT, CSrByteSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPFD, CSrEpfdSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPF2, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_EPF3, CSrDwordSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrPerkRecord, CSrIdRecord)
	ADD_SRFIELDALL("ItemName",		SR_FIELD_ITEMNAME,		0, CSrPerkRecord, FieldItemName)
	ADD_SRFIELDALL("Description",	SR_FIELD_DESCRIPTION,	0, CSrPerkRecord, FieldDescription)
	ADD_SRFIELDALL("NextPerk",		SR_FIELD_NEXTPERK,		0, CSrPerkRecord, FieldNextPerk)
	ADD_SRFIELDALL("Unknown1",		SR_FIELD_UNKNOWN1,		0, CSrPerkRecord, FieldUnknown1)
	ADD_SRFIELDALL("Unknown2",		SR_FIELD_UNKNOWN2,		0, CSrPerkRecord, FieldUnknown2)
	ADD_SRFIELDALL("Unknown3",		SR_FIELD_UNKNOWN3,		0, CSrPerkRecord, FieldUnknown3)
	ADD_SRFIELDALL("PerkSections",	SR_FIELD_PERKSECTIONS,	0, CSrPerkRecord, FieldPerkSections)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Constructor
 *
 *=========================================================================*/
CSrPerkRecord::CSrPerkRecord () 
{
	m_pCurrentSection = NULL;
	m_pCurrentSubSection = NULL;
	m_pItemName = NULL;
	m_pDescription = NULL;
	m_pPerkData = NULL;
	m_pNextPerk = NULL;
	m_pLastEPFT = NULL;
}
/*===========================================================================
 *		End of Class CSrPerkRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrPerkRecord::Destroy (void) 
{
	m_pLastEPFT = NULL;
	m_pCurrentSection = NULL;
	m_pCurrentSubSection = NULL;
	m_pItemName = NULL;
	m_pDescription = NULL;
	m_pPerkData = NULL;
	m_pNextPerk = NULL;

	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrPerkRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrPerkRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();
	m_pCurrentSection = NULL;

	AddNewSubrecord(SR_NAME_FULL);
	if (m_pItemName != NULL) m_pItemName->InitializeNew();

	AddNewSubrecord(SR_NAME_DESC);
	if (m_pDescription != NULL) m_pDescription->InitializeNew();

	AddNewSubrecord(SR_NAME_DATA);
	if (m_pPerkData != NULL) m_pPerkData->InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrPerkRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrPerkRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescription = SrCastClass(CSrLStringSubrecord, pSubrecord);
		m_pCurrentSection = NULL;
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pItemName = SrCastClass(CSrLStringSubrecord, pSubrecord);
		m_pCurrentSection = NULL;
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		if (pSubrecord->GetRecordSize() == SR_PERKDATA_SUBRECORD_SIZE) 
		{
			m_pCurrentSection = NULL;
			m_pPerkData = SrCastClass(CSrPerkDataSubrecord, pSubrecord);
		}
		else if (m_pCurrentSection)
		{
			m_Subrecords.Remove(pSubrecord);
			m_pCurrentSection->Add(pSubrecord);
		}
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_NNAM)
	{
		m_pNextPerk = SrCastClass(CSrFormidSubrecord, pSubrecord);
		m_pCurrentSection = NULL;
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PRKE)
	{
		m_pLastEPFT = NULL;
		/* 
			Disable for now until we figure out how to handle PERK sections/sub-sections

		m_pCurrentSubSection = NULL;

		m_pCurrentSection = new CSrArraySubrecord;
		m_pCurrentSection->Initialize(SR_NAME_psec, 0);
		m_pCurrentSection->InitializeNew();

		m_Subrecords.Remove(pSubrecord);		
		m_pCurrentSection->Add(pSubrecord);

		m_Subrecords.Add(m_pCurrentSection); //*/
	} 
	else if (pSubrecord->GetRecordType() == SR_NAME_PRKC && m_pCurrentSection)
	{
		m_pCurrentSubSection = new CSrArraySubrecord;
		m_pCurrentSubSection->Initialize(SR_NAME_pssc, 0);
		m_pCurrentSubSection->InitializeNew();
		m_pCurrentSection->Add(m_pCurrentSubSection);

		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSubSection->Add(pSubrecord);		
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CTDA && m_pCurrentSubSection)
	{
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSubSection->Add(pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CIS1 && m_pCurrentSubSection)
	{
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSubSection->Add(pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_CIS1 && m_pCurrentSubSection)
	{
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSubSection->Add(pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPFT && m_pCurrentSection)
	{
		m_pLastEPFT = SrCastClass(CSrByteSubrecord, pSubrecord);

		m_pCurrentSubSection = NULL;
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSection->Add(pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPFT)
	{
		m_pLastEPFT = SrCastClass(CSrByteSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPFD && m_pCurrentSection)
	{
		m_pCurrentSubSection = NULL;
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSection->Add(pSubrecord);

		CSrEpfdSubrecord* pEpfd = SrCastClass(CSrEpfdSubrecord, pSubrecord);
		if (m_pLastEPFT && pEpfd) pEpfd->SetDataType(m_pLastEPFT->GetValue());

		m_pLastEPFT = NULL;
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPFD)
	{
		CSrEpfdSubrecord* pEpfd = SrCastClass(CSrEpfdSubrecord, pSubrecord);
		if (m_pLastEPFT && pEpfd) pEpfd->SetDataType(m_pLastEPFT->GetValue());

		m_pLastEPFT = NULL;
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPF2 && m_pCurrentSection)
	{
		m_pCurrentSubSection = NULL;
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSection->Add(pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_EPF3 && m_pCurrentSection)
	{
		m_pCurrentSubSection = NULL;
		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSection->Add(pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_PRKF && m_pCurrentSection)
	{
		m_pCurrentSubSection = NULL;
		m_pLastEPFT = NULL;

		m_Subrecords.Remove(pSubrecord);
		m_pCurrentSection->Add(pSubrecord);
		m_pCurrentSection = NULL;
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrPerkRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrPerkRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrPerkRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pDescription == pSubrecord)
		m_pDescription = NULL;
	else if (m_pItemName == pSubrecord)
		m_pItemName = NULL;
	else if (m_pPerkData == pSubrecord)
		m_pPerkData = NULL;
	else if (m_pNextPerk == pSubrecord)
		m_pNextPerk = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrPerkRecord::OnDeleteSubrecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrPerkRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrPerkRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrPerkRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrPerkRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrPerkRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrPerkRecord Set Field Methods
 *=========================================================================*/
