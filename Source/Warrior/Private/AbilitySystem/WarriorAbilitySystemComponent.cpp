// Mehmet Fatih KILIÇ


#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "Items/Weapons/WarriorHeroWeapon.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag InInputTag)
{
	
}

void UWarriorAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FWarriorHeroAbilitySet>& InDefaultWeaponAbilities, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles, int32 ApplyLevel = 1)
{
	if (InDefaultWeaponAbilities.IsEmpty())
	{
		return;
	}

	for (const FWarriorHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		
		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void UWarriorAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(AWarriorHeroWeapon* Weapon)
{
	TArray<FGameplayAbilitySpecHandle>& GrantedAbilitySpecHandles = Weapon->GetGrantedAbilitySpecHandles();
	
	if (GrantedAbilitySpecHandles.IsEmpty())
	{
		return;
	}

	for (FGameplayAbilitySpecHandle& GrantedAbilitySpecHandle : GrantedAbilitySpecHandles)
	{
		if (GrantedAbilitySpecHandle.IsValid())
		{
			ClearAbility(GrantedAbilitySpecHandle);	
		}	
	}

	GrantedAbilitySpecHandles.Empty();
	
}
