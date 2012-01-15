/*===========================================================================
 *
 * File:		Srmoddefs.CPP
 * Author:		Dave Humphrey (dave@uesp.net)
 * Created On:	26 November 2011
 *
 * Description
 *
 *=========================================================================*/

	/* Include Files */
#include "srmoddefs.h"
#include "ctype.h"


/*===========================================================================
 *
 * Begin Global Constants
 *
 *=========================================================================*/
const srrgba_t SR_COLOR_NULL = { 0, 0, 0, 0 };

CSString g_SrLanguage("English");
/*===========================================================================
 *		End of Global Constants
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Constant String Tables
 *
 *=========================================================================*/
BEGIN_STRINGVALUE(s_SrMagicSchools)
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_ALTERATION,	"Alteration")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_CONJURATION,	"Conjuration")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_DESTRUCTION,	"Destruction")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_ILLUSION,		"Illusion")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_RESTORATION,	"Restoration")
	ADD_STRINGVALUE( SR_MAGIC_SCHOOL_NONE,			"None")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrMagicTypes)
	ADD_STRINGVALUE( SR_MAGIC_TYPE_EXTRADMG,	"Extra Damage")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_POISON,		"Poison")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_FIRE,		"Fire")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_SHOCK,		"Shock")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_FROST,		"Frost")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_DRAIN,		"Drain")
	ADD_STRINGVALUE( SR_MAGIC_TYPE_NONE,		"None")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrConditionOperators)
	ADD_STRINGVALUE( SR_CONDOP_EQUAL,			"==")
	ADD_STRINGVALUE( SR_CONDOP_NOTEQUAL,		"!=")
	ADD_STRINGVALUE( SR_CONDOP_GREATER,			">")
	ADD_STRINGVALUE( SR_CONDOP_GREATEREQUAL,	">=")
	ADD_STRINGVALUE( SR_CONDOP_LESS,			"<")
	ADD_STRINGVALUE( SR_CONDOP_LESSEQUAL,		"<=")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSpellTypes)
	ADD_STRINGVALUE( SR_SPELL_TYPE_SPELL,		"Spell")
	ADD_STRINGVALUE( SR_SPELL_TYPE_DISEASE,		"Disease")
	ADD_STRINGVALUE( SR_SPELL_TYPE_POWER,		"Destruction")
	ADD_STRINGVALUE( SR_SPELL_TYPE_LESSERPOWER,	"Lesser Power")
	ADD_STRINGVALUE( SR_SPELL_TYPE_ABILITY,		"Ability")
	ADD_STRINGVALUE( SR_SPELL_TYPE_POISON,		"Poison")
	ADD_STRINGVALUE( SR_SPELL_TYPE_VOICE,		"Voice")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSpellCastAnims)
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_NONE,		"None")
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_PROJECTILE,	"Projectile")
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_SUSTAINED,	"Sustained")
	ADD_STRINGVALUE( SR_SPELL_CASTANIM_3,			"3")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSpellCastTypes)
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_0,		"CastType0")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_1,		"CastType1")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_2,		"CastType2")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_3,		"CastType3")
	ADD_STRINGVALUE( SR_SPELL_CASTTYPE_4,		"CastType4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeA)
	ADD_STRINGVALUE( 0,		"0")
	ADD_STRINGVALUE( 1,		"1")
	ADD_STRINGVALUE( 4,		"4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeB)
	ADD_STRINGVALUE( 0,		"0")
	ADD_STRINGVALUE( 1,		"1")
	ADD_STRINGVALUE( 2,		"2")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeC)
	ADD_STRINGVALUE( 0,		"0")
	ADD_STRINGVALUE( 1,		"1")
	ADD_STRINGVALUE( 2,		"2")
	ADD_STRINGVALUE( 3,		"3")
	ADD_STRINGVALUE( 4,		"4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEnchantTypeD)
	ADD_STRINGVALUE( 6,		"6")
	ADD_STRINGVALUE( 12,	"12")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrBodyParts)
	ADD_STRINGVALUE( SR_BODYPARTS_SKIN				,	"Skin")
	ADD_STRINGVALUE( SR_BODYPARTS_HEAD				,	"Head")
	ADD_STRINGVALUE( SR_BODYPARTS_CHEST				,	"Chest")
	ADD_STRINGVALUE( SR_BODYPARTS_HANDS				,	"Hand")
	ADD_STRINGVALUE( SR_BODYPARTS_BEARD				,	"Beard")
	ADD_STRINGVALUE( SR_BODYPARTS_AMULET			,	"Amulet")
	ADD_STRINGVALUE( SR_BODYPARTS_RING				,	"Ring")
	ADD_STRINGVALUE( SR_BODYPARTS_FEET				,	"Feet")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN1			,	"0x00000100")
	ADD_STRINGVALUE( SR_BODYPARTS_SHIELD			,	"Shield")
	ADD_STRINGVALUE( SR_BODYPARTS_ANIMALSKIN		,	"AnimalSkin")
	ADD_STRINGVALUE( SR_BODYPARTS_UNDERSKIN			,	"UnderSkin")
	ADD_STRINGVALUE( SR_BODYPARTS_CROWN				,	"Crown")
	ADD_STRINGVALUE( SR_BODYPARTS_FACE				,	"Face")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONHEAD		,	"DragonHead")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONLWING		,	"DragonLeftWing")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONRWING		,	"DragonRightWing")
	ADD_STRINGVALUE( SR_BODYPARTS_DRAGONBODY		,	"DragonBody")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN3			,	"0x00100000")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN4			,	"0x00200000")
	ADD_STRINGVALUE( SR_BODYPARTS_UNKNOWN2			,	"0x80000000")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrArmorTypes)
	ADD_STRINGVALUE( SR_ARMORTYPE_NONE,		"None")
	ADD_STRINGVALUE( SR_ARMORTYPE_LIGHT,	"Light")
	ADD_STRINGVALUE( SR_ARMORTYPE_HEAVY,	"Heavy")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPotionTypes)
	ADD_STRINGVALUE( SR_POTIONTYPE_0,		"0x0000")
	ADD_STRINGVALUE( SR_POTIONTYPE_1,		"0x0001")
	ADD_STRINGVALUE( SR_POTIONTYPE_2,		"0x0002")
	ADD_STRINGVALUE( SR_POTIONTYPE_FOOD,	"Food")
	ADD_STRINGVALUE( SR_POTIONTYPE_HARMFUL,	"Harmful")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSkillTypes)
	ADD_STRINGVALUE(SR_SKILL_ONEHAND 	 ,		"OneHand")
	ADD_STRINGVALUE(SR_SKILL_TWOHAND 	 ,		"TwoHand")
	ADD_STRINGVALUE(SR_SKILL_MARKSMAN 	 ,		"Marksman")
	ADD_STRINGVALUE(SR_SKILL_BLOCK 		 ,		"Block")
	ADD_STRINGVALUE(SR_SKILL_SMITHING 	 ,		"Smithing")
	ADD_STRINGVALUE(SR_SKILL_HEAVYARMOR  ,		"HeavyArmor")
	ADD_STRINGVALUE(SR_SKILL_LIGHTARMOR  ,		"LightArmor")
	ADD_STRINGVALUE(SR_SKILL_PICKPOCKET  ,		"Pickpocket")
	ADD_STRINGVALUE(SR_SKILL_LOCKPICKING ,		"Lockpicking")
	ADD_STRINGVALUE(SR_SKILL_SNEAK 		 ,		"Sneak")
	ADD_STRINGVALUE(SR_SKILL_ALCHEMY 	 ,		"Alchemy")
	ADD_STRINGVALUE(SR_SKILL_SPEECHCRAFT ,		"Speechcraft")
	ADD_STRINGVALUE(SR_SKILL_ALTERATION  ,		"Alteration")
	ADD_STRINGVALUE(SR_SKILL_CONJURATION ,		"Conjuration")
	ADD_STRINGVALUE(SR_SKILL_DESTRUCTION ,		"Destruction")
	ADD_STRINGVALUE(SR_SKILL_ILLUSION 	 ,		"Illusion")
	ADD_STRINGVALUE(SR_SKILL_RESTORATION ,		"Restoration")
	ADD_STRINGVALUE(SR_SKILL_ENCHANTING  ,		"Enchanting")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrContainerTypes)
	ADD_STRINGVALUE( 0,	"0")
	ADD_STRINGVALUE( 1,	"1")
	ADD_STRINGVALUE( 2,	"2")
	ADD_STRINGVALUE( 3,	"3")
	ADD_STRINGVALUE( 4,	"4")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrLightTypes)
    ADD_STRINGVALUE( 0,							"None")
	ADD_STRINGVALUE( SR_LIGHTTYPE_FLICKER,		"Flicker")
	ADD_STRINGVALUE( SR_LIGHTTYPE_FLICKERSLOW,	"FlickerSlow")
	ADD_STRINGVALUE( SR_LIGHTTYPE_PULSE,		"Pulse")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEffectCastTypes)
    ADD_STRINGVALUE( SR_EFFECT_CASTTYPE_NONE,		"None")
	ADD_STRINGVALUE( SR_EFFECT_CASTTYPE_NORMAL,		"Normal")
	ADD_STRINGVALUE( SR_EFFECT_CASTTYPE_CHANNELED,	"Channeled")
