// Mehmet Fatih KILIÇ


#include "Items/Weapons/WarriorHeroWeapon.h"

void AWarriorHeroWeapon::AssingGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles)
{
	GrantedAbilitySpecHandles = InSpecHandles;
}

TArray<FGameplayAbilitySpecHandle>& AWarriorHeroWeapon::GetGrantedAbilitySpecHandles()
{
	return GrantedAbilitySpecHandles;
}
