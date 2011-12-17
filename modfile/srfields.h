/*===========================================================================
 *
 * File:	Srfields.H
 * Author:	Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Basic definitions for field IDs.
 *
 *=========================================================================*/
#ifndef __SRFIELDS_H
#define __SRFIELDS_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "../common/textutils.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Type Definitions
 *
 *=========================================================================*/

	/* The basic field ID type */
  typedef long srfieldid_t;
  typedef srfieldid_t srrecfieldid_t;

/*===========================================================================
 *		End of Type Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

	/* Default format strings */
  #define SR_FORMATSTR_WEIGHT "%g"

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Field Types
 *
 *=========================================================================*/

  #define SR_FIELD_UNKNOWN			-1
  #define SR_FIELD_NONE				0
  #define SR_FIELD_RECORDTYPE		1
  #define SR_FIELD_FORMID			2
  #define SR_FIELD_EDITORID			3
  #define SR_FIELD_ITEMNAME			4
  #define SR_FIELD_FULLNAME			4
  #define SR_FIELD_VALUE			5
  #define SR_FIELD_WEIGHT			6
  #define SR_FIELD_TYPE				7
  #define SR_FIELD_BIPED			8
  #define SR_FIELD_ICON				9
  #define SR_FIELD_ICON2			10
  #define SR_FIELD_MODEL			11
  #define SR_FIELD_MODEL2			12
  #define SR_FIELD_MODEL3			13
  #define SR_FIELD_MODEL4			14
  #define SR_FIELD_ARMOR			15
  #define SR_FIELD_DAMAGE			16
  #define SR_FIELD_SPEED			17
  #define SR_FIELD_REACH			18
  #define SR_FIELD_HEALTH			19
  #define SR_FIELD_FLAGS			20
  #define SR_FIELD_AUTHOR			21
  #define SR_FIELD_SUMMARY			22
  #define SR_FIELD_VERSION			23
  #define SR_FIELD_FILETYPE			24
  #define SR_FIELD_ENCHANTMENT		25
  #define SR_FIELD_ENCHANTPOINTS	26
  #define SR_FIELD_QUALITY			27
  #define SR_FIELD_IGNORERESIST		28
  #define SR_FIELD_HIDEAMULET		29
  #define SR_FIELD_HIDERINGS		30
  #define SR_FIELD_TEACHES			31
  #define SR_FIELD_SCROLL			32
  #define SR_FIELD_NOTAKE			33
  #define SR_FIELD_TEXT				34
  #define SR_FIELD_CHARGE			35
  #define SR_FIELD_COST				36
  #define SR_FIELD_AUTOCALC			37
  #define SR_FIELD_FOOD				38
  #define SR_FIELD_FOODITEM			38
  #define SR_FIELD_SCRIPT			39
  #define SR_FIELD_CHANCENONE		40
  #define SR_FIELD_CALCULATEALL		41
  #define SR_FIELD_CALCULATEEACH	42
  #define SR_FIELD_ITEMLIST			43
  #define SR_FIELD_SCRIPTTEXT		44
  #define SR_FIELD_USES				45
  #define SR_FIELD_LEVEL			46
  #define SR_FIELD_PLAYERSTART		47
  #define SR_FIELD_IGNORELOS		48
  #define SR_FIELD_ALWAYSAPPLY		49
  #define SR_FIELD_ABSORBREFLECT	50
  #define SR_FIELD_SILENCEIMMUNE	51
  #define SR_FIELD_RECORDCOUNT		52
  #define SR_FIELD_ITEMCOUNT		53
  #define SR_FIELD_EFFECTCOUNT		54
  #define SR_FIELD_USERDATA			55
  #define SR_FIELD_EFFECTID			56
  #define SR_FIELD_EFFECTNAME		57
  #define SR_FIELD_MAGNITUDE		58
  #define SR_FIELD_AREA				59
  #define SR_FIELD_DURATION			60
  #define SR_FIELD_RANGE			61
  #define SR_FIELD_SCHOOL			62
  #define SR_FIELD_ACTORVALUE		63
  #define SR_FIELD_EFFECTDESC		64
  #define SR_FIELD_SCRIPTSCHOOL		65
  #define SR_FIELD_VISUALNAME		66
  #define SR_FIELD_HOSTILE			67
  #define SR_FIELD_DATANAME			68
  #define SR_FIELD_NAME2			69
  #define SR_FIELD_SCRIPTID			70
  #define SR_FIELD_PLAYABLE			71
  #define SR_FIELD_TIME				72
  #define SR_FIELD_RADIUS			73
  #define SR_FIELD_FOV				74
  #define SR_FIELD_CARRIED			75
  #define SR_FIELD_COLOR			76
  #define SR_FIELD_FADE				77
  #define SR_FIELD_FALLOFF			78
  #define SR_FIELD_DYNAMIC			79
  #define SR_FIELD_NEGATIVE			80
  #define SR_FIELD_DEFAULTOFF		81
  #define SR_FIELD_SPOTLIGHT		82
  #define SR_FIELD_SPOTSHADOW		83
  #define SR_FIELD_SOUNDID			84
  #define SR_FIELD_SOUND			85
  #define SR_FIELD_ENCHANTMENTID	86
  #define SR_FIELD_LOCATIONX		87
  #define SR_FIELD_LOCATIONY		88
  #define SR_FIELD_LOCATIONZ		89
  #define SR_FIELD_ANGLEX			90
  #define SR_FIELD_ANGLEY			91
  #define SR_FIELD_ANGLEZ			92
  #define SR_FIELD_TELEPORTFORMID	93
  #define SR_FIELD_TELEPORTNAME		94
  #define SR_FIELD_TELEPORTLOCX		95
  #define SR_FIELD_TELEPORTLOCY		96
  #define SR_FIELD_TELEPORTLOCZ		97
  #define SR_FIELD_TELEPORTANGLEX	98
  #define SR_FIELD_TELEPORTANGLEY	99
  #define SR_FIELD_TELEPORTANGLEZ	100
  #define SR_FIELD_WORLDSPACE		101
  #define SR_FIELD_MARKERTYPE		102
  #define SR_FIELD_MARKERTYPEID		103
  #define SR_FIELD_BASEFORMID		104
  #define SR_FIELD_BASEEDITORID		105
  #define SR_FIELD_BASENAME			106
  #define SR_FIELD_LINECOUNT		107
  #define SR_FIELD_SIZE				108
  #define SR_FIELD_REALARMOR		109
  #define SR_FIELD_QUESTITEM		110
  #define SR_FIELD_DANGEROUS		111
  #define SR_FIELD_IGNORED			112
  #define SR_FIELD_DELETED			113
  #define SR_FIELD_USEALLSPELLS		114
  #define SR_FIELD_TEMPLATE			115
  #define SR_FIELD_TEMPLATEID		116
  #define SR_FIELD_CAPACITY			117
  #define SR_FIELD_SOUL				118
  #define SR_FIELD_RESPAWNS			119
  #define SR_FIELD_OPENSOUND		120
  #define SR_FIELD_OPENSOUNDID		121
  #define SR_FIELD_CLOSESOUND		122
  #define SR_FIELD_CLOSESOUNDID		123
  #define SR_FIELD_MINATTENUATION       125
  #define SR_FIELD_MAXATTENUATION       126
  #define SR_FIELD_STATICATTENUATION    127
  #define SR_FIELD_FREQADJUSTMENT       128
  #define SR_FIELD_STARTTIME            129
  #define SR_FIELD_STOPTIME             130
  #define SR_FIELD_RANDOMFREQSHIFT      131
  #define SR_FIELD_RANDOMPLAY           132
  #define SR_FIELD_RANDOMLOCATION       133
  #define SR_FIELD_LOOP                 134
  #define SR_FIELD_MENUSOUND            135
  #define SR_FIELD_IGNOREENVIRONMENT    136
  #define SR_FIELD_2DSOUND              137
  #define SR_FIELD_360LFE               138
  #define SR_FIELD_INGREDIANT			139
  #define SR_FIELD_INGREDIANTID			140
  #define SR_FIELD_SPRING				141
  #define SR_FIELD_SUMMER				142
  #define SR_FIELD_FALL					143
  #define SR_FIELD_WINTER				144
  #define SR_FIELD_SOUNDFILE			145
  #define SR_FIELD_REDCOLOR				146
  #define SR_FIELD_GREENCOLOR			147
  #define SR_FIELD_BLUECOLOR			148
  #define SR_FIELD_NEXTOBJECTID			149
  #define SR_FIELD_CNAM					150
  #define SR_FIELD_KEYWORDCOUNT			151
  #define SR_FIELD_KEYWORDS				152
  #define SR_FIELD_MATERIAL				153
  #define SR_FIELD_VNAM					154
  #define SR_FIELD_DESCRIPTION			155
  #define SR_FIELD_EFFECTTYPE			156
  #define SR_FIELD_CONDITIONCOUNT		157
  #define SR_FIELD_OPERATOR				158
  #define SR_FIELD_REFERENCE			159
  #define SR_FIELD_FUNCTION				160
  #define SR_FIELD_PARAM1				161
  #define SR_FIELD_PARAM2				162
  #define SR_FIELD_CONDFLAGS			163
  #define SR_FIELD_COMPONENTCOUNT		164
  #define SR_FIELD_RESULTCOUNT			165
  #define SR_FIELD_STATION				166
  #define SR_FIELD_RESULTITEM			167
  #define SR_FIELD_CONDFLAGSEX			168
  #define SR_FIELD_COUNT				169
  #define SR_FIELD_COMPONENT			170
  #define SR_FIELD_COMPCOUNT			171
  #define SR_FIELD_COMPFORMID			172
  #define SR_FIELD_COMPITEMNAME			173
  #define SR_FIELD_EQUIPSLOT			174
  #define SR_FIELD_SKILLLEVEL			175
  #define SR_FIELD_CASTINGDELAY			176
  #define SR_FIELD_BASECOST				177
  #define SR_FIELD_MAGICFLAGS			178
  #define SR_FIELD_BASEENCHANT			179
  #define SR_FIELD_ITEMTYPES			180
  #define SR_FIELD_ENCHANTCOST			181
  #define SR_FIELD_PERK					182
  #define SR_FIELD_SPELLFLAGS			183
  #define SR_FIELD_SPELLTYPE			184
  #define SR_FIELD_CASTTIME				185
  #define SR_FIELD_CASTANIM				186
  #define SR_FIELD_CASTTYPE				187
  #define SR_FIELD_PERKID				188
  #define SR_FIELD_EQUIPSLOTID			189
  #define SR_FIELD_UNKNOWN1				190
  #define SR_FIELD_UNKNOWN2				191
  #define SR_FIELD_UNKNOWN3				192
  #define SR_FIELD_UNKNOWN4				193
  #define SR_FIELD_UNKNOWN5				194
  #define SR_FIELD_TYPEA				195
  #define SR_FIELD_TYPEB				196
  #define SR_FIELD_TYPEC				197
  #define SR_FIELD_TYPED				198
  #define SR_FIELD_STAFFMOD				199
  #define SR_FIELD_PICKUPSOUND			200
  #define SR_FIELD_DROPSOUND			201
  #define SR_FIELD_VANISH				202
  #define SR_FIELD_PROJECTILE			203
  #define SR_FIELD_RATING				204
  #define SR_FIELD_BODYPARTS			205
  #define SR_FIELD_RACE					206
  #define SR_FIELD_BAMT					207
  #define SR_FIELD_IMPACTDATA			208
  #define SR_FIELD_ANAM					209

/*===========================================================================
 *		End of Field Types
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Function Prototypes
 *
 *=========================================================================*/

  bool          GetSrFieldValue  (int& Value, const SSCHAR* pString);
  const SSCHAR* GetSrFieldString (const int Value);

  bool SrFieldConvertLong    (const SSCHAR* pString, long&  Value);
  bool SrFieldConvertInt     (const SSCHAR* pString, int&   Value);
  bool SrFieldConvertDword   (const SSCHAR* pString, dword& Value);
  bool SrFieldConvertShort   (const SSCHAR* pString, short& Value);
  bool SrFieldConvertWord    (const SSCHAR* pString, word&  Value);
  bool SrFieldConvertByte    (const SSCHAR* pString, byte&  Value);
  bool SrFieldConvertFloat   (const SSCHAR* pString, float& Value);
  bool SrFieldConvertBoolean (const SSCHAR* pString, bool&  Value);
  bool SrFieldConvertColor   (const SSCHAR* pString, srrgba_t& Value);

/*===========================================================================
 *		End of Function Prototypes
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srfields.H
 *=========================================================================*/
