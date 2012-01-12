/*===========================================================================
 *
 * File:		SrRaceRecord.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srRacerecord.h"


srracedata_t CSrRaceRecord::s_NullRaceData;
srbodtdata_t CSrRaceRecord::s_NullBodtData;


/*===========================================================================
 *
 * Begin Subrecord Creation Array
 *
 *=========================================================================*/
BEGIN_SRSUBRECCREATE(CSrRaceRecord, CSrIdKeyRecord)
	DEFINE_SRSUBRECCREATE(SR_NAME_DESC, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FULL, CSrLStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPCT, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SPLO, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_WNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_BODT, CSrBodtSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DATA, CSrRaceDataSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_MNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FNAM, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ANAM, CSrStringSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_MODT, CSrDataSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_MTNM, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VTCK, CSrFormidArraySubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_HCLF, CSrFormidArraySubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DNAM, CSrFormidArraySubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINL, CSrWordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PNAM, CSrFloatSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_UNAM, CSrFloatSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_ATKD, CSrAtkdSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ATKE, CSrStringSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_NAM1, CSrDataSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_INDX, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MODL, CSrStringSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_GNAM, CSrFormidSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_NAM4, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM5, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM7, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_ONAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_LNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAME, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MTYP, CSrFormidSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_SPED, CSrSpedSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_VNAM, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_QNAM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_UNES, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PHTN, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_PHWT, CSrPhwtSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM0, CSrDataSubrecord::Create)	

	DEFINE_SRSUBRECCREATE(SR_NAME_HEAD, CSrDwordSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_MPAI, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_MPAV, CSrMpavSubrecord::Create)	

	DEFINE_SRSUBRECCREATE(SR_NAME_RPRM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RPRF, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_AHCM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_AHCF, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FTSM, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FTSF, CSrFormidSubrecord::Create)	
	DEFINE_SRSUBRECCREATE(SR_NAME_DFTF, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_DFTM, CSrFormidSubrecord::Create)

	DEFINE_SRSUBRECCREATE(SR_NAME_TINI, CSrWordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINT, CSrStringSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINP, CSrWordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TIND, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINC, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TINV, CSrDwordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_TIRS, CSrWordSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_NAM8, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNAM, CSrFormidSubrecord::Create)
	
	DEFINE_SRSUBRECCREATE(SR_NAME_WKMV, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_RNMV, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SWMV, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_FLMV, CSrFormidSubrecord::Create)
	DEFINE_SRSUBRECCREATE(SR_NAME_SNMV, CSrFormidSubrecord::Create)	
END_SRSUBRECCREATE()
/*===========================================================================
 *		End of Subrecord Creation Array
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrIdKeyRecord Field Map
 *
 *=========================================================================*/