END_STRINGVALUE()	


BEGIN_STRINGVALUE(s_SrActorValues)
    ADD_STRINGVALUE( -1,  "None"  )
	ADD_STRINGVALUE( 0, "Aggression" )
	ADD_STRINGVALUE( 1, "Confidence" )
	ADD_STRINGVALUE( 2, "Energy" )
	ADD_STRINGVALUE( 3, "Morality" )
	ADD_STRINGVALUE( 4, "Mood" )
	ADD_STRINGVALUE( 5, "Assistance" )
	ADD_STRINGVALUE( 6, "OneHanded" )
	ADD_STRINGVALUE( 7, "TwoHanded" )
	ADD_STRINGVALUE( 8, "Marksman" )
	ADD_STRINGVALUE( 9, "Block" )
	ADD_STRINGVALUE( 10, "Smithing" )
	ADD_STRINGVALUE( 11, "HeavyArmor" )
	ADD_STRINGVALUE( 12, "LightArmor" )
	ADD_STRINGVALUE( 13, "Pickpocket" )
	ADD_STRINGVALUE( 14, "Lockpicking" )
	ADD_STRINGVALUE( 15, "Sneak" )
	ADD_STRINGVALUE( 16, "Alchemy" )
	ADD_STRINGVALUE( 17, "Speechcraft" )
	ADD_STRINGVALUE( 18, "Alteration" )
	ADD_STRINGVALUE( 19, "Conjuration" )
	ADD_STRINGVALUE( 20, "Destruction" )
	ADD_STRINGVALUE( 21, "Illusion" )
	ADD_STRINGVALUE( 22, "Restoration" )
	ADD_STRINGVALUE( 23, "Enchanting" )
	ADD_STRINGVALUE( 24, "Health" )
	ADD_STRINGVALUE( 25, "Magicka" )
	ADD_STRINGVALUE( 26, "Stamina" )
	ADD_STRINGVALUE( 27, "HealRate" )
	ADD_STRINGVALUE( 28, "MagickaRate" )
	ADD_STRINGVALUE( 29, "StaminaRate" )
	ADD_STRINGVALUE( 30, "SpeedMult" )
	ADD_STRINGVALUE( 31, "InventoryWeight" )
	ADD_STRINGVALUE( 32, "CarryWeight" )
	ADD_STRINGVALUE( 33, "DragonRend" )
	ADD_STRINGVALUE( 34, "MeleeDamage" )
	ADD_STRINGVALUE( 35, "UnarmedDamage" )
	ADD_STRINGVALUE( 36, "Mass" )
	ADD_STRINGVALUE( 37, "VoicePoints" )
	ADD_STRINGVALUE( 38, "VoiceRate" )
	ADD_STRINGVALUE( 39, "DamageResist" )
	ADD_STRINGVALUE( 40, "PoisonResist" )
	ADD_STRINGVALUE( 41, "FireResist" )
	ADD_STRINGVALUE( 42, "ElectricResist" )
	ADD_STRINGVALUE( 43, "FrostResist" )
	ADD_STRINGVALUE( 44, "MagicResist" )
	ADD_STRINGVALUE( 45, "DiseaseResist" )
	ADD_STRINGVALUE( 46, "46" )
	ADD_STRINGVALUE( 47, "47" )
	ADD_STRINGVALUE( 48, "48" )
	ADD_STRINGVALUE( 49, "49" )
	ADD_STRINGVALUE( 50, "50" )
	ADD_STRINGVALUE( 51, "51" )
	ADD_STRINGVALUE( 52, "52" )
	ADD_STRINGVALUE( 53, "Paralysis" )
	ADD_STRINGVALUE( 54, "Invisibility" )
	ADD_STRINGVALUE( 55, "NightEye" )
	ADD_STRINGVALUE( 56, "DetectLifeRange" )
	ADD_STRINGVALUE( 57, "WaterBreathing" )
	ADD_STRINGVALUE( 58, "WaterWalking" )
	ADD_STRINGVALUE( 59, "IgnoreCrippledLimbs" )
	ADD_STRINGVALUE( 60, "Fame" )
	ADD_STRINGVALUE( 61, "Infamy" )
	ADD_STRINGVALUE( 62, "JumpingBonus" )
	ADD_STRINGVALUE( 63, "WardPower" )
	ADD_STRINGVALUE( 64, "RightItemCharge" )
	ADD_STRINGVALUE( 65, "LeftItemCharge" )
	ADD_STRINGVALUE( 66, "EquippedItemCharge" )
	ADD_STRINGVALUE( 67, "ArmorPerks" )
	ADD_STRINGVALUE( 68, "ShieldPerks" )
	ADD_STRINGVALUE( 69, "Variable01" )
	ADD_STRINGVALUE( 70, "Variable02" )
	ADD_STRINGVALUE( 71, "Variable03" )
	ADD_STRINGVALUE( 72, "Variable04" )
	ADD_STRINGVALUE( 73, "Variable05" )
	ADD_STRINGVALUE( 74, "Variable06" )
	ADD_STRINGVALUE( 75, "Variable07" )
	ADD_STRINGVALUE( 76, "Variable08" )
	ADD_STRINGVALUE( 77, "Variable09" )
	ADD_STRINGVALUE( 78, "Variable10" )
	ADD_STRINGVALUE( 79, "FavorActive" )
	ADD_STRINGVALUE( 80, "FavorsPerDay" )
	ADD_STRINGVALUE( 81, "FavorsPerDayTimer" )
	ADD_STRINGVALUE( 82, "EquippedStaffCharge" )
	ADD_STRINGVALUE( 83, "AbsorbChance" )
	ADD_STRINGVALUE( 84, "Blindness" )
	ADD_STRINGVALUE( 85, "WeaponSpeedMult" )
	ADD_STRINGVALUE( 86, "ShoutRecoveryMult" )
	ADD_STRINGVALUE( 87, "BowStaggerBonus" )
	ADD_STRINGVALUE( 88, "Telekinesis" )
	ADD_STRINGVALUE( 89, "FavorPointsBonus" )
	ADD_STRINGVALUE( 90, "LastBribedIntimidated" )
	ADD_STRINGVALUE( 91, "LastFlattered" )
	ADD_STRINGVALUE( 92, "MovementNoiseMult" )
	ADD_STRINGVALUE( 93, "BypassVendorStolenCheck" )
	ADD_STRINGVALUE( 94, "BypassVendorKeywordCheck" )
	ADD_STRINGVALUE( 95, "WaitingForPlayer" )
	ADD_STRINGVALUE( 96, "OneHandedMod" )
	ADD_STRINGVALUE( 97, "TwoHandedMod" )
	ADD_STRINGVALUE( 98, "MarksmanMod" )
	ADD_STRINGVALUE( 99, "BlockMod" )
	ADD_STRINGVALUE( 100, "SmithingMod" )
	ADD_STRINGVALUE( 101, "HeavyArmorMod" )
	ADD_STRINGVALUE( 102, "LightArmorMod" )
	ADD_STRINGVALUE( 103, "PickPocketMod" )
	ADD_STRINGVALUE( 104, "LockpickingMod" )
	ADD_STRINGVALUE( 105, "SneakMod" )
	ADD_STRINGVALUE( 106, "AlchemyMod" )
	ADD_STRINGVALUE( 107, "SpeechcraftMod" )
	ADD_STRINGVALUE( 108, "AlterationMod" )
	ADD_STRINGVALUE( 109, "ConjurationMod" )
	ADD_STRINGVALUE( 110, "DestructionMod" )
	ADD_STRINGVALUE( 111, "IllusionMod" )
	ADD_STRINGVALUE( 112, "RestorationMod" )
	ADD_STRINGVALUE( 113, "EnchantingMod" )
	ADD_STRINGVALUE( 114, "OneHandedSkillAdvance" )
	ADD_STRINGVALUE( 115, "TwoHandedSkillAdvance" )
	ADD_STRINGVALUE( 116, "MarksmanSkillAdvance" )
	ADD_STRINGVALUE( 117, "BlockSkillAdvance" )
	ADD_STRINGVALUE( 118, "SmithingSkillAdvance" )
	ADD_STRINGVALUE( 119, "HeavyArmorSkillAdvance" )
	ADD_STRINGVALUE( 120, "LightArmorSkillAdvance" )
	ADD_STRINGVALUE( 121, "PickPocketSkillAdvance" )
	ADD_STRINGVALUE( 122, "LockpickingSkillAdvance" )
	ADD_STRINGVALUE( 123, "SneakSkillAdvance" )
	ADD_STRINGVALUE( 124, "AlchemySkillAdvance" )
	ADD_STRINGVALUE( 125, "SpeechcraftSkillAdvance" )
	ADD_STRINGVALUE( 126, "AlterationSkillAdvance" )
	ADD_STRINGVALUE( 127, "ConjurationSkillAdvance" )
	ADD_STRINGVALUE( 128, "DestructionSkillAdvance" )
	ADD_STRINGVALUE( 129, "IllusionSkillAdvance" )
	ADD_STRINGVALUE( 130, "RestorationSkillAdvance" )
	ADD_STRINGVALUE( 131, "EnchantingSkillAdvance" )
	ADD_STRINGVALUE( 132, "LeftWeaponSpeedMult" )
	ADD_STRINGVALUE( 133, "DragonSouls" )
	ADD_STRINGVALUE( 134, "CombatHealthRegenMult" )
	ADD_STRINGVALUE( 135, "OneHandedPowerMod" )
	ADD_STRINGVALUE( 136, "TwoHandedPowerMod" )
	ADD_STRINGVALUE( 137, "MarksmanPowerMod" )
	ADD_STRINGVALUE( 138, "BlockPowerMod" )
	ADD_STRINGVALUE( 139, "SmithingPowerMod" )
	ADD_STRINGVALUE( 140, "HeavyArmorPowerMod" )
	ADD_STRINGVALUE( 141, "LightArmorPowerMod" )
	ADD_STRINGVALUE( 142, "PickPocketPowerMod" )
	ADD_STRINGVALUE( 143, "LockpickingPowerMod" )
	ADD_STRINGVALUE( 144, "SneakPowerMod" )
	ADD_STRINGVALUE( 145, "AlchemyPowerMod" )
	ADD_STRINGVALUE( 146, "SpeechcraftPowerMod" )
	ADD_STRINGVALUE( 147, "AlterationPowerMod" )
	ADD_STRINGVALUE( 148, "ConjurationPowerMod" )
	ADD_STRINGVALUE( 149, "DestructionPowerMod" )
	ADD_STRINGVALUE( 150, "IllusionPowerMod" )
	ADD_STRINGVALUE( 151, "RestorationPowerMod" )
	ADD_STRINGVALUE( 152, "EnchantingPowerMod" )
	ADD_STRINGVALUE( 153, "153" )
	ADD_STRINGVALUE( 154, "AttackDamageMult" )
	ADD_STRINGVALUE( 155, "HealRateMult" )
	ADD_STRINGVALUE( 156, "MagickaRateMult" )
	ADD_STRINGVALUE( 157, "StaminaRateMult" )
	ADD_STRINGVALUE( 158, "158" )
	ADD_STRINGVALUE( 159, "159" )
	ADD_STRINGVALUE( 160, "160" )
	ADD_STRINGVALUE( 161, "161" )
	ADD_STRINGVALUE( 162, "162" )
	ADD_STRINGVALUE( 163, "ReflectDamage" )
    ADD_STRINGVALUE( 164,  "164"  )
    ADD_STRINGVALUE( 165,  "165"  )
    ADD_STRINGVALUE( 166,  "166"  )
    ADD_STRINGVALUE( 167,  "167"  )
    ADD_STRINGVALUE( 168,  "168"  )
    ADD_STRINGVALUE( 169,  "169"  )
    ADD_STRINGVALUE( 170,  "170"  )
    ADD_STRINGVALUE( 171,  "171"  )
    ADD_STRINGVALUE( 172,  "172"  )
