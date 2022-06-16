// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "GAM312_MOD1HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MyTriggerBox.h"


AMyTriggerBox::AMyTriggerBox()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::EndEvent);

    static ConstructorHelpers::FClassFinder<UUserWidget> GameOverScreen(TEXT("/Game/FirstPerson/UI/GameOver_UI"));
	HUDWidgetClass = GameOverScreen.Class;
}

void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyTriggerBox::EndEvent(class AActor* overlappedActor, class AActor* otherActor)
{
    if(otherActor && otherActor != this)
    {
        if(HUDWidgetClass != nullptr)
	    {
		    CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		    if(CurrentWidget)
		    {
			    CurrentWidget->AddToViewport();
                UGameplayStatics::SetGamePaused(GetWorld(), true);
	        }
	    }
    }

}