// Mehmet Fatih KILIÇ


#include "AbilitySystem/WarriorAttributeSet.h"
#include "GameplayEffectExtension.h"

UWarriorAttributeSet::UWarriorAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
	
}

void UWarriorAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(),0.f,GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
	}

	
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(),0.f,GetMaxRage());
		SetCurrentRage(NewCurrentRage);
	}

	
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone,0.f,GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		UE_LOG(LogTemp, Warning, TEXT("Old Health : %f , Damage Done %f, NewCurrentHealth : %f"),OldHealth,DamageDone,NewCurrentHealth);

		//todo:: notify the ui

		//todo:: handle character death
		if (NewCurrentHealth == 0.f)
		{
			
		}
		
	}
	
}
