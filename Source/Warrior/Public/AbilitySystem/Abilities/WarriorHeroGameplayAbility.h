// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WarriorAbility")
	class AWarriorHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="WarriorAbility")
	class AWarriorHeroController* GetHeroControllerFromACtorInfo();

	UFUNCTION(BlueprintPure, Category="WarriorAbility")
	class UHeroCombatComponent* GetHeroCombatComponentFromACtorInfo();
	
private:
	TWeakObjectPtr<AWarriorHeroCharacter> CachedWarriorHeroCharacter;
	TWeakObjectPtr<AWarriorHeroController> CachedWarriorHeroController;
	
};
