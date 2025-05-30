// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "WarriorTypes/WarriorStructTypes.h"

#include "WarriorAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag InInputTag);
	void OnAbilityInputReleased(const FGameplayTag InInputTag);

	UFUNCTION(BlueprintCallable, Category= " Warrior|Ability", meta=(ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles, int32 ApplyLevel);

	UFUNCTION(BlueprintCallable, Category= " Warrior|Ability")
	void RemoveGrantedHeroWeaponAbilities(class AWarriorHeroWeapon* Weapon);
};
