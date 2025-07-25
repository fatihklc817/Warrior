// Mehmet Fatih KILIÇ

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WarriorWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorWidgetBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintimplementableEvent, meta = (DisplayName = "On Owning Hero UI Component Initialized"))
	void BP_OnOwningHeroUIComponentInitialized(class UHeroUIComponent* OwningHeroUIComponent);

	UFUNCTION(BlueprintimplementableEvent, meta = (DisplayName = "On Owning Enemy UI Component Initialized"))
	void BP_OnOwningEnemyUIComponentInitialized(class UEnemyUIComponent* OwningEnemyUIComponent);
	
public:
	UFUNCTION(BlueprintCallable)
	void InitEnemyCreatedWidget(AActor* OwningEnemyActor);
	
};
