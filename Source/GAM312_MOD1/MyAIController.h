// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "MyAIController.generated.h"


/**
 * 
 */
UCLASS()
class GAM312_MOD1_API AMyAIController : public AAIController
{

	GENERATED_BODY() //INTELLISENSE ERROR, COMPILIES FINE
public:
    void BeginPlay() override;

public:
    void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
    FTimerHandle TimerHandle;

private:
    UPROPERTY()
        TArray<AActor*> Waypoints;

    UFUNCTION()
        ATargetPoint* GetRandomWaypoint();

    UFUNCTION()
        void GoToRandomWaypoint();
	
};