END_STRINGVALUE()	


BEGIN_STRINGVALUE(s_SrActorSkillValues)
    ADD_STRINGVALUE( -1,  "None"  )
	ADD_STRINGVALUE( 6, "OneHanded" )
	ADD_STRINGVALUE( 7, "TwoHanded" )
	ADD_STRINGVALUE( 8, "Marksman" )
	ADD_STRINGVALUE( 9, "Block" )
	ADD_STRINGVALUE( 10, "Smithing" )
	ADD_STRINGVALUE( 11, "HeavyArmor" )
	ADD_STRINGVALUE( 12, "LightArmor" )
	ADD_STRINGVALUE( 13, "Pickpocket" )
	ADD_STRINGVALUE( 14, "Lockpicking" )
	ADD_STRINGVALUE( 15, "Sneak" )
	ADD_STRINGVALUE( 16, "Alchemy" )
	ADD_STRINGVALUE( 17, "Speechcraft" )
	ADD_STRINGVALUE( 18, "Alteration" )
	ADD_STRINGVALUE( 19, "Conjuration" )
	ADD_STRINGVALUE( 20, "Destruction" )
	ADD_STRINGVALUE( 21, "Illusion" )
	ADD_STRINGVALUE( 22, "Restoration" )
	ADD_STRINGVALUE( 23, "Enchanting" )
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEffectLinkTypes)
    ADD_STRINGVALUE( 0,  "0"  )
    ADD_STRINGVALUE( 1,  "1"  )
    ADD_STRINGVALUE( 2,  "2"  )
    ADD_STRINGVALUE( 3,  "3"  )
    ADD_STRINGVALUE( 4,  "4"  )
    ADD_STRINGVALUE( 5,  "5"  )
    ADD_STRINGVALUE( 6,  "6"  )
    ADD_STRINGVALUE( 7,  "7"  )
    ADD_STRINGVALUE( 8,  "8"  )
    ADD_STRINGVALUE( 9,  "9"  )
    ADD_STRINGVALUE( 10,  "10"  )
    ADD_STRINGVALUE( 11,  "11"  )
    ADD_STRINGVALUE( 12,  "Light"  )
    ADD_STRINGVALUE( 13,  "13"  )
    ADD_STRINGVALUE( 14,  "14"  )
    ADD_STRINGVALUE( 15,  "15"  )
    ADD_STRINGVALUE( 16,  "16"  )
    ADD_STRINGVALUE( 17,  "Weapon"  )
    ADD_STRINGVALUE( 18,  "NPC"  )
    ADD_STRINGVALUE( 19,  "19"  )
    ADD_STRINGVALUE( 20,  "20"  )
    ADD_STRINGVALUE( 21,  "21"  )
    ADD_STRINGVALUE( 22,  "22"  )
    ADD_STRINGVALUE( 23,  "23"  )
    ADD_STRINGVALUE( 24,  "24"  )
    ADD_STRINGVALUE( 25,  "Hazard (25)"  )
    ADD_STRINGVALUE( 26,  "26"  )
    ADD_STRINGVALUE( 27,  "27"  )
    ADD_STRINGVALUE( 28,  "28"  )
    ADD_STRINGVALUE( 29,  "29"  )
    ADD_STRINGVALUE( 30,  "30"  )
    ADD_STRINGVALUE( 31,  "31"  )
    ADD_STRINGVALUE( 32,  "32"  )
    ADD_STRINGVALUE( 33,  "33"  )
    ADD_STRINGVALUE( 34,  "Keyword"  )
    ADD_STRINGVALUE( 35,  "Spell"  )
    ADD_STRINGVALUE( 36,  "Race"  )
    ADD_STRINGVALUE( 37,  "37"  )
    ADD_STRINGVALUE( 38,  "38"  )
    ADD_STRINGVALUE( 39,  "Enchantment"  )
    ADD_STRINGVALUE( 40,  "Hazard (40)"  )
    ADD_STRINGVALUE( 41,  "41"  )
    ADD_STRINGVALUE( 42,  "42"  )
    ADD_STRINGVALUE( 43,  "43"  )
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrWeaponTypes)
    ADD_STRINGVALUE( SR_WEAPON_PROJECTILE	, "Projectile")
    ADD_STRINGVALUE( SR_WEAPON_1HSWORD		, "1HSword")
    ADD_STRINGVALUE( SR_WEAPON_DAGGER		, "Dagger")
    ADD_STRINGVALUE( SR_WEAPON_1HAXE		, "1HAxe")
    ADD_STRINGVALUE( SR_WEAPON_1HBLUNT		, "1HBlunt")
    ADD_STRINGVALUE( SR_WEAPON_2HSWORD		, "2HSword")
    ADD_STRINGVALUE( SR_WEAPON_2HAXEBLUNT	, "2HAxeBlunt")
    ADD_STRINGVALUE( SR_WEAPON_BOW			, "Bow")		
    ADD_STRINGVALUE( SR_WEAPON_STAFF		, "Staff")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSoulGemTypes)
    ADD_STRINGVALUE( SR_SOULGEM_EMPTY	, "Empty")
	ADD_STRINGVALUE( SR_SOULGEM_PETTY	, "Petty")
	ADD_STRINGVALUE( SR_SOULGEM_LESSER	, "Lesser")
	ADD_STRINGVALUE( SR_SOULGEM_COMMON	, "Common")
	ADD_STRINGVALUE( SR_SOULGEM_GREATER	, "Greater")
	ADD_STRINGVALUE( SR_SOULGEM_GRAND	, "Grand")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataUnknown1Types)
    ADD_STRINGVALUE( 1	, "1")
	ADD_STRINGVALUE( 5	, "5")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataUnknown2Types)
    ADD_STRINGVALUE( 0	, "0")
	ADD_STRINGVALUE( 1	, "1")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataUnknown3Types)
    ADD_STRINGVALUE( 0	, "0")
	ADD_STRINGVALUE( 1	, "1")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataTypes)
    ADD_STRINGVALUE( 0, "Quest")
	ADD_STRINGVALUE( 1, "Spell")
	ADD_STRINGVALUE( 2, "Complex")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPrkcTypes)
    ADD_STRINGVALUE( 0, "0")
	ADD_STRINGVALUE( 1, "1")
	ADD_STRINGVALUE( 2, "2")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrEpftTypes)
    ADD_STRINGVALUE( 1, "float")
	ADD_STRINGVALUE( 2, "actorvalue")
	ADD_STRINGVALUE( 4, "lstring(4)?")
	ADD_STRINGVALUE( 5, "spell")
	ADD_STRINGVALUE( 6, "gmst")
	ADD_STRINGVALUE( 7, "lstring(7)?")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataEffectTypes)
    ADD_STRINGVALUE( 0x00, "0x00?")
	ADD_STRINGVALUE( 0x01, "Critical Chance")
	ADD_STRINGVALUE( 0x02, "Critical Damage")
	ADD_STRINGVALUE( 0x08, "Buy Price")
	ADD_STRINGVALUE( 0x0E, "Activate Verb?")
	ADD_STRINGVALUE( 0x12, "Backstab Dmg")
	ADD_STRINGVALUE( 0x14, "Zoom Factor?")
	ADD_STRINGVALUE( 0x15, "Recover Arrows")
	ADD_STRINGVALUE( 0x16, "Skill Increase")
	ADD_STRINGVALUE( 0x1A, "Bash Dmg")
	ADD_STRINGVALUE( 0x1B, "Stamina Cost")
	ADD_STRINGVALUE( 0x1C, "Power Attack Dmg")
	ADD_STRINGVALUE( 0x1D, "Spell Magnitude")
	ADD_STRINGVALUE( 0x1E, "Spell Duration")
	ADD_STRINGVALUE( 0x20, "Encumberance")
	ADD_STRINGVALUE( 0x21, "Stagger Chance")
	ADD_STRINGVALUE( 0x22, "Enemy Stagger Chance")
	ADD_STRINGVALUE( 0x23, "Damage?")
	ADD_STRINGVALUE( 0x24, "Received Dmg")
	ADD_STRINGVALUE( 0x25, "Ignore Armor")
	ADD_STRINGVALUE( 0x26, "Spell Cost")
	ADD_STRINGVALUE( 0x27, "Blocking Chance")
	ADD_STRINGVALUE( 0x28, "Blocking Dmge")
	ADD_STRINGVALUE( 0x29, "Incoming Spell Dmg")
	ADD_STRINGVALUE( 0x2B, "Intimidation?")
	ADD_STRINGVALUE( 0x2F, "Detection(0x2f)?")
	ADD_STRINGVALUE( 0x30, "Detection(0x30)?")
	ADD_STRINGVALUE( 0x31, "Soul Charge")
	ADD_STRINGVALUE( 0x32, "Hit Chance?")
	ADD_STRINGVALUE( 0x33, "Hit Cast Spell?")
	ADD_STRINGVALUE( 0x34, "Bash Cast Spell?")
	ADD_STRINGVALUE( 0x35, "Spell Cast spell?")
	ADD_STRINGVALUE( 0x36, "Set GMST?")
	ADD_STRINGVALUE( 0x37, "Casting Noise?")
	ADD_STRINGVALUE( 0x38, "Pickpocket")
	ADD_STRINGVALUE( 0x39, "Stealth")
	ADD_STRINGVALUE( 0x3A, "Falling Dmg")
	ADD_STRINGVALUE( 0x3B, "Lockpick Difficulty?")
	ADD_STRINGVALUE( 0x3C, "Sell Price")
	ADD_STRINGVALUE( 0x3D, "PP Weapons")
	ADD_STRINGVALUE( 0x3F, "Lockpick Start?")
	ADD_STRINGVALUE( 0x41, "Lockpicking")
	ADD_STRINGVALUE( 0x42, "Alchemy")
	ADD_STRINGVALUE( 0x43, "Is attacking?")
	ADD_STRINGVALUE( 0x44, "Raise Dead Count")
	ADD_STRINGVALUE( 0x45, "Sneak Cast Spell")
	ADD_STRINGVALUE( 0x46, "Set Something?")
	ADD_STRINGVALUE( 0x47, "Spell Absorb")
	ADD_STRINGVALUE( 0x48, "Plant Effect Count?")
	ADD_STRINGVALUE( 0x49, "Potion Purity?")
	ADD_STRINGVALUE( 0x4A, "Door Access?")
	ADD_STRINGVALUE( 0x4B, "Dual Casting?")
	ADD_STRINGVALUE( 0x4C, "Armor Smithing")
	ADD_STRINGVALUE( 0x4D, "Enchantment Effect")
	ADD_STRINGVALUE( 0x4E, "Weapon Recharge?")
	ADD_STRINGVALUE( 0x50, "Enchant Effect Count")
	ADD_STRINGVALUE( 0x51, "Activate Verb?")
	ADD_STRINGVALUE( 0x52, "Allow Shouts?")
	ADD_STRINGVALUE( 0x53, "Poison Hit Count")
	ADD_STRINGVALUE( 0x54, "PP Poison")
	ADD_STRINGVALUE( 0x55, "Armor Rating")
	ADD_STRINGVALUE( 0x56, "Lockpick Noise")
	ADD_STRINGVALUE( 0x57, "Gather Plant Count")
	ADD_STRINGVALUE( 0x58, "Summon Range")
	ADD_STRINGVALUE( 0x59, "Duplicate Potion?")
	ADD_STRINGVALUE( 0x5A, "Make Wax Key")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataApplyTypes)
    ADD_STRINGVALUE( 1,  "=float")
	ADD_STRINGVALUE( 2,  "+float")
	ADD_STRINGVALUE( 3,  "*float")
	ADD_STRINGVALUE( 9,  "lstring+spell")
	ADD_STRINGVALUE( 10, "spell")
	ADD_STRINGVALUE( 11, "gmst")
	ADD_STRINGVALUE( 14, "actorvalue")
	ADD_STRINGVALUE( 15, "lstring")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrPerkDataUnknownTypes)
    ADD_STRINGVALUE( 1, "1")
	ADD_STRINGVALUE( 2, "2")
	ADD_STRINGVALUE( 3, "3")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrSopmContentTypes)
	ADD_STRINGVALUE( SR_SOPMCONTENTTYPE_FNAM,		"Fnam")
	ADD_STRINGVALUE( SR_SOPMCONTENTTYPE_ANAM,		"Anam")
	ADD_STRINGVALUE( SR_SOPMCONTENTTYPE_ONAM,		"Onam")
	ADD_STRINGVALUE( SR_SOPMCONTENTTYPE_ANAMONAM,	"Anam+Onam")
