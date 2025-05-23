// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorBaseAnimInstance.h"
#include "WarriorHeroLinkedAnimLayer.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorHeroLinkedAnimLayer : public UWarriorBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,meta=(NotBlueprintThreadSafe))
	class UWarriorHeroAnimInstance* GetHeroAnimInstance() const;
	
};
