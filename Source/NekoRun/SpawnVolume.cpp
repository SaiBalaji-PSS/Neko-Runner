// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Math/UnrealMathUtility.h"
#include "Spikes.h"
#include "Saw.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Volume"));
	RootComponent = SpawnVolume;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(Timer, this, &ASpawnVolume::SpawnObstacles,2.0f, true);
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//SpawnObstacles();

}

void ASpawnVolume::SpawnObstacles()
{
	bool temp = FMath::RandBool();


	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	FVector SawSpawnLocation = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 1000);

	UWorld* world = GetWorld();

	
	if (temp == true)
	{
		if (world && SpikeClassReference)
		{
			UE_LOG(LogTemp, Warning, TEXT("TEST1"));
			world->SpawnActor<ASpikes>(SpikeClassReference, SpawnLocation, SpawnRotation);
		}
	}
		
	
	

	else if(temp == false)
	{
		if (world && SawClassReference)
		{
			UE_LOG(LogTemp, Warning, TEXT("TEST1"));
			UE_LOG(LogTemp, Warning, TEXT("TEST2"));
			world->SpawnActor<ASaw>(SawClassReference, SawSpawnLocation, SpawnRotation);
		}
	}
	

}

