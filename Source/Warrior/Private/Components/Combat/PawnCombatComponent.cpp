// Mehmet Fatih KILIÇ


#include "Components/Combat/PawnCombatComponent.h"

#include "Items/Weapons/WarriorWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, class AWarriorWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponsMap.Contains(InWeaponTagToRegister),TEXT("a tag named %s has already in added as a carried weapon"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponsMap.Emplace(InWeaponTagToRegister,InWeaponToRegister);

	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
	
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{

	if(CharacterCarriedWeaponsMap.Contains(InWeaponTagToGet))
	{
		AWarriorWeaponBase* const* FoundedWeapon = CharacterCarriedWeaponsMap.Find(InWeaponTagToGet);
		return *FoundedWeapon;
	}
	
	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
