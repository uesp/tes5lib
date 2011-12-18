/*===========================================================================
 *
 * File:		SrLvliRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srLvlirecord.h"


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrLvliRecord, CSrIdRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_OBND, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLD, CSrByteSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLF, CSrByteSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LLCT, CSrByteSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLO, CSrLvloSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LVLG, CSrFormidSubrecord::Create)
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrLvliRecord, CSrIdRecord)
	ADD_SRFIELDALL("ChanceNone",		SR_FIELD_CHANCENONE,		0, CSrLvliRecord, FieldChanceNone)
	ADD_SRFIELDALL("CalculateEach",		SR_FIELD_CALCULATEEACH,		0, CSrLvliRecord, FieldCalculateEach)
	ADD_SRFIELDALL("CalculateAll",		SR_FIELD_CALCULATEALL,		0, CSrLvliRecord, FieldCalculateAll)
	ADD_SRFIELDALL("UseAll",			SR_FIELD_USEALL,			0, CSrLvliRecord, FieldUseAll)
	ADD_SRFIELDALL("ItemCount",			SR_FIELD_ITEMCOUNT,			0, CSrLvliRecord, FieldItemCount)
	ADD_SRFIELDALL("Global",			SR_FIELD_GLOBAL,			0, CSrLvliRecord, FieldGlobal)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Constructor
 *
 *=========================================================================*/
CSrLvliRecord::CSrLvliRecord () 
{
	m_pObndData = NULL;
	m_pChanceNone = NULL;
	m_pFlags = NULL;
	m_pItemCount = NULL;
	m_pGlobal = NULL;
}
/*===========================================================================
 *		End of Class CSrLvliRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrLvliRecord::Destroy (void) 
{
	m_pObndData = NULL;
	m_pChanceNone = NULL;
	m_pFlags = NULL;
	m_pItemCount = NULL;
	m_pGlobal = NULL;

	CSrIdRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrLvliRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrLvliRecord::InitializeNew (void) 
{
	CSrIdRecord::InitializeNew();

	AddNewSubrecord(SR_NAME_LVLD);
	if (m_pChanceNone != NULL) m_pChanceNone->InitializeNew();

	AddNewSubrecord(SR_NAME_LVLF);
	if (m_pFlags != NULL) m_pFlags->InitializeNew();

	AddNewSubrecord(SR_NAME_LLCT);
	if (m_pItemCount != NULL) m_pItemCount->InitializeNew();
}
/*===========================================================================
 *		End of Class Method CSrLvliRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLvliRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_OBND)
	{
		m_pObndData = SrCastClass(CSrDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLD)
	{
		m_pChanceNone = SrCastClass(CSrByteSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLF)
	{
		m_pFlags = SrCastClass(CSrByteSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LLCT)
	{
		m_pItemCount = SrCastClass(CSrByteSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_LVLG)
	{
		m_pGlobal = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else
	{
		CSrIdRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrLvliRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrLvliRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrLvliRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pObndData == pSubrecord)
		m_pObndData = NULL;
	else if (m_pChanceNone == pSubrecord)
		m_pChanceNone = NULL;
	else if (m_pFlags == pSubrecord)
		m_pFlags = NULL;
	else if (m_pItemCount == pSubrecord)
		m_pItemCount = NULL;
	else if (m_pGlobal == pSubrecord)
		m_pGlobal = NULL;
	else
		CSrIdRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrLvliRecord::OnDeleteSubrecord()
 *=========================================================================*/


void CSrLvliRecord::SetChanceNone (const byte Value)
{
	if (m_pChanceNone == NULL)
	{
		AddNewSubrecord(SR_NAME_LVLD);
		if (m_pChanceNone == NULL) return;
		m_pChanceNone->InitializeNew();
	}

	m_pChanceNone->SetValue(Value);
}


void CSrLvliRecord::SetCalculateEach (const bool Flag)
{
	if (m_pFlags == NULL)
	{
		AddNewSubrecord(SR_NAME_LVLF);
		if (m_pFlags == NULL) return;
		m_pFlags->InitializeNew();
	}

	m_pFlags->FlipFlag(SR_LVLIFLAG_CALCULATEEACH, Flag);
}


void CSrLvliRecord::SetCalculateAll (const bool Flag)
{
	if (m_pFlags == NULL)
	{
		AddNewSubrecord(SR_NAME_LVLF);
		if (m_pFlags == NULL) return;
		m_pFlags->InitializeNew();
	}

	m_pFlags->FlipFlag(SR_LVLIFLAG_CALCULATEALL, Flag);
}


void CSrLvliRecord::SetUseAll (const bool Flag)
{
	if (m_pFlags == NULL)
	{
		AddNewSubrecord(SR_NAME_LVLF);
		if (m_pFlags == NULL) return;
		m_pFlags->InitializeNew();
	}

	m_pFlags->FlipFlag(SR_LVLIFLAG_USEALL, Flag);
}


void CSrLvliRecord::UpdateItemCount (void)
{

	if (m_pItemCount == NULL)
	{
		AddNewSubrecord(SR_NAME_LLCT);
		if (m_pItemCount == NULL) return;
		m_pItemCount->InitializeNew();
	}

	dword Count = CountSubrecords(SR_NAME_LVLO);

	if (Count > SR_LVLI_MAXITEMCOUNT)
	{
		SystemLog.Printf("WARNING: LVLI record exceeded maximum of %d LVLO subrecords!", SR_LVLI_MAXITEMCOUNT);
		int Counter = 0;
		
		for (dword i = 0; i < m_Subrecords.GetSize(); ++i)
		{
			if (m_Subrecords[i]->GetRecordType() != SR_NAME_LVLO) continue;
			++Counter;

			if (Counter > SR_LVLI_MAXITEMCOUNT) 
			{
				m_Subrecords.Delete(i);
				--i;
			}
		}

		m_pItemCount->SetValue(SR_LVLI_MAXITEMCOUNT);
	}

	m_pItemCount->SetValue((byte) Count);
}


/*===========================================================================
 *
 * Begin CSrLvliRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvliRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvliRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvliRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrLvliRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrLvliRecord Set Field Methods
 *=========================================================================*/
