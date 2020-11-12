// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"PaperSpriteComponent.h"
#include"PaperFlipbookComponent.h"
#include "Saw.generated.h"

UCLASS()
class NEKORUN_API ASaw : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaw();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		void OnOverlapBeginPlayer(AActor* OwnerSaw, AActor* otherActor);

private:
	UPROPERTY(EditAnywhere, Category = "Component")
		UPaperSpriteComponent* saw;

};
