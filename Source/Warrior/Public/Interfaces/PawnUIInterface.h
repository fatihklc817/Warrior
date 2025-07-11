// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnUIInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPawnUIInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WARRIOR_API IPawnUIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual class UPawnUIComponent* GetPawnUIComponent() const = 0;

	virtual class UHeroUIComponent* GetHeroUIComponent() const;

	virtual class UEnemyUIComponent* GetEnemyUIComponent() const;
};