END_STRINGVALUE()


BEGIN_STRINGVALUE(s_SrRaceMoveNames)
	ADD_STRINGVALUE( SR_RACE_MOVENAME_WALK,		"WALK")
	ADD_STRINGVALUE( SR_RACE_MOVENAME_RUN1,		"RUN1")
	ADD_STRINGVALUE( SR_RACE_MOVENAME_SNEK,		"SNEK")
	ADD_STRINGVALUE( SR_RACE_MOVENAME_BLD0,		"BLD0")
	ADD_STRINGVALUE( SR_RACE_MOVENAME_SWIM,		"SWIM")
END_STRINGVALUE()

/*===========================================================================
 *		End of Constant String Tables
 *=========================================================================*/


/*===========================================================================
 *
 * Begin String Table Lookup Functions
 *
 *=========================================================================*/
const SSCHAR* GetSrMagicSchoolString		(const int Value) { return s_SrMagicSchoolsMap.FindValue(Value); }
const SSCHAR* GetSrMagicTypeString			(const int Value) { return s_SrMagicTypesMap.FindValue(Value); }
const SSCHAR* GetSrConditionOperatorString	(const int Value) { return s_SrConditionOperatorsMap.FindValue(Value); }

const SSCHAR* GetSrSpellTypeString		(const int Value) { return s_SrSpellTypesMap.FindValue(Value); }
const SSCHAR* GetSrSpellCastTypeString	(const int Value) { return s_SrSpellCastTypesMap.FindValue(Value); }
const SSCHAR* GetSrSpellCastAnimString	(const int Value) { return s_SrSpellCastAnimsMap.FindValue(Value); }

