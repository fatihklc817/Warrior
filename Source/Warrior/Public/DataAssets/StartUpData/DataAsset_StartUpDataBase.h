// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(class UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<class UWarriorGameplayAbility>> ActivateOnGivenAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<class UWarriorGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartUpData")
	TArray<TSubclassOf<class UGameplayEffect>> StartUpGameplayEffects;

	void GrantAbilities(const TArray< TSubclassOf<UWarriorGameplayAbility>>& InAbilitiesToGive,class UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
};
