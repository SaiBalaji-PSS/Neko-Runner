// Fill out your copyright notice in the Description page of Project Settings.


#include "Spikes.h"
#include"PaperSpriteComponent.h"
#include "Neko.h"
#include "Kismet/GameplayStatics.h"
#include"PaperFlipbookComponent.h"

// Sets default values
ASpikes::ASpikes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spike = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SPIKE"));
	RootComponent = spike;
		

}

// Called when the game starts or when spawned
void ASpikes::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ASpikes::OnOverlapBegin);
	
}

// Called every frame
void ASpikes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->AddActorWorldOffset(FVector(DeltaTime * 1400.0f * -1, 0.0f, 0.0f), false);

}

void ASpikes::OnOverlapBegin(AActor* OwnerSpike, AActor* otherActor)
{


	if (otherActor && otherActor != this)
	{
		ANeko* Player = Cast<ANeko>(otherActor);

		if (Player)
		{

			Player->IsPlayerDead = true;

			if (Player->IsPlayerDead == true)
			{
				UGameplayStatics::SetGamePaused(this, true);
			}
			UE_LOG(LogTemp, Warning, TEXT("Overlapped"));
		}


		
	}

}

