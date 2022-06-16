// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChange = 2.0f;
	const float SmoothBlendTime = 0.75f;

	TimeToNextCameraChange -= DeltaTime;
	if(TimeToNextCameraChange <= 0.0f)
	{
		TimeToNextCameraChange += TimeBetweenCameraChange;

		//Find actor that handles control for local player
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if(OurPlayerController)
		{
			if((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			{
				//cuts to camera one if on cam2 or other
				OurPlayerController->SetViewTarget(CameraOne);

			}

			else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			{

				//blend to next camera smoothly
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
		}
	}

}

