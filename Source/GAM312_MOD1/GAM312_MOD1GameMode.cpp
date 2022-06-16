// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GAM312_MOD1GameMode.h"
#include "GAM312_MOD1HUD.h"
#include "GAM312_MOD1Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine.h"
#include "UObject/ConstructorHelpers.h"

AGAM312_MOD1GameMode::AGAM312_MOD1GameMode()
	: Super() //still compilies
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	//DefaultPawnClass = AGAM312_MOD1Character::StaticClass();

	// use our custom HUD class
	HUDClass = AGAM312_MOD1HUD::StaticClass();
}

void AGAM312_MOD1GameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AGAM312_MOD1Character>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AGAM312_MOD1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetWorld()->GetMapName();

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
			GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, FString::Printf(TEXT("Health is Zero")));
		}
	}
}

EGamePlayState AGAM312_MOD1GameMode::GetCurrentState() const
{
	return CurrentState;
}

void AGAM312_MOD1GameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AGAM312_MOD1GameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
		case EGamePlayState::EPlaying:
		{
			// do nothing
		}
		break;
		// Unknown/default state
		case EGamePlayState::EGameOver:
		{
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
		break;
		// Unknown/default state
		default:
		case EGamePlayState::EUnknown:
		{
			// do nothing
		}
		break;
	}
}