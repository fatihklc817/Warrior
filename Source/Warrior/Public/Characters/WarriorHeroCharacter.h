// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "WarriorBaseCharacter.h"
#include "WarriorHeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorHeroCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()

public:
	AWarriorHeroCharacter();
	
	//~ Begin IPawnCombatInterface Interface.
	virtual class UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface


	//~ Begin IPawnUIInterface Interface.
	virtual class UPawnUIComponent* GetPawnUIComponent() const override;
	virtual class UHeroUIComponent* GetHeroUIComponent() const override;
	//~ End IPawnUIInterface Interface
	
	
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay() override;

private:
	
#pragma region Components

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category= "Camera" , meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UHeroCombatComponent* HeroCombatComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class UHeroUIComponent* HeroUIComponent;
	
#pragma endregion


#pragma region Inputs

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	class UDataAsset_InputConfig* InputConfigDataAsset;
	
	void Input_Move(const struct FInputActionValue& InputActionValue);
	void Input_Look(const struct FInputActionValue& InputActionValue);
	
	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
	
	
#pragma endregion
	
public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
