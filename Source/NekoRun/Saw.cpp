// Fill out your copyright notice in the Description page of Project Settings.


#include "Saw.h"
#include "Neko.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASaw::ASaw()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	saw = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Saw Sprite"));
	RootComponent = saw;

	

}

// Called when the game starts or when spawned
void ASaw::BeginPlay()
{
	Super::BeginPlay();

	this->OnActorBeginOverlap.AddDynamic(this, &ASaw::OnOverlapBeginPlayer);

	
}

// Called every frame
void ASaw::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->AddActorWorldRotation(FRotator(DeltaTime * 400.0f,0.0f,0.0f),false);

	this->AddActorWorldOffset(FVector(DeltaTime * 1400.0f * -1, 0.0f, 0.0f), false);

}

void ASaw::OnOverlapBeginPlayer(AActor* OwnerSaw, AActor* otherActor)
{
	

	if (otherActor && otherActor != this)
	{
		ANeko* Player = Cast<ANeko>(otherActor);
			if(Player)
			{
				Player->IsPlayerDead = true;
				if (Player->IsPlayerDead == true)
				{
					UGameplayStatics::SetGamePaused(this, true);
				}
				
			}
	}

}