const SSCHAR* GetSrEnchantTypeAString	(const int Value) { return s_SrEnchantTypeAMap.FindValue(Value); }
const SSCHAR* GetSrEnchantTypeBString	(const int Value) { return s_SrEnchantTypeBMap.FindValue(Value); }
const SSCHAR* GetSrEnchantTypeCString	(const int Value) { return s_SrEnchantTypeCMap.FindValue(Value); }
const SSCHAR* GetSrEnchantTypeDString	(const int Value) { return s_SrEnchantTypeDMap.FindValue(Value); }

const SSCHAR* GetSrBodyPartString		(const int Value) { return s_SrBodyPartsMap.FindValue(Value); }
const SSCHAR* GetSrArmorTypeString		(const int Value) { return s_SrArmorTypesMap.FindValue(Value); }

const SSCHAR* GetSrPotionTypeString		(const int Value) { return s_SrPotionTypesMap.FindValue(Value); }
const SSCHAR* GetSrSkillTypeString		(const int Value) { return s_SrSkillTypesMap.FindValue(Value); }
const SSCHAR* GetSrContainerTypeString	(const int Value) { return s_SrContainerTypesMap.FindValue(Value); }
const SSCHAR* GetSrLightTypeString   	(const int Value) { return s_SrLightTypesMap.FindValue(Value); }
const SSCHAR* GetSrEffectCastTypeString (const int Value) { return s_SrEffectCastTypesMap.FindValue(Value); }
const SSCHAR* GetSrActorValueString     (const int Value) { return s_SrActorValuesMap.FindValue(Value); }
const SSCHAR* GetSrEffectLinkTypeString (const int Value) { return s_SrEffectLinkTypesMap.FindValue(Value); }
const SSCHAR* GetSrWeaponTypeString     (const int Value) { return s_SrWeaponTypesMap.FindValue(Value); }
const SSCHAR* GetSrSoulGemTypeString    (const int Value) { return s_SrSoulGemTypesMap.FindValue(Value); }

