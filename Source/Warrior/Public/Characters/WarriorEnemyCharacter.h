// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorEnemyCharacter();

	
	//~ Begin PawnCombatInterface Interface.
	virtual class UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End PawnCombatInterface Interface


	
	//~ Begin PawnUIInterface Interface.
	virtual class UPawnUIComponent* GetPawnUIComponent() const override;
	virtual class UEnemyUIComponent* GetEnemyUIComponent() const override;
	//~ End PawnUIInterface Interface

	
	
protected:

	virtual void BeginPlay() override;
	
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	class UEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	class UEnemyUIComponent* EnemyUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	class UWidgetComponent* EnemyHealthBarWidgetComponent;
	
private:
	void InitEnemyStartUpData();

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
