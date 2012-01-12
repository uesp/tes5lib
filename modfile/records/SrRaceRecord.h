/*===========================================================================
 *
 * File:		SrRacerecord.H
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	5 December 2011
 *
 * Defines the CSrRaceRecord class.
 *
 *=========================================================================*/
#ifndef __SRRACERECORD_H
#define __SRRACERECORD_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
	#include "sridkeyrecord.h"
	#include "../subrecords/srlstringsubrecord.h"
	#include "../subrecords/srracedatasubrecord.h"
	#include "../subrecords/srbodtsubrecord.h"
	#include "../subrecords/sratkdsubrecord.h"
	#include "../subrecords/srphwtsubrecord.h"
	#include "../subrecords/srspedsubrecord.h"
	#include "../subrecords/srmpavsubrecord.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Class CSrRaceRecord Definition
 *
 *=========================================================================*/
class CSrRaceRecord : public CSrIdKeyRecord 
{
	DECLARE_SRSUBRECCREATE()
	DECLARE_SRFIELDMAP()
	DECLARE_SRCLASS(CSrRaceRecord, CSrIdKeyRecord)

  /*---------- Begin Protected Class Members --------------------*/
protected:
	CSrLStringSubrecord*	m_pDescription;
	CSrLStringSubrecord*	m_pItemName;
	CSrDwordSubrecord*		m_pSpellCount;
	CSrFormidSubrecord*		m_pNakedArmor;
	CSrBodtSubrecord*		m_pBodyData;
	CSrRaceDataSubrecord*	m_pRaceData;

	CSString				m_BodyPartsString;


	static srracedata_t s_NullRaceData;
	static srbodtdata_t s_NullBodtData;


  /*---------- Begin Protected Class Methods --------------------*/
protected:


  /*---------- Begin Public Class Methods -----------------------*/
public:

		/* Class Constructors/Destructors */
	CSrRaceRecord();
	virtual void Destroy (void);

	CSrFormidSubrecord* AddSpell (const srformid_t FormID);

    	/* Return a new instance of the class */
	static CSrRecord* Create (void) { return new CSrRaceRecord; }

		/* Get class members */
	dword         GetSpellCount (void) { return m_pSpellCount ? m_pSpellCount->GetValue() : 0; }
	srracedata_t& GetRaceData   (void) { return m_pRaceData ? m_pRaceData->GetRaceData() : s_NullRaceData; } 
	srbodtdata_t& GetBodyData   (void) { return m_pBodyData ? m_pBodyData->GetBodtData() : s_NullBodtData; }

	const char* GetBodyParts (void) { m_BodyPartsString = GetSrBodyPartFlagString(GetBodyData().BodyParts); return m_BodyPartsString.c_str(); }

	const char* GetRaceSkillAV    (const dword Index) { return (Index < SR_RACE_MAXSKILLINDEX) ? GetSrActorValueString((int)(char)GetRaceData().Skills[Index].ActorValue) : ""; }
	byte        GetRaceSkillValue (const dword Index) { return (Index < SR_RACE_MAXSKILLINDEX) ? GetRaceData().Skills[Index].Value: 0; }
	const char* GetRaceSkillAV1   (void) { return GetRaceSkillAV(0); }
	const char* GetRaceSkillAV2   (void) { return GetRaceSkillAV(1); }
	const char* GetRaceSkillAV3   (void) { return GetRaceSkillAV(2); }
	const char* GetRaceSkillAV4   (void) { return GetRaceSkillAV(3); }
	const char* GetRaceSkillAV5   (void) { return GetRaceSkillAV(4); }
	const char* GetRaceSkillAV6   (void) { return GetRaceSkillAV(5); }
	const char* GetRaceSkillAV7   (void) { return GetRaceSkillAV(6); }

		/* Initialize a new record */
	void InitializeNew (void);

		/* Called to alert record of a new subrecord being added */
	virtual void OnAddSubrecord    (CSrSubrecord* pSubrecord);
	virtual void OnDeleteSubrecord (CSrSubrecord* pSubrecord);

		/* Set class members */
	void SetBodyParts   (const char* pString) { GetSrBodyPartFlagValue(GetBodyData().BodyParts, pString); }

	void SetRaceSkillAV    (const dword Index, const char* pString) { int Value = -1; if (Index < SR_RACE_MAXSKILLINDEX) { GetSrActorValueValue(Value, pString); GetRaceData().Skills[Index].ActorValue = (byte) Value; } }
	void SetRaceSkillValue (const dword Index, const byte    Value) { if (Index < SR_RACE_MAXSKILLINDEX) GetRaceData().Skills[Index].Value = Value; }
	void SetRaceSkillAV1   (const char* pString) { SetRaceSkillAV(0, pString); }
	void SetRaceSkillAV2   (const char* pString) { SetRaceSkillAV(1, pString); }
	void SetRaceSkillAV3   (const char* pString) { SetRaceSkillAV(2, pString); }
	void SetRaceSkillAV4   (const char* pString) { SetRaceSkillAV(3, pString); }
	void SetRaceSkillAV5   (const char* pString) { SetRaceSkillAV(4, pString); }
	void SetRaceSkillAV6   (const char* pString) { SetRaceSkillAV(5, pString); }
	void SetRaceSkillAV7   (const char* pString) { SetRaceSkillAV(6, pString); }	