const SSCHAR* GetSrPerkDataUnknown1TypeString (const int Value) { return s_SrPerkDataUnknown1TypesMap.FindValue(Value); }
const SSCHAR* GetSrPerkDataUnknown2TypeString (const int Value) { return s_SrPerkDataUnknown2TypesMap.FindValue(Value); }
const SSCHAR* GetSrPerkDataUnknown3TypeString (const int Value) { return s_SrPerkDataUnknown3TypesMap.FindValue(Value); }

const SSCHAR* GetSrPerkDataTypeString (const int Value) { return s_SrPerkDataTypesMap.FindValue(Value); }
const SSCHAR* GetSrPrkcTypeString (const int Value) { return s_SrPrkcTypesMap.FindValue(Value); }
const SSCHAR* GetSrEpftTypeString (const int Value) { return s_SrEpftTypesMap.FindValue(Value); }
const SSCHAR* GetSrPerkDataEffectTypeString (const int Value) { return s_SrPerkDataEffectTypesMap.FindValue(Value); }
const SSCHAR* GetSrPerkDataApplyTypeString (const int Value) { return s_SrPerkDataApplyTypesMap.FindValue(Value); }
const SSCHAR* GetSrPerkDataUnknownTypeString (const int Value) { return s_SrPerkDataUnknownTypesMap.FindValue(Value); }

const SSCHAR* GetSopmContentTypeString (const int Value) { return s_SrSopmContentTypesMap.FindValue(Value); }

const SSCHAR* GetSrLightTypeFlagString 	(const dword LightFlags) 
{
	int Value = LightFlags & SR_LIGHTTYPE_MASK;
	return s_SrLightTypesMap.FindValue(Value); 
}


CSString GetSrBodyPartFlagString	(const dword Value) 
{ 
	CSString Buffer;

	for (dword i = 0; s_SrBodyParts[i].pString != NULL; ++i)
	{
		if (s_SrBodyParts[i].Value & Value)
		{
			Buffer += s_SrBodyParts[i].pString;
			Buffer += " ";
		}
	}

	return Buffer;
}


bool GetSrMagicSchoolValue			(int& Value, const SSCHAR* pString) { return s_SrMagicSchoolsMap.FindString(Value, pString); }
bool GetSrMagicTypeValue			(int& Value, const SSCHAR* pString) { return s_SrMagicTypesMap.FindString(Value, pString); }
bool GetSrConditionOperatorValue	(int& Value, const SSCHAR* pString) { return s_SrConditionOperatorsMap.FindString(Value, pString); }