BEGIN_SRFIELDMAP(CSrRaceRecord, CSrIdKeyRecord)
	ADD_SRFIELDALL("ItemName",		SR_FIELD_ITEMNAME,		0, CSrRaceRecord, FieldItemName)
	ADD_SRFIELDALL("Description",	SR_FIELD_DESCRIPTION,	0, CSrRaceRecord, FieldDescription)
	ADD_SRFIELDALL("SpellCount",	SR_FIELD_SPELLCOUNT,	0, CSrRaceRecord, FieldSpellCount)
	ADD_SRFIELDALL("NakedArmor",	SR_FIELD_NAKEDARMOR,	0, CSrRaceRecord, FieldNakedArmor)
	ADD_SRFIELDALL("BodyParts",		SR_FIELD_BODYPARTS,		0, CSrRaceRecord, FieldBodyParts)
	ADD_SRFIELDALL("MaleHeight",	SR_FIELD_MALEHEIGHT,	0, CSrRaceRecord, FieldMaleHeight)
	ADD_SRFIELDALL("FemaleHeight",	SR_FIELD_FEMALEHEIGHT,	0, CSrRaceRecord, FieldFemaleHeight)
	ADD_SRFIELDALL("ActorValue1",	SR_FIELD_ACTORVALUE1,	0, CSrRaceRecord, FieldActorValue1)
	ADD_SRFIELDALL("Skill1",		SR_FIELD_SKILL1,		0, CSrRaceRecord, FieldSkill1)
	ADD_SRFIELDALL("ActorValue2",	SR_FIELD_ACTORVALUE2,	0, CSrRaceRecord, FieldActorValue2)
	ADD_SRFIELDALL("Skill2",		SR_FIELD_SKILL2,		0, CSrRaceRecord, FieldSkill2)
	ADD_SRFIELDALL("ActorValue3",	SR_FIELD_ACTORVALUE3,	0, CSrRaceRecord, FieldActorValue3)
	ADD_SRFIELDALL("Skill3",		SR_FIELD_SKILL3,		0, CSrRaceRecord, FieldSkill3)
	ADD_SRFIELDALL("ActorValue4",	SR_FIELD_ACTORVALUE4,	0, CSrRaceRecord, FieldActorValue4)
	ADD_SRFIELDALL("Skill4",		SR_FIELD_SKILL4,		0, CSrRaceRecord, FieldSkill4)
	ADD_SRFIELDALL("ActorValue5",	SR_FIELD_ACTORVALUE5,	0, CSrRaceRecord, FieldActorValue5)
	ADD_SRFIELDALL("Skill5",		SR_FIELD_SKILL5,		0, CSrRaceRecord, FieldSkill5)
	ADD_SRFIELDALL("ActorValue6",	SR_FIELD_ACTORVALUE6,	0, CSrRaceRecord, FieldActorValue6)
	ADD_SRFIELDALL("Skill6",		SR_FIELD_SKILL6,		0, CSrRaceRecord, FieldSkill6)
	ADD_SRFIELDALL("ActorValue7",	SR_FIELD_ACTORVALUE7,	0, CSrRaceRecord, FieldActorValue7)
	ADD_SRFIELDALL("Skill7",		SR_FIELD_SKILL7,		0, CSrRaceRecord, FieldSkill7)
	ADD_SRFIELDALL("Unknown1",		SR_FIELD_UNKNOWN1,		0, CSrRaceRecord, FieldUnknown1)
	ADD_SRFIELDALL("Unknown2",		SR_FIELD_UNKNOWN2,		0, CSrRaceRecord, FieldUnknown2)
	ADD_SRFIELDALL("Unknown3",		SR_FIELD_UNKNOWN3,		0, CSrRaceRecord, FieldUnknown3)
	ADD_SRFIELDALL("Unknown4",		SR_FIELD_UNKNOWN4,		0, CSrRaceRecord, FieldUnknown4)
	ADD_SRFIELDALL("Unknown5",		SR_FIELD_UNKNOWN5,		0, CSrRaceRecord, FieldUnknown5)
	ADD_SRFIELDALL("Unknown6",		SR_FIELD_UNKNOWN6,		0, CSrRaceRecord, FieldUnknown6)
	ADD_SRFIELDALL("Unknown7",		SR_FIELD_UNKNOWN7,		0, CSrRaceRecord, FieldUnknown7)
	ADD_SRFIELDALL("Unknown8",		SR_FIELD_UNKNOWN8,		0, CSrRaceRecord, FieldUnknown8)
	ADD_SRFIELDALL("Unknown9",		SR_FIELD_UNKNOWN9,		0, CSrRaceRecord, FieldUnknown9)
	ADD_SRFIELDALL("Unknown10",		SR_FIELD_UNKNOWN10,		0, CSrRaceRecord, FieldUnknown10)
	ADD_SRFIELDALL("Unknown11",		SR_FIELD_UNKNOWN11,		0, CSrRaceRecord, FieldUnknown11)
	ADD_SRFIELDALL("Unknown12",		SR_FIELD_UNKNOWN12,		0, CSrRaceRecord, FieldUnknown12)
	ADD_SRFIELDALL("Unknown13",		SR_FIELD_UNKNOWN13,		0, CSrRaceRecord, FieldUnknown13)
	ADD_SRFIELDALL("Unknown14",		SR_FIELD_UNKNOWN14,		0, CSrRaceRecord, FieldUnknown14)
	ADD_SRFIELDALL("Unknown15",		SR_FIELD_UNKNOWN15,		0, CSrRaceRecord, FieldUnknown15)
	ADD_SRFIELDALL("Unknown16",		SR_FIELD_UNKNOWN16,		0, CSrRaceRecord, FieldUnknown16)
	ADD_SRFIELDALL("Unknown17",		SR_FIELD_UNKNOWN17,		0, CSrRaceRecord, FieldUnknown17)
	ADD_SRFIELDALL("Unknown18",		SR_FIELD_UNKNOWN18,		0, CSrRaceRecord, FieldUnknown18)
	ADD_SRFIELDALL("Unknown19",		SR_FIELD_UNKNOWN19,		0, CSrRaceRecord, FieldUnknown19)
	ADD_SRFIELDALL("Unknown20",		SR_FIELD_UNKNOWN20,		0, CSrRaceRecord, FieldUnknown20)
	ADD_SRFIELDALL("Unknown21",		SR_FIELD_UNKNOWN21,		0, CSrRaceRecord, FieldUnknown21)
	ADD_SRFIELDALL("Unknown22",		SR_FIELD_UNKNOWN22,		0, CSrRaceRecord, FieldUnknown22)
	ADD_SRFIELDALL("Unknown23",		SR_FIELD_UNKNOWN23,		0, CSrRaceRecord, FieldUnknown23)
	ADD_SRFIELDALL("Unknown24",		SR_FIELD_UNKNOWN24,		0, CSrRaceRecord, FieldUnknown24)
	ADD_SRFIELDALL("Unknown25",		SR_FIELD_UNKNOWN25,		0, CSrRaceRecord, FieldUnknown25)
	ADD_SRFIELDALL("Unknown26",		SR_FIELD_UNKNOWN26,		0, CSrRaceRecord, FieldUnknown26)
