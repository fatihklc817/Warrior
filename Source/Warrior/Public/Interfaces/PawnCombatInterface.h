// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnCombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WARRIOR_API IPawnCombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual class UPawnCombatComponent* GetPawnCombatComponent() const = 0;
};