bool GetSrSpellTypeValue		(int& Value, const SSCHAR* pString) { return s_SrSpellTypesMap.FindString(Value, pString); }
bool GetSrSpellCastTypeValue	(int& Value, const SSCHAR* pString) { return s_SrSpellCastTypesMap.FindString(Value, pString); }
bool GetSrSpellCastAnimValue	(int& Value, const SSCHAR* pString) { return s_SrSpellCastAnimsMap.FindString(Value, pString); }

bool GetSrEnchantTypeAValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeAMap.FindString(Value, pString); }
bool GetSrEnchantTypeBValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeBMap.FindString(Value, pString); }
bool GetSrEnchantTypeCValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeCMap.FindString(Value, pString); }
bool GetSrEnchantTypeDValue	(int& Value, const SSCHAR* pString) { return s_SrEnchantTypeDMap.FindString(Value, pString); }

bool GetSrBodyPartValue	 (int& Value, const SSCHAR* pString) { return s_SrBodyPartsMap.FindString(Value, pString); }
bool GetSrArmorTypeValue (int& Value, const SSCHAR* pString) { return s_SrArmorTypesMap.FindString(Value, pString); }

bool GetSrPotionTypeValue     (int& Value, const SSCHAR* pString) { return s_SrPotionTypesMap.FindString(Value, pString); }
bool GetSrSkillTypeValue      (int& Value, const SSCHAR* pString) { return s_SrSkillTypesMap.FindString(Value, pString); }
bool GetSrContainerTypeValue  (int& Value, const SSCHAR* pString) { return s_SrContainerTypesMap.FindString(Value, pString); }
bool GetSrLightTypeValue      (int& Value, const SSCHAR* pString) { return s_SrLightTypesMap.FindString(Value, pString); }
bool GetSrEffectCastTypeValue (int& Value, const SSCHAR* pString) { return s_SrEffectCastTypesMap.FindString(Value, pString); }
bool GetSrActorValueValue     (int& Value, const SSCHAR* pString) { return s_SrActorValuesMap.FindString(Value, pString); }
bool GetSrEffectLinkTypeValue (int& Value, const SSCHAR* pString) { return s_SrEffectLinkTypesMap.FindString(Value, pString); }
bool GetSrWeaponTypeValue     (int& Value, const SSCHAR* pString) { return s_SrWeaponTypesMap.FindString(Value, pString); }
bool GetSrSoulGemTypeValue    (int& Value, const SSCHAR* pString) { return s_SrSoulGemTypesMap.FindString(Value, pString); }

bool GetSrPerkDataUnknown1TypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataUnknown1TypesMap.FindString(Value, pString); }
bool GetSrPerkDataUnknown2TypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataUnknown2TypesMap.FindString(Value, pString); }
bool GetSrPerkDataUnknown3TypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataUnknown3TypesMap.FindString(Value, pString); }

bool GetSrPerkDataTypeTypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataTypesMap.FindString(Value, pString); }
bool GetSrPrkcTypeValue (int& Value, const SSCHAR* pString) { return s_SrPrkcTypesMap.FindString(Value, pString); }
bool GetSrEpftTypeValue (int& Value, const SSCHAR* pString) { return s_SrEpftTypesMap.FindString(Value, pString); }
bool GetSrPerkDataEffectTypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataEffectTypesMap.FindString(Value, pString); }
bool GetSrPerkDataApplyTypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataApplyTypesMap.FindString(Value, pString); }
bool GetSrPerkDataUnknownTypeValue (int& Value, const SSCHAR* pString) { return s_SrPerkDataUnknownTypesMap.FindString(Value, pString); }

bool GetSrSopmContentTypeValue (int& Value, const SSCHAR* pString) { return s_SrSopmContentTypesMap.FindString(Value, pString); }

bool GetSrLightTypeFlagValue  (dword& LightFlags, const SSCHAR* pString) 
{
	int Type = LightFlags & SR_LIGHTTYPE_MASK;

	if (s_SrLightTypesMap.FindString(Type, pString)) 
	{
		LightFlags = (LightFlags & ~SR_LIGHTTYPE_MASK) | Type;
		return true;
	}

	return false;
}


bool GetSrBodyPartFlagValue	(dword& Value, const SSCHAR* pString) 
{ 
	CSString	  Source(pString);
	CSStringArray SplitStrings;
	int 		  Flag;

	Value = 0;
	SplitString(SplitStrings, Source, ' ');

	for (dword i = 0; i < SplitStrings.GetSize(); ++i)
	{
		if (GetSrBodyPartValue(Flag, *SplitStrings[i])) Value |= Flag;
	}

	return true;
}

/*===========================================================================
 *		End of String Table Lookup Functions
 *=========================================================================*/


/*===========================================================================
 *
 * Function - bool SrFixupFormid (OutputFormID, OrigFormID, FixupArray);
 *
 *=========================================================================*/
bool SrFixupFormid (srformid_t& OutputFormID, const srformid_t OrigFormID, CSrFormidFixupArray& FixupArray) 
{
  dword OldModIndex;
  dword NewModIndex;

	/* Special case for the NULL formid */
  if (OrigFormID == SR_FORMID_NULL) 
  {
    OutputFormID = SR_FORMID_NULL;
    return (true);
  }

  OldModIndex = SR_GETMODINDEX(OrigFormID);
  
  if (!FixupArray.IsValidIndex(OldModIndex)) 
  {
    AddSrGeneralError("Warning: Modindex of form 0x%08X is not valid (must be 0-%d)!", OrigFormID, FixupArray.GetSize()-1);
    //return (false); //Turn into just a warning?
  }
  
  NewModIndex  = FixupArray[OldModIndex];
  OutputFormID = SR_MAKEFORMID(OrigFormID, NewModIndex);
  return (true);
}
/*===========================================================================
 *		End of Function SrFixupFormid()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindData (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindData (const byte* pData, const dword Size, srfinddata_t& FindData) 
{
  if ((FindData.Flags & SR_FIND_CASESENSITIVE) != 0) return SrFindDataCase(pData, Size, FindData);
  return SrFindDataNoCase(pData, Size, FindData); 
}
/*===========================================================================
 *		End of Function SrFindData()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindTextData (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindTextData (const byte* pData, const dword Size, srfinddata_t& FindData)
{
  if ((FindData.Flags & SR_FIND_CASESENSITIVE) != 0) return SrFindTextDataCase(pData, Size, FindData);
  return SrFindTextDataNoCase(pData, Size, FindData); 
}
/*===========================================================================
 *		End of Function SrFindTextData()
 *=========================================================================*/
 