END_SRFIELDMAP()
/*===========================================================================
 *		End of CObRecord Field Map
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Constructor
 *
 *=========================================================================*/
CSrRaceRecord::CSrRaceRecord () 
{
	m_pDescription = NULL;
	m_pItemName = NULL;
	m_pSpellCount = NULL;
	m_pNakedArmor = NULL;
	m_pBodyData = NULL;
	m_pRaceData = NULL;
}
/*===========================================================================
 *		End of Class CSrRaceRecord Constructor
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Method - void Destroy (void);
 *
 *=========================================================================*/
void CSrRaceRecord::Destroy (void) 
{
	m_pDescription = NULL;
	m_pItemName = NULL;
	m_pSpellCount = NULL;
	m_pNakedArmor = NULL;
	m_pBodyData = NULL;
	m_pRaceData = NULL;

	CSrIdKeyRecord::Destroy();
}
/*===========================================================================
 *		End of Class Method CSrRaceRecord::Destroy()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Method - void InitializeNew (void);
 *
 *=========================================================================*/
void CSrRaceRecord::InitializeNew (void) 
{
	CSrIdKeyRecord::InitializeNew();

	AddInitNewSubrecord(SR_NAME_FULL);
	AddInitNewSubrecord(SR_NAME_DESC);
	AddInitNewSubrecord(SR_NAME_SPCT);
	AddInitNewSubrecord(SR_NAME_WNAM);
	AddInitNewSubrecord(SR_NAME_BODT);
	AddInitNewSubrecord(SR_NAME_DATA);

}
/*===========================================================================
 *		End of Class Method CSrRaceRecord::InitializeNew()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Event - void OnAddSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRaceRecord::OnAddSubrecord (CSrSubrecord* pSubrecord) {

	if (pSubrecord->GetRecordType() == SR_NAME_DESC)
	{
		m_pDescription = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_FULL)
	{
		m_pItemName = SrCastClass(CSrLStringSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_WNAM)
	{
		m_pNakedArmor = SrCastClass(CSrFormidSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_DATA)
	{
		m_pRaceData = SrCastClass(CSrRaceDataSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_BODT)
	{
		m_pBodyData = SrCastClass(CSrBodtSubrecord, pSubrecord);
	}
	else if (pSubrecord->GetRecordType() == SR_NAME_SPCT)
	{
		m_pSpellCount = SrCastClass(CSrDwordSubrecord, pSubrecord);
	}
	else
	{
		CSrIdKeyRecord::OnAddSubrecord(pSubrecord);
	}

}
/*===========================================================================
 *		End of Class Event CSrRaceRecord::OnAddSubRecord()
 *=========================================================================*/


/*===========================================================================
 *
 * Class CSrRaceRecord Event - void OnDeleteSubrecord (pSubrecord);
 *
 *=========================================================================*/
void CSrRaceRecord::OnDeleteSubrecord (CSrSubrecord* pSubrecord) {

	if (m_pDescription == pSubrecord)
		m_pDescription = NULL;
	else if (m_pItemName == pSubrecord)
		m_pItemName = NULL;
	else if (m_pNakedArmor == pSubrecord)
		m_pNakedArmor = NULL;
	else if (m_pRaceData == pSubrecord)
		m_pRaceData = NULL;
	else if (m_pBodyData == pSubrecord)
		m_pBodyData = NULL;
	else if (m_pSpellCount == pSubrecord)
		m_pSpellCount = NULL;
	else
		CSrIdKeyRecord::OnDeleteSubrecord(pSubrecord);

}
/*===========================================================================
 *		End of Class Event CSrRaceRecord::OnDeleteSubrecord()
 *=========================================================================*/


CSrFormidSubrecord* CSrRaceRecord::AddSpell (const srformid_t FormID)
{
	CSrSubrecord* pSubrecord = AddInitNewSubrecordAfter(SR_NAME_SPLO, SR_NAME_SPCT);
	CSrFormidSubrecord* pFormID = SrCastClassNull(CSrFormidSubrecord, pSubrecord);
	if (pFormID == NULL) return NULL;

	pFormID->SetValue(FormID);
	return pFormID;
}


/*===========================================================================
 *
 * Begin CSrRaceRecord Get Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRaceRecord Get Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRaceRecord Compare Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRaceRecord Compare Field Methods
 *=========================================================================*/


/*===========================================================================
 *
 * Begin CSrRaceRecord Set Field Methods
 *
 *=========================================================================*/
/*===========================================================================
 *		End of CSrRaceRecord Set Field Methods
 *=========================================================================*/
