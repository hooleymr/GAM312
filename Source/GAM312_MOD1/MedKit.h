// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAM312_MOD1Character.h"
#include "MedKit.generated.h"


UCLASS()
class GAM312_MOD1_API AMedKit : public AActor
{
	GENERATED_BODY() //intellisense error
	
public:	
	// Sets default values for this actor's properties
	AMedKit();

	UFUNCTION()
	void OnOverlap(AActor* MyOverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
	AGAM312_MOD1Character* MyCharacter;

};