		/* Begin field method definitions */
	DECLARE_SRFIELD_DESCRIPTION(CSrRaceRecord, SR_NAME_DESC)
	DECLARE_SRFIELD_ITEMNAME(CSrRaceRecord)
	DECLARE_SRFIELD_EDITORID1(CSrRaceRecord, NakedArmor, SR_NAME_WNAM)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, BodyParts, GetBodyParts, SetBodyParts)
	DECLARE_SRFIELD_DWORD1(CSrRaceRecord, SpellCount, GetSpellCount(), dword Tmp)

	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue1, GetRaceSkillAV1, SetRaceSkillAV1)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue2, GetRaceSkillAV2, SetRaceSkillAV2)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue3, GetRaceSkillAV3, SetRaceSkillAV3)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue4, GetRaceSkillAV4, SetRaceSkillAV4)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue5, GetRaceSkillAV5, SetRaceSkillAV5)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue6, GetRaceSkillAV6, SetRaceSkillAV6)
	DECLARE_SRFIELD_METHOD(CSrRaceRecord, ActorValue7, GetRaceSkillAV7, SetRaceSkillAV7)

	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill1,      GetRaceData().Skills[0].Value,      GetRaceData().Skills[0].Value)
	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill2,      GetRaceData().Skills[1].Value,      GetRaceData().Skills[1].Value)
	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill3,      GetRaceData().Skills[2].Value,      GetRaceData().Skills[2].Value)
	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill4,      GetRaceData().Skills[3].Value,      GetRaceData().Skills[3].Value)
	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill5,      GetRaceData().Skills[4].Value,      GetRaceData().Skills[4].Value)
	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill6,      GetRaceData().Skills[5].Value,      GetRaceData().Skills[5].Value)
	DECLARE_SRFIELD_BYTE1(CSrRaceRecord, Skill7,      GetRaceData().Skills[6].Value,      GetRaceData().Skills[6].Value)

	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, MaleHeight, GetRaceData().MaleHeight, GetRaceData().MaleHeight)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, FemaleHeight, GetRaceData().FemaleHeight, GetRaceData().FemaleHeight)

	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown1,  GetRaceData().Unknown1,  GetRaceData().Unknown1)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown2,  GetRaceData().Unknown2,  GetRaceData().Unknown2)
	DECLARE_SRFIELD_DWORDFLAG1(CSrRaceRecord, Unknown3,  GetRaceData().Unknown3,  GetRaceData().Unknown3)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown4,  GetRaceData().Unknown4,  GetRaceData().Unknown4)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown5,  GetRaceData().Unknown5,  GetRaceData().Unknown5)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown6,  GetRaceData().Unknown6,  GetRaceData().Unknown6)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown7,  GetRaceData().Unknown7,  GetRaceData().Unknown7)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown8,  GetRaceData().Unknown8,  GetRaceData().Unknown8)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown9,  GetRaceData().Unknown9,  GetRaceData().Unknown9)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown10, GetRaceData().Unknown10,  GetRaceData().Unknown10)
	DECLARE_SRFIELD_INT1(CSrRaceRecord, Unknown11, GetRaceData().Unknown11, GetRaceData().Unknown11)
	DECLARE_SRFIELD_INT1(CSrRaceRecord, Unknown12, GetRaceData().Unknown12, GetRaceData().Unknown12)
	DECLARE_SRFIELD_INT1(CSrRaceRecord, Unknown13, GetRaceData().Unknown13, GetRaceData().Unknown13)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown14, GetRaceData().Unknown14, GetRaceData().Unknown14)
	DECLARE_SRFIELD_INT1(CSrRaceRecord, Unknown15, GetRaceData().Unknown15, GetRaceData().Unknown15)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown16, GetRaceData().Unknown16, GetRaceData().Unknown16)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown17, GetRaceData().Unknown17, GetRaceData().Unknown17)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown18, GetRaceData().Unknown18, GetRaceData().Unknown18)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown19, GetRaceData().Unknown19, GetRaceData().Unknown19)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown20, GetRaceData().Unknown20, GetRaceData().Unknown20)
	DECLARE_SRFIELD_INT1(CSrRaceRecord, Unknown21, GetRaceData().Unknown21, GetRaceData().Unknown21)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown22, GetRaceData().Unknown22, GetRaceData().Unknown22)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown23, GetRaceData().Unknown23, GetRaceData().Unknown23)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown24, GetRaceData().Unknown24, GetRaceData().Unknown24)
	DECLARE_SRFIELD_FLOAT1(CSrRaceRecord, Unknown25, GetRaceData().Unknown25, GetRaceData().Unknown25)
	DECLARE_SRFIELD_INT1(CSrRaceRecord, Unknown26, GetRaceData().Unknown26, GetRaceData().Unknown26)

};
/*===========================================================================
 *		End of Class CSrRaceRecord Definition
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File SrRaceRecord.H
 *=========================================================================*/
