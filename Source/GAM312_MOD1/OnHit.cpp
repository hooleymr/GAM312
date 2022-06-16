// Fill out your copyright notice in the Description page of Project Settings.


#include "OnHit.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "GAM312_MOD1Character.h"
#include "KismetStringLibrary.generated.h"

// Sets default values
AOnHit::AOnHit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation
	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyComp->SetSimulatePhysics(true);
    MyComp->SetNotifyRigidBodyCollision(true);
    
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &AOnHit::OnCompHit);
	
	Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireEffect"));
	Fire->AttachTo(MyComp);
	Fire->bAutoActivate = false;
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	Fire->SetTemplate(ParticleAsset.Object);

	// Set as root component
	RootComponent = MyComp;

}

// Called when the game starts or when spawned
void AOnHit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnHit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOnHit::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
		FString OtherActorName = *OtherActor->GetName(); //define name of colliding actor

		if(OtherActorName.Equals("FirstPersonCharacter_C_0")) //check against name of player character
		{
			Fire->ActivateSystem(); //activate fire particle
		}
	}
}

