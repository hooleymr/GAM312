// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

void AMyAIController::BeginPlay()
{
    Super::BeginPlay();

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

    GoToRandomWaypoint();
}

ATargetPoint* AMyAIController::GetRandomWaypoint()
{
    auto index = FMath::RandRange(0, Waypoints.Num() - 1);
    return Cast<ATargetPoint>(Waypoints[index]);

}

void AMyAIController::GoToRandomWaypoint()
{
    MoveToActor(GetRandomWaypoint());
}

void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
    Super::OnMoveCompleted(RequestID, Result);

    GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyAIController::GoToRandomWaypoint, 1.0f, false); //still compilies even if ftimer "incomplete"
    
}
