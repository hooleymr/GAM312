// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/TriggerBox.h"
#include "GAM312_MOD1Character.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GAM312_MOD1_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
	protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AMyTriggerBox();

    // declare overlap begin function
	UFUNCTION()
		void EndEvent(class AActor* overlappedActor, class AActor* otherActor);

private: 

	UPROPERTY(EditAnywhere, Category = "Health")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* CurrentWidget;
	
};