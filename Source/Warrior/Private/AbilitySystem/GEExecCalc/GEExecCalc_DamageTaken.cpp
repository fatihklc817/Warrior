// Mehmet Fatih KILIÇ


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"

#include "WarriorGameplayTags.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "Chaos/PBDSuspensionConstraintData.h"

struct FWarriorDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FWarriorDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DefensePower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DamageTaken, Target, false)
	}
	
};

static const FWarriorDamageCapture& GetWarriorDamageCapture()
{
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{

	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();
	
	
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();
	
	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().AttackPowerDef,EvaluateParameters,SourceAttackPower);
	//UE_LOG(LogTemp, Warning, TEXT("source attack power : %f"),SourceAttackPower);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount =0;
	
	for(const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
			//UE_LOG(LogTemp, Warning, TEXT("BaseDamage : %f"),BaseDamage);
		}

		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
			//UE_LOG(LogTemp, Warning, TEXT("UsedLightAttackComboCount : %d"),UsedLightAttackComboCount);
		}

		if (TagMagnitude.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
			//UE_LOG(LogTemp, Warning, TEXT("UsedHeavyAttackComboCount : %d"),UsedHeavyAttackComboCount);
		}
	}
	
	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetWarriorDamageCapture().DefensePowerDef,EvaluateParameters,TargetDefensePower);
	//UE_LOG(LogTemp, Warning, TEXT("TargetDefensePower : %f"),TargetDefensePower);

	if (UsedLightAttackComboCount != 0)
	{
		const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1 ) * 0.05 + 1.f;
		BaseDamage *= DamageIncreasePercentLight;
		//UE_LOG(LogTemp, Warning, TEXT("ScaledBaseDamageLight : %f"),BaseDamage);
	}

	if (UsedHeavyAttackComboCount != 0)
	{
		const float DamageIncreasePercenntHeavy = UsedHeavyAttackComboCount * 0.15f +1.f;
		BaseDamage *= DamageIncreasePercenntHeavy;
		//UE_LOG(LogTemp, Warning, TEXT("ScaledBaseDamageHeavy : %f"),BaseDamage);
	}

	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	//UE_LOG(LogTemp, Warning, TEXT("FinalDamageDone : %f"),FinalDamageDone);
	
	if (FinalDamageDone > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(GetWarriorDamageCapture().DamageTakenProperty,EGameplayModOp::Override,FinalDamageDone));
	}
	
}
