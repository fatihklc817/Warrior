// Mehmet Fatih KILIÇ


#include "AbilitySystem/Abilities/WarriorEnemyGameplayAbility.h"

#include "Characters/WarriorEnemyCharacter.h"

class AWarriorEnemyCharacter* UWarriorEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedWarriorEnemyCharacter.IsValid())
	{
		 CachedWarriorEnemyCharacter = Cast<AWarriorEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedWarriorEnemyCharacter.IsValid()? CachedWarriorEnemyCharacter.Get() : nullptr;
}

class UEnemyCombatComponent* UWarriorEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
