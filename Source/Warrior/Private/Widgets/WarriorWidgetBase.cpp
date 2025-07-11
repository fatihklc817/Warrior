// Mehmet Fatih KILIÇ


#include "Widgets/WarriorWidgetBase.h"

#include "Interfaces/PawnUIInterface.h"

void UWarriorWidgetBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(GetOwningPlayerPawn());
	if (PawnUIInterface)
	{
		UHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent();
		if (HeroUIComponent)
		{
			BP_OnOwningHeroUIComponentInitialized(HeroUIComponent);
		}
	}
}

void UWarriorWidgetBase::InitEnemyCreatedWidget(AActor* OwningEnemyActor)
{
	IPawnUIInterface* PawnUIInterface = Cast<IPawnUIInterface>(OwningEnemyActor);
	if (PawnUIInterface)
	{
		UEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent();

		checkf(EnemyUIComponent,TEXT("Failied to extrac an enemyUIComponent from %s"), *OwningEnemyActor->GetName());

		BP_OnOwningEnemyUIComponentInitialized(EnemyUIComponent);
	}
}