/*===========================================================================
 *
 * Function - dword SrFindDataNoCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindDataNoCase (const byte* pData, const dword Size, srfinddata_t& FindData) {
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);
  
  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size) {
    if (pParse2[FindIndex] == pParse1[0]) {
      ++FindIndex;

      if (FindIndex == FindData.DataSize) {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
	++FindCount;
	if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
	FindIndex = 0;
      }
    }
    else {
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindDataNoCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindDataCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindDataCase (const byte* pData, const dword Size, srfinddata_t& FindData) 
{
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);
 
  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size) 
  {

    if (pParse2[FindIndex] == pParse1[0]) 
	{
      ++FindIndex;

      if (FindIndex == FindData.DataSize) 
	  {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
		++FindCount;
		if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
		FindIndex = 0;
      }
    }
    else
	{
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindDataCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindTextDataNoCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindTextDataNoCase (const byte* pData, const dword Size, srfinddata_t& FindData)
{
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);

  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size)
  {

  		/* Stop searching on the first non-text character */
    if (*pParse1 < 0x05 || *pParse1 > 0x7f) break;

    if (tolower(pParse2[FindIndex]) == tolower(pParse1[0]))
	{
      ++FindIndex;

      if (FindIndex == FindData.DataSize) 
	  {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
		++FindCount;
		if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
		FindIndex = 0;
      }
    }
    else 
	{
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindTextDataNoCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - dword SrFindTextDataCase (pData, Size, FindData);
 *
 *=========================================================================*/
dword SrFindTextDataCase (const byte* pData, const dword Size, srfinddata_t& FindData)
{
  dword FindCount = 0;
  dword Index     = 0;
  dword FindIndex = 0;
  const byte* pParse1;
  const byte* pParse2;

	/* Ignore if given data size is too small */
  if (Size < FindData.DataSize) return (0);
  if (pData == NULL) return (0);

  pParse1 = pData;
  pParse2 = FindData.pData;

  while (Index < Size)
  {

    		/* Stop searching on the first non-text character */
    if (*pParse1 < 0x05 || *pParse1 > 0x7f) break;

    if (tolower(pParse2[FindIndex]) == tolower(pParse1[0]))
	{
      ++FindIndex;

      if (FindIndex == FindData.DataSize)
	  {
        if ((FindData.Flags & SR_FIND_OUTPUTLOG) != 0) SystemLog.Printf("\t\tFound at index %u", Index);
		++FindCount;
		if ((FindData.Flags & SR_FIND_FINDALL) == 0) return (FindCount);
		FindIndex = 0;
      }
    }
    else
	{
      pParse1  -= FindIndex;
      Index    -= FindIndex;
      FindIndex = 0;
    }

    ++pParse1;
    ++Index;
  }

  return (FindCount);
}
/*===========================================================================
 *		End of Function SrFindTextDataCase()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - bool SrContainsRecordType (Name, pArray);
 *
 *=========================================================================*/
bool SrContainsRecordType (const srrectype_t Name, const srrectype_t* pArray)
{
  if (pArray == NULL) return (false);

  while (*pArray != SR_NAME_NULL)
  {
    if (*pArray == Name) return (true);
    ++pArray;
  }

  return (false);
}
/*===========================================================================
 *		End of Function SrContainsRecordType()
 *=========================================================================*/


/*===========================================================================
 *
 * Function - bool SrPrepareEditorID (EditorID);
 *
 * Prepares the given editorID for use, removing whitespace and any invalid
 * characters. Returns false if the final result is not a valid editor ID.
 *
 *========================================================================*/
int sriseditorchar(int Char)
{
	return (isalnum(Char) || Char == '_');
}


bool SrPrepareEditorID (CSString& EditorID)
{

	/* Remove all whitespace */
  EditorID.Trim();

	/* Ensure the ID is only alpha-numeric */
  EditorID.RemoveCharsToMatch(sriseditorchar);

	/* Empty string is not a valid ID */
  if (EditorID.IsEmpty()) return (false);

  return (true);
}
/*===========================================================================
 *		End of Function SrPrepareEditorID()
 *=========================================================================*/


bool SrIsRecipeComponent (const srrectype_t Type)
{
	if (Type == SR_NAME_ALCH) return true;
	if (Type == SR_NAME_ARMO) return true;
	if (Type == SR_NAME_BOOK) return true;
	if (Type == SR_NAME_INGR) return true;
	if (Type == SR_NAME_MISC) return true;
	if (Type == SR_NAME_SCRL) return true;
	if (Type == SR_NAME_WEAP) return true;

	return false;
}


bool SrIsRecipeResult (const srrectype_t Type)
{
	if (Type == SR_NAME_ALCH) return true;
	if (Type == SR_NAME_ARMO) return true;
	if (Type == SR_NAME_BOOK) return true;	
	if (Type == SR_NAME_INGR) return true;
	if (Type == SR_NAME_MISC) return true;
	if (Type == SR_NAME_SCRL) return true;
	if (Type == SR_NAME_WEAP) return true;

	return false;
}


bool SrIsValidLvliRecord (const srrectype_t Type)
{
	if (Type == SR_NAME_ALCH) return true;
	if (Type == SR_NAME_AMMO) return true;
	if (Type == SR_NAME_ARMO) return true;
	if (Type == SR_NAME_BOOK) return true;	
	if (Type == SR_NAME_INGR) return true;
	if (Type == SR_NAME_LVLI) return true;
	if (Type == SR_NAME_KEYM) return true;
	if (Type == SR_NAME_MISC) return true;
	if (Type == SR_NAME_SCRL) return true;
	if (Type == SR_NAME_WEAP) return true;

	return false;
}


bool SrIsValidLvlnRecord (const srrectype_t Type)
{
	if (Type == SR_NAME_NPC_) return true;
	if (Type == SR_NAME_LVLN) return true;

	return false;
}


bool SrIsValidLvspRecord (const srrectype_t Type)
{
	if (Type == SR_NAME_LVSP) return true;
	if (Type == SR_NAME_SPEL) return true;

	return false;
}


bool SrIsValidContainerRecord (const srrectype_t Type)
{
	if (Type == SR_NAME_ALCH) return true;
	if (Type == SR_NAME_AMMO) return true;
	if (Type == SR_NAME_ARMO) return true;
	if (Type == SR_NAME_BOOK) return true;	
	if (Type == SR_NAME_INGR) return true;
	if (Type == SR_NAME_LVLI) return true;
	if (Type == SR_NAME_KEYM) return true;
	if (Type == SR_NAME_MISC) return true;
	if (Type == SR_NAME_SCRL) return true;
	if (Type == SR_NAME_WEAP) return true;

	return false;
}